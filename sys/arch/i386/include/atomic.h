/*	$OpenBSD: atomic.h,v 1.4 2007/02/06 17:13:33 art Exp $	*/
/* $NetBSD: atomic.h,v 1.1.2.2 2000/02/21 18:54:07 sommerfeld Exp $ */

/*-
 * Copyright (c) 2000 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by RedBack Networks Inc.
 *
 * Author: Bill Sommerfeld
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
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _ATOMIC_H_
#define _ATOMIC_H_

/*
 * Perform atomic operations on memory. Should be atomic with respect
 * to interrupts and multiple processors.
 *
 * void atomic_setbits_int(volatile u_int *a, u_int mask) { *a |= mask; }
 * void atomic_clearbits_int(volatile u_int *a, u_int mas) { *a &= ~mask; }
 */
#ifndef _LOCORE

#ifdef MULTIPROCESSOR
#define LOCK "lock"
#else
#define LOCK
#endif

static __inline u_int64_t
i386_atomic_testset_uq (volatile u_int64_t *ptr, u_int64_t val) {
    __asm__ volatile ("\n1:\t" LOCK " cmpxchg8b (%1); jnz 1b" : "+A" (val) :
	"r" (ptr), "b" ((u_int32_t)val), "c" ((u_int32_t)(val >> 32)));
    return val;
}

static __inline u_int32_t
i386_atomic_testset_ul (volatile u_int32_t *ptr, unsigned long val) {
    __asm__ volatile ("xchgl %0,(%2)" :"=r" (val):"0" (val),"r" (ptr));
    return val;
}

static __inline int
i386_atomic_testset_i (volatile int *ptr, unsigned long val) {
    __asm__ volatile ("xchgl %0,(%2)" :"=r" (val):"0" (val),"r" (ptr));
    return val;
}

static __inline void 
i386_atomic_setbits_l (volatile u_int32_t *ptr, unsigned long bits) {
    __asm __volatile(LOCK " orl %1,%0" :  "=m" (*ptr) : "ir" (bits));
}

static __inline void 
i386_atomic_clearbits_l (volatile u_int32_t *ptr, unsigned long bits) {
    bits = ~bits;
    __asm __volatile(LOCK " andl %1,%0" :  "=m" (*ptr) : "ir" (bits));
}

#define atomic_setbits_int i386_atomic_setbits_l
#define atomic_clearbits_int i386_atomic_clearbits_l

#undef LOCK

#endif
#endif

