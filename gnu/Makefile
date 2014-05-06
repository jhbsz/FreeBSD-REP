#	@(#)Makefile	5.33.1.1 (Berkeley) 5/6/91
# $FreeBSD: head/gnu/Makefile 97874 2002-06-05 17:02:37Z obrien $

.include <src.opts.mk>

SUBDIR= lib ${_tests} usr.bin

.if ${MK_TESTS} != "no"
_tests=	tests
.endif

.include <bsd.subdir.mk>
