# $FreeBSD: head/usr.bin/clang/clang.prog.mk 261991 2014-02-16 19:44:07Z dim $

LLVM_SRCS= ${.CURDIR}/../../../contrib/llvm

.include "../../lib/clang/clang.build.mk"

.for lib in ${LIBDEPS}
DPADD+=	${.OBJDIR}/../../../lib/clang/lib${lib}/lib${lib}.a
LDADD+=	${.OBJDIR}/../../../lib/clang/lib${lib}/lib${lib}.a
.endfor

DPADD+=	${LIBNCURSES}
LDADD+=	-lncurses

BINDIR?= /usr/bin

.include <bsd.prog.mk>
