#	From: @(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: head/usr.bin/lastcomm/Makefile 263226 2014-03-16 04:09:22Z jmmv $

.include <bsd.own.mk>

PROG=	lastcomm
SRCS=	lastcomm.c readrec.c

.if ${MK_TESTS} != "no"
SUBDIR+= tests
.endif

.include <bsd.prog.mk>
