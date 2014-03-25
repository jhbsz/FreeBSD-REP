# $FreeBSD: head/tools/tools/mwl/mwlstats/Makefile 262830 2014-03-06 07:48:43Z adrian $

PROG=	mwlstats
BINDIR=	/usr/local/bin
NO_MAN=

SRCS=	main.c mwlstats.c
USEPRIVATELIB=
LDADD=-lbsdstat

.include <bsd.prog.mk>

CFLAGS+= -I.
