# $FreeBSD: head/lib/ncurses/Makefile 261296 2014-01-30 21:08:36Z brooks $

.include <src.opts.mk>

SUBDIR=	ncurses form menu panel

.if ${MK_NCURSESW} != "no"
SUBDIR+=	ncursesw formw menuw panelw
.endif

.include <bsd.subdir.mk>
