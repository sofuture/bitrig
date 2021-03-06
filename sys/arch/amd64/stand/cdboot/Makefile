#	$OpenBSD: Makefile,v 1.11 2007/11/25 18:25:30 deraadt Exp $

.include "${.CURDIR}/../Makefile.inc"

MAN=	cdboot.8

.if ${MACHINE} == "amd64"
S	=${.CURDIR}/../../../..
SADIR=	${.CURDIR}/..

PROG=	cdboot
SRCS=	srt0.S boot.c conf.c
LD?=	ld
SIZE?=	size
LDFLAGS+=-melf_i386 -nostdlib -Bstatic -Ttext $(LINKADDR) -N -x -noinhibit-exec
LDFLAGS+=-L/usr/libdata
INSTALL_STRIP=

.PATH:	${SADIR}/libsa
# i386 stuff (so, it will possibly load in the same 64k)
SRCS+=	machdep.c dev_i386.c exec_i386.c cmd_i386.c
SRCS+=	gidt.S alloca.S biosdev.c bioscons.c gateA20.c \
	memprobe.c diskprobe.c time.c ## biosprobe.c

.PATH:	${S}/stand/boot
SRCS+=	cmd.c vars.c bootarg.c

.PATH:	${S}/lib/libsa
SRCS+=	alloc.c exit.c strcmp.c strlen.c \
	strncmp.c memcmp.c memcpy.c memset.c printf.c snprintf.c \
	strerror.c strncpy.c strtol.c strtoll.c ctime.c strlcpy.c
SRCS+=	close.c closeall.c dev.c disklabel.c dkcksum.c fstat.c lseek.c \
	open.c read.c stat.c cread.c readdir.c cons.c loadfile.c \
	elf32.c elf64.c
SRCS+=	ufs.c cd9660.c

.PATH:	${S}/lib/libkern/arch/i386 ${S}/lib/libkern
SRCS+=	divdi3.c moddi3.c qdivrem.c

.PATH:	${S}/lib/libz
SRCS+=	adler32.c crc32.c inflate.c inftrees.c

#LDADD=	${LIBSA} ${LIBZ}
#DPADD=	${LIBSA} ${LIBZ}

${PROG}: $(OBJS) $(DPADD)
	$(LD) $(LDFLAGS) -o ${PROG} $(OBJS) $(LDADD)
	@$(SIZE) $(PROG)
	@if [ -x ${.OBJDIR}/${PROG} ]; then \
		objcopy -O binary ${PROG} ${.OBJDIR}/.tmp;\
		mv -f ${.OBJDIR}/.tmp ${.OBJDIR}/${PROG}; \
		ls -l ${.OBJDIR}/${PROG}; \
	fi

.else
NOPROG=
.endif

.include <bsd.prog.mk>

CPPFLAGS+=-DBOOTMAGIC=$(BOOTMAGIC) ${DEBUGFLAGS}
CPPFLAGS+=-DSLOW -DSMALL -DNOBYFOUR -DNO_GZIP -DDYNAMIC_CRC_TABLE
CPPFLAGS+=-DLINKADDR=${LINKADDR} -I${S}/stand/boot
CFLAGS+=-m32 ${SACFLAGS} -D__INTERNAL_LIBSA_CREAD
CFLAGS+=-DOSREV=\"${OSREV}\" -DMACHINE=\"${MACHINE}\"
CFLAGS+=-DKERNEL=\"/${OSREV}/${MACHINE}/bsd.rd\"
.if ${COMPILER_VERSION:L} != "gcc4"
#AFLAGS+=-no-integrated-as
# XXX HACK kill this
CFLAGS+=-Wno-error
CC=gcc
AFLAGS+=-m32 # -Wa,-R
.else
# AFLAGS+=-Wa,-a
AFLAGS+=-Wa,--32
.endif
