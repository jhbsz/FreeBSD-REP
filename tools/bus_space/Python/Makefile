# $FreeBSD:  265056 2014-04-28 18:06:11Z marcel $

SHLIB_NAME=	bus_space.so
SRCS=		lang.c

CFLAGS+= -I${.CURDIR}/.. -I/usr/local/include/python2.7
LDFLAGS+= -L/usr/local/lib -lpython2.7

.include <bsd.lib.mk>
