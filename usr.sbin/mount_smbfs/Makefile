# $FreeBSD: head/usr.sbin/mount_smbfs/Makefile 257888 2013-11-09 14:48:50Z glebius $

PROG=	mount_smbfs
SRCS=	mount_smbfs.c getmntopts.c
MAN=	mount_smbfs.8

MOUNTDIR=	${.CURDIR}/../../sbin/mount
CONTRIBDIR=	${.CURDIR}/../../contrib/smbfs
CFLAGS+=	-DSMBFS -I${MOUNTDIR} -I${CONTRIBDIR}/include

LDADD=	-lsmb -lkiconv
DPADD=	${LIBSMB} ${LIBKICONV}

.PATH:	${CONTRIBDIR}/mount_smbfs
.PATH:  ${MOUNTDIR}

.include <bsd.prog.mk>
