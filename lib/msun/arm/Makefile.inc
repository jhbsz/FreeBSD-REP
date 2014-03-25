# $FreeBSD: head/lib/msun/arm/Makefile.inc 263230 2014-03-16 09:38:43Z andrew $

LDBL_PREC = 53
SYM_MAPS += ${.CURDIR}/arm/Symbol.map

.if ${TARGET_ARCH} == "armv6"
ARCH_SRCS = fenv-softfp.c fenv-vfp.c
.endif

CFLAGS.fenv-vfp.c=	-mfloat-abi=softfp
CFLAGS+=		${CFLAGS.${.IMPSRC:T}}

