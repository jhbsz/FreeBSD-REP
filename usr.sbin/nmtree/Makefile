#	$FreeBSD: head/usr.sbin/nmtree/Makefile 261298 2014-01-30 21:32:25Z brooks $

.include <bsd.own.mk>

.PATH: ${.CURDIR}/../../contrib/mtree

PROG=		mtree
MAN=		mtree.5 mtree.8
SRCS=		compare.c crc.c create.c excludes.c getid.c misc.c mtree.c \
		only.c spec.c specspec.c verify.c
LDADD+=		-lmd -lutil

CFLAGS+=	-I${.CURDIR}/../../contrib/mknod
.PATH:		${.CURDIR}/../../contrib/mknod
SRCS+=		pack_dev.c

CFLAGS+=	-I${.CURDIR}/../../lib/libnetbsd
LIBNETBSDDIR=	${.OBJDIR}/../../lib/libnetbsd
LIBNETBSD=	${LIBNETBSDDIR}/libnetbsd.a
DPADD+=		${LIBNETBSD}
LDADD+=		${LIBNETBSD}

LINKS=		${BINDIR}/mtree ${BINDIR}/nmtree
MLINKS=		mtree.8 nmtree.8

.include <bsd.prog.mk>
