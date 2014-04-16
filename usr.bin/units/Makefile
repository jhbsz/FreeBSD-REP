# $FreeBSD: head/usr.bin/units/Makefile 88064 2001-12-17 16:02:15Z ru $

PROG=	units
FILES=	units.lib
FILESDIR=	${SHAREDIR}/misc

LDADD+=-ledit -ltermcap
DPADD+=${LIBEDIT} ${LIBTERMCAP}

.include <bsd.prog.mk>
