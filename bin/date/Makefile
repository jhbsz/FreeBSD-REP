#	@(#)Makefile	8.1 (Berkeley) 5/31/93
# $FreeBSD: head/bin/date/Makefile 259210 2013-12-11 04:09:17Z jmmv $

.include <src.opts.mk>

PROG=	date
SRCS=	date.c netdate.c vary.c

.if ${MK_TESTS} != "no"
SUBDIR+=    tests
.endif

.include <bsd.prog.mk>
