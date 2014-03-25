# $FreeBSD: head/usr.sbin/pkg/Makefile 262400 2014-02-23 21:55:07Z bapt $

PROG=	pkg
SRCS=	pkg.c dns_utils.c config.c
MAN=	pkg.7

CFLAGS+=-I${.CURDIR}/../../contrib/libucl/include
.PATH:	${.CURDIR}/../../contrib/libucl/include
DPADD=	${LIBARCHIVE} ${LIBELF} ${LIBFETCH} ${LIBUCL} ${LIBSBUF} ${LIBSSL} \
	${LIBCRYPTO}
LDADD=	-larchive -lelf -lfetch -lucl -lsbuf -lssl -lcrypto
USEPRIVATELIB=	ucl

.include <bsd.prog.mk>
