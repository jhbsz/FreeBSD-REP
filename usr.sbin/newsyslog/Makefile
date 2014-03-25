# $FreeBSD: head/usr.sbin/newsyslog/Makefile 263226 2014-03-16 04:09:22Z jmmv $

.include <bsd.own.mk>

PROG=	newsyslog
MAN=	newsyslog.8 newsyslog.conf.5
SRCS=	newsyslog.c ptimes.c

.if ${MK_TESTS} != "no"
SUBDIR+=	tests
.endif

.include <bsd.prog.mk>
