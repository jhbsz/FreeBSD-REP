# $FreeBSD: head/usr.bin/ncal/Makefile 263227 2014-03-16 08:04:06Z jmmv $

.include <src.opts.mk>

PROG=	ncal

DPADD=	${LIBCALENDAR} ${LIBTERMCAP}
LDADD=	-lcalendar -ltermcap

LINKS=	${BINDIR}/ncal ${BINDIR}/cal
MLINKS=	ncal.1 cal.1

.if ${MK_TESTS} != "no"
SUBDIR+= tests
.endif

.include <bsd.prog.mk>
