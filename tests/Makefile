# $FreeBSD: head/tests/Makefile 261978 2014-02-16 12:56:05Z jmmv $

.include <bsd.own.mk>

SUBDIR= sys

TESTSDIR= ${TESTSBASE}
KYUAFILE= yes

afterinstall: install-tests-local
install-tests-local: .PHONY
	${INSTALL_SYMLINK} ../local/tests ${DESTDIR}${TESTSDIR}/local

.include <bsd.test.mk>
