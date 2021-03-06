/*	$OpenBSD: uthread_writev.c,v 1.14 2010/01/03 23:05:35 fgsch Exp $	*/
/*
 * Copyright (c) 1995-1998 John Birrell <jb@cimlogic.com.au>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by John Birrell.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: uthread_writev.c,v 1.12 1999/08/28 00:03:55 peter Exp $
 *
 */
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/uio.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef _THREAD_SAFE
#include <pthread.h>
#include "pthread_private.h"

ssize_t
writev(int fd, const struct iovec * iov, int iovcnt)
{
	struct pthread	*curthread = _get_curthread();
	int	blocking;
	int	idx = 0;
	int	type;
	ssize_t num = 0;
	size_t cnt;
	ssize_t n;
	ssize_t	ret;
	struct iovec liov[20];
	struct iovec *p_iov = liov;

	/* This is a cancellation point: */
	_thread_enter_cancellation_point();

	/* Check if the array size exceeds to compiled in size: */
	if (iovcnt > (int) (sizeof(liov) / sizeof(struct iovec))) {
		/* Allocate memory for the local array: */
		if ((p_iov = (struct iovec *)
		    malloc((size_t)iovcnt * sizeof(struct iovec))) == NULL) {
			/* Insufficient memory: */
			errno = ENOMEM;
			_thread_leave_cancellation_point();
			return (-1);
		}
	} else if (iovcnt <= 0) {
		errno = EINVAL;
		_thread_leave_cancellation_point();
		return (-1);
	}

	/* Copy the caller's array so that it can be modified locally: */
	memcpy(p_iov,iov,(size_t)iovcnt * sizeof(struct iovec));

	/* Lock the file descriptor for write: */
	if ((ret = _FD_LOCK(fd, FD_WRITE, NULL)) == 0) {
		/* Get the read/write mode type: */
		type = _thread_fd_table[fd]->status_flags->flags & O_ACCMODE;

		/* Check if the file is not open for write: */
		if (type != O_WRONLY && type != O_RDWR) {
			/* File is not open for write: */
			errno = EBADF;
			_FD_UNLOCK(fd, FD_WRITE);
			if (p_iov != liov)
				free(p_iov);
			_thread_leave_cancellation_point();
			return (-1);
		}

		/* Check if file operations are to block */
		blocking = ((_thread_fd_table[fd]->status_flags->flags & O_NONBLOCK) == 0);

		/*
		 * Loop while no error occurs and until the expected number
		 * of bytes are written if performing a blocking write:
		 */
		while (ret == 0) {
			/* Perform a non-blocking write syscall: */
			n = _thread_sys_writev(fd, &p_iov[idx], iovcnt - idx);

			/* Check if one or more bytes were written: */
			if (n > 0) {
				/*
				 * Keep a count of the number of bytes
				 * written:
				 */
				num += n;

				/*
				 * Enter a loop to check if a short write
				 * occurred and move the index to the
				 * array entry where the short write
				 * ended:
				 */
				cnt = (size_t)n;
				while (cnt > 0 && idx < iovcnt) {
					/*
					 * If the residual count exceeds
					 * the size of this vector, then
					 * it was completely written:
					 */
					if (cnt >= p_iov[idx].iov_len)
						/*
						 * Decrement the residual
						 * count and increment the
						 * index to the next array
						 * entry:
						 */
						cnt -= p_iov[idx++].iov_len;
					else {
						/*
						 * This entry was only
						 * partially written, so
						 * adjust it's length
						 * and base pointer ready
						 * for the next write:
						 */
						p_iov[idx].iov_len -= cnt;
						p_iov[idx].iov_base =
						    (char *)p_iov[idx].iov_base
						    + (ptrdiff_t)cnt;
						cnt = 0;
					}
				}
			} else if (n == 0) {
				/*
				 * Avoid an infinite loop if the last iov_len is
				 * 0.
				 */
				while (idx < iovcnt && p_iov[idx].iov_len == 0)
					idx++;

				if (idx == iovcnt) {
					ret = num;
					break;
				}
			}

			/*
			 * If performing a blocking write, check if the
			 * write would have blocked or if some bytes
			 * were written but there are still more to
			 * write:
			 */
			if (blocking && ((n < 0 && (errno == EWOULDBLOCK ||
			    errno == EAGAIN)) || (n >= 0 && idx < iovcnt))) {
				curthread->data.fd.fd = fd;
				_thread_kern_set_timeout(_FD_SNDTIMEO(fd));

				/* Reset the interrupted operation flag: */
				curthread->interrupted = 0;
				curthread->closing_fd = 0;
				curthread->timeout = 0;

				_thread_kern_sched_state(PS_FDW_WAIT,
				    __FILE__, __LINE__);

				/*
				 * Check if the operation was
				 * interrupted by a signal
				 */
				if (curthread->interrupted ||
				    curthread->closing_fd ||
				    curthread->timeout) {
					if (num > 0) {
						/* Return partial success: */
						ret = num;
					} else {
						/* Return an error: */
						if (curthread->closing_fd)
							errno = EBADF;
						else if (curthread->interrupted)
							errno = EINTR;
						else
							errno = EWOULDBLOCK;
						ret = -1;
					}
				}

			/*
			 * If performing a non-blocking write,
			 * just return whatever the write syscall did:
			 */
			} else if (!blocking) {
				/* A non-blocking call might return zero: */
				ret = n;
				break;

			/*
			 * If there was an error, return partial success
			 * (if any bytes were written) or else the error:
			 */
			} else if (n < 0) {
				if (num > 0)
					ret = num;
				else
					ret = n;

			/* Check if the write has completed: */
			} else if (idx == iovcnt)
				/* Return the number of bytes written: */
				ret = num;
		}
		_FD_UNLOCK(fd, FD_WRITE);
	}

	/* If memory was allocated for the array, free it: */
	if (p_iov != liov)
		free(p_iov);

	/* No longer in a cancellation point: */
	_thread_leave_cancellation_point();

	return (ret);
}
#endif
