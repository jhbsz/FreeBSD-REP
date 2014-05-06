#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: head/usr.bin/apply/Makefile 263227 2014-03-16 08:04:06Z jmmv $

.include <src.opts.mk>

PROG=	apply
DPADD=	${LIBSBUF}
LDADD=	-lsbuf

.if ${MK_TESTS} != "no"
SUBDIR+= tests
.endif

.include <bsd.prog.mk>
