# $FreeBSD: head/sbin/ipfw/Makefile 261797 2014-02-12 09:59:48Z glebius $

.include <src.opts.mk>

PROG=	ipfw
SRCS=	ipfw2.c dummynet.c ipv6.c main.c nat.c
WARNS?=	2

.if ${MK_PF} != "no"
SRCS+=	altq.c
CFLAGS+=-DPF
.endif

DPADD=	${LIBUTIL}
LDADD=	-lutil
MAN=	ipfw.8

.include <bsd.prog.mk>
