#
# $FreeBSD: head/lib/libpjdlog/Makefile 258791 2013-12-01 09:41:06Z pjd $
#

SHLIBDIR?=	/lib

.include <bsd.own.mk>

LIB=		pjdlog
SRCS=		pjdlog.c

SHLIB_MAJOR=	0

CFLAGS+=-I${.CURDIR}

DPADD=	${LIBUTIL}
LDADD=	-lutil

WARNS?=	6

.include <bsd.lib.mk>
