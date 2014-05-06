# $FreeBSD: head/usr.sbin/bsdinstall/distfetch/Makefile 261296 2014-01-30 21:08:36Z brooks $

BINDIR= /usr/libexec/bsdinstall
PROG=	distfetch
DPADD=	${LIBFETCH} ${LIBDIALOG} ${LIBM}
LDADD=	-lfetch -ldialog -lm

WARNS?=	6
MAN=

.include <src.opts.mk>

.if ${MK_NCURSESW} == "no"
DPADD+=	${LIBNCURSES}
LDADD+=	-lncurses
.else
DPADD+=	${LIBNCURSESW}
LDADD+=	-lncursesw
.endif

.include <bsd.prog.mk>
