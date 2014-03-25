# $FreeBSD: head/libexec/casper/sysctl/Makefile 258838 2013-12-02 08:21:28Z pjd $

.PATH:	${.CURDIR} ${.CURDIR}/../../../sbin/casper

PROG=	sysctl

SRCS=	sysctl.c

DPADD=	${LIBCAPSICUM} ${LIBCASPER} ${LIBNV} ${LIBPJDLOG} ${LIBUTIL}
LDADD=	-lcapsicum -lcasper -lnv -lpjdlog -lutil

BINDIR=	/libexec/casper

CFLAGS+=-I${.CURDIR}
CFLAGS+=-I${.CURDIR}/../../../lib/libcapsicum
CFLAGS+=-I${.CURDIR}/../../../lib/libcasper
CFLAGS+=-I${.CURDIR}/../../../lib/libpjdlog
CFLAGS+=-I${.CURDIR}/../../../sbin/casper

NO_MAN=

.include <bsd.prog.mk>
