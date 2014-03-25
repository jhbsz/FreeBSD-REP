# $FreeBSD: head/usr.sbin/sa/Makefile 263226 2014-03-16 04:09:22Z jmmv $

.include <bsd.own.mk>

.PATH: ${.CURDIR}/../../usr.bin/lastcomm

PROG=	sa
MAN=	sa.8
SRCS=	main.c db.c pdb.c usrdb.c readrec.c

.if ${MK_TESTS} != "no"
SUBDIR+= tests
.endif

.include <bsd.prog.mk>
