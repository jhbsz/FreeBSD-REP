# $FreeBSD: head/lib/libc/arm/Makefile.inc 262722 2014-03-04 02:19:39Z marcel $
#
# Machine dependent definitions for the arm architecture.
#

SOFTFLOAT_BITS=32

# Long double is just double precision.
MDSRCS+=machdep_ldisd.c
SYM_MAPS+=${LIBC_SRCTOP}/arm/Symbol.map

.if ${MK_ARM_EABI} == "no"
# This contains the symbols that were removed when moving to the ARM EABI
SYM_MAPS+=${LIBC_SRCTOP}/arm/Symbol_oabi.map
.else
.include "${LIBC_SRCTOP}/arm/aeabi/Makefile.inc"
.endif

