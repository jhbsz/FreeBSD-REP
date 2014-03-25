# $FreeBSD: head/tools/tools/cxgbetool/Makefile 258698 2013-11-27 22:17:00Z np $

PROG=	cxgbetool
SRCS=	cxgbetool.c
NO_MAN=
CFLAGS+= -I${.CURDIR}/../../../sys/dev/cxgbe -I${.CURDIR}/../../../sys -I.
BINDIR?= /usr/sbin

.include <bsd.prog.mk>
