# $FreeBSD: head/lib/libc/powerpc/Makefile.inc 262722 2014-03-04 02:19:39Z marcel $

SRCS+=	__vdso_gettc.c

# Long double is 64-bits
MDSRCS+=machdep_ldisd.c
SYM_MAPS+=${LIBC_SRCTOP}/powerpc/Symbol.map
