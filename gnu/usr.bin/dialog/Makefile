# $FreeBSD: head/gnu/usr.bin/dialog/Makefile 261296 2014-01-30 21:08:36Z brooks $

DIALOG=	${.CURDIR}/../../../contrib/dialog
PROG=   dialog

DPADD=	${LIBDIALOG} ${LIBM}
LDADD=	-ldialog -lm
CFLAGS+= -I${.CURDIR} -I${DIALOG}
.PATH:	${DIALOG}

WARNS?= 6

.include <src.opts.mk>

.if ${MK_NCURSESW} == "no"
DPADD+=	${LIBNCURSES}
LDADD+=	-lncurses
.else
DPADD+=	${LIBNCURSESW}
LDADD+=	-lncursesw
.endif

.include <bsd.prog.mk>
