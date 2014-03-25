# $FreeBSD: head/lib/libiconv_modules/mapper_parallel/Makefile 260334 2014-01-05 21:03:49Z dim $

.PATH: ${.CURDIR}/../mapper_serial

SHLIB=	mapper_parallel
SRCS+=	citrus_mapper_serial.c
CFLAGS.gcc+= --param max-inline-insns-single=32

.include <bsd.lib.mk>
