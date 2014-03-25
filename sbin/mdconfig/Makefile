# $FreeBSD: head/sbin/mdconfig/Makefile 263220 2014-03-16 02:07:08Z jmmv $

.include <bsd.own.mk>

PROG=		mdconfig
MAN=		mdconfig.8

DPADD=	${LIBUTIL} ${LIBGEOM} ${LIBBSDXML} ${LIBSBUF} 
LDADD=	-lutil -lgeom -lbsdxml -lsbuf

.if ${MK_TESTS} != "no"
SUBDIR+=    tests
.endif

.include <bsd.prog.mk>
