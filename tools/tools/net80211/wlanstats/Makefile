# $FreeBSD: head/tools/tools/net80211/wlanstats/Makefile 262824 2014-03-06 07:43:42Z adrian $

.include <bsd.compiler.mk>

PROG=	wlanstats
BINDIR=	/usr/local/bin
MAN=
USEPRIVATELIB=

SRCS=	wlanstats.c main.c
LDADD=	-lbsdstat
CFLAGS.clang+= -fbracket-depth=512

.include <bsd.prog.mk>
