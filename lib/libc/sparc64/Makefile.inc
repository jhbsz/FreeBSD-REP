# $FreeBSD: head/lib/libc/sparc64/Makefile.inc 262722 2014-03-04 02:19:39Z marcel $
#
# Machine dependent definitions for the ultra sparc architecture.
#

.include "fpu/Makefile.inc"

SRCS+=	__vdso_gettc.c

# Long double is quad precision
GDTOASRCS+=strtorQ.c
MDSRCS+=machdep_ldisQ.c
SYM_MAPS+=${LIBC_SRCTOP}/sparc64/Symbol.map
