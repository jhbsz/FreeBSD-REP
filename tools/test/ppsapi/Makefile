# $FreeBSD: head/tools/test/ppsapi/Makefile 244040 2012-12-08 22:16:36Z eadler $

PROG=	ppsapitest
MAN=

WARNS?=	5

.include <bsd.prog.mk>

CFLAGS+=-Wno-format-security

test:	${PROG}
	./${PROG} /dev/cuau0
