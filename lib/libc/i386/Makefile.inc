# $FreeBSD: head/lib/libc/i386/Makefile.inc 262722 2014-03-04 02:19:39Z marcel $

# Long double is 80 bits
GDTOASRCS+=strtorx.c
MDSRCS+=machdep_ldisx.c
SYM_MAPS+=${LIBC_SRCTOP}/i386/Symbol.map
