# $FreeBSD: head/cddl/Makefile 168792 2007-04-16 21:20:26Z ru $

.include <src.opts.mk>

SUBDIR=	lib sbin usr.bin usr.sbin

.if ${MK_TESTS} != "no"
SUBDIR+=tests
.endif

.include <bsd.subdir.mk>
