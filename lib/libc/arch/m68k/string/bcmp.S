/*	$OpenBSD: bcmp.S,v 1.5 2005/08/07 16:40:14 espie Exp $ */
/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * the Systems Programming Group of the University of Utah Computer
 * Science Department.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "DEFS.h"

/* bcmp(s1, s2, n) */

/*
 * This is probably not the best we can do, but it is still 2-10 times
 * faster than the C version in the portable gen directory.
 *
 * Things that might help:
 *	- longword align when possible (only on the 68020)
 *	- use nested DBcc instructions or use one and limit size to 64K
 */
ENTRY(bcmp)
	movl	sp@(4),a0		| string 1
	movl	sp@(8),a1		| string 2
	movl	sp@(12),d0		| length
	beq	bcdone			| if zero, nothing to do
	movl	a0,d1
	btst	#0,d1			| string 1 address odd?
	beq	bceven			| no, skip alignment
	cmpmb	a0@+,a1@+		| yes, compare a byte
	bne	bcnoteq			| not equal, return non-zero
	subql	#1,d0			| adjust count
	beq	bcdone			| count 0, reutrn zero
bceven:
	movl	a1,d1
	btst	#0,d1			| string 2 address odd?
	bne	bcbloop			| yes, no hope for alignment, compare bytes
	movl	d0,d1			| no, both even
	lsrl	#2,d1			| convert count to longword count
	beq	bcbloop			| count 0, skip longword loop
bclloop:
	cmpml	a0@+,a1@+		| compare a longword
	bne	bcnoteq			| not equal, return non-zero
	subql	#1,d1			| adjust count
	bne	bclloop			| still more, keep comparing
	andl	#3,d0			| what remains
	beq	bcdone			| nothing, all done
bcbloop:
	cmpmb	a0@+,a1@+		| compare a byte
	bne	bcnoteq			| not equal, return non-zero
	subql	#1,d0			| adjust count
	bne	bcbloop			| still more, keep going
	rts
bcnoteq:
	moveq	#1,d0
bcdone:
	rts
