/*	$OpenBSD: delivery_filename.c,v 1.5 2012/05/25 13:51:41 chl Exp $	*/

/*
 * Copyright (c) 2011 Gilles Chehade <gilles@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>
#include <sys/queue.h>
#include <sys/tree.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/stat.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <event.h>
#include <fcntl.h>
#include <imsg.h>
#include <paths.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "smtpd.h"
#include "log.h"

extern char	**environ;

/* filename backend */
static void delivery_filename_open(struct deliver *);

struct delivery_backend delivery_backend_filename = {
	delivery_filename_open
};


static void
delivery_filename_open(struct deliver *deliver)
{
	struct stat 	 sb;
	time_t		 now;
	size_t		 len;
	int		 fd;
	FILE		*fp;
	char		*ln;
	char		*msg;
	int		 n;

#define error(m)	{ msg = m; goto err; }	
#define error2(m)	{ msg = m; goto err2; }

	setproctitle("file delivery");
	fd = open(deliver->to, O_CREAT | O_APPEND | O_WRONLY, 0600);
	if (fd < 0)
		error("open");
	if (fstat(fd, &sb) < 0)
		error("fstat");
	if (S_ISREG(sb.st_mode) && flock(fd, LOCK_EX) < 0)
		error("flock");
	fp = fdopen(fd, "a");
	if (fp == NULL)
		error("fdopen");
	time(&now);
	fprintf(fp, "From %s@%s %s", SMTPD_USER, env->sc_hostname,
	    ctime(&now));
	while ((ln = fgetln(stdin, &len)) != NULL) {
		if (ln[len - 1] == '\n')
			len--;
		if (len >= 5 && memcmp(ln, "From ", 5) == 0)
			putc('>', fp);
		fprintf(fp, "%.*s\n", (int)len, ln);
		if (ferror(fp))
			break;
	}
	if (ferror(stdin))
		error2("read error");
	putc('\n', fp);
	if (fflush(fp) == EOF || ferror(fp))
		error2("write error");
	if (fsync(fd) < 0)
		error2("fsync");
	if (fclose(fp) == EOF)
		error2("fclose");
	_exit(0);

err2:
	n = errno;
	ftruncate(fd, sb.st_size);
	errno = n;

err:
	perror(msg);
	_exit(1);
}
