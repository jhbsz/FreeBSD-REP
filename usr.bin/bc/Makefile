#	$FreeBSD: head/usr.bin/bc/Makefile 249657 2013-04-19 19:45:00Z ed $
#	$OpenBSD: Makefile,v 1.7 2013/09/19 16:12:00 otto Exp $

PROG=		bc
SRCS=		bc.y scan.l tty.c
CFLAGS+=	-I. -I${.CURDIR}

LDADD+=		-ledit -lcurses
DPADD+=		${LIBEDIT} ${LIBCURSES}

NO_WMISSING_VARIABLE_DECLARATIONS=

FILES+=	bc.library
FILESDIR=${SHAREDIR}/misc

.include <bsd.prog.mk>
