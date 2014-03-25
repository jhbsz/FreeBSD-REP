# $FreeBSD: head/tools/tools/iwn/iwnstats/Makefile 262423 2014-02-24 02:38:43Z adrian $

NO_MAN=1

.include <bsd.own.mk>

.PATH:	${.CURDIR}/../../../../sys/dev/iwn/

CFLAGS+=-I${.CURDIR}/../../../../sys/dev/iwn/
CFLAGS+=-I${.CURDIR}/../../../../sys/

PROG=	iwnstats

# Because of a clang preprocessor parser limitation causing this
# to not compile, use gcc for now.
#CC=	gcc

SRCS=	main.c iwn_ioctl.c

# CFLAGS.clang+= -fbracket-depth=512

.include <bsd.prog.mk>
