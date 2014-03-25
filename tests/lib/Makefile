# $FreeBSD: head/tests/lib/Makefile 257097 2013-10-25 05:25:19Z rpaulo $

.include <bsd.own.mk>

TESTSDIR= ${TESTSBASE}/lib

KYUAFILE= yes

CLEANFILES+= Kyuafile
Kyuafile: ${.CURDIR}/../Kyuafile
	cp -f ${.CURDIR}/../Kyuafile .

.include <bsd.test.mk>
