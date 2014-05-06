#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: head/usr.bin/tr/Makefile 263227 2014-03-16 08:04:06Z jmmv $

.include <src.opts.mk>

PROG=	tr
SRCS=	cmap.c cset.c str.c tr.c

.if ${MK_TESTS} != "no"
SUBDIR+= tests
.endif

.include <bsd.prog.mk>
