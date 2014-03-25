# $FreeBSD: head/etc/devd/Makefile 261894 2014-02-14 15:31:48Z avg $

FILES=	uath.conf usb.conf zfs.conf

.if ${MACHINE} == "powerpc"
FILES+=	apple.conf
.endif

.if ${MACHINE} == "amd64" || ${MACHINE} == "i386"
FILES+=	asus.conf
.endif

NO_OBJ=
FILESDIR=	/etc/devd
FILESMODE=	644

.include <bsd.prog.mk>
