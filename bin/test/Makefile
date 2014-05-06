#        @(#)Makefile	8.1 (Berkeley) 5/31/93
# $FreeBSD: head/bin/test/Makefile 259210 2013-12-11 04:09:17Z jmmv $

.include <src.opts.mk>

PROG=	test
LINKS=	${BINDIR}/test ${BINDIR}/[
MLINKS=	test.1 [.1

.if ${MK_TESTS} != "no"
SUBDIR+=    tests
.endif

.include <bsd.prog.mk>
