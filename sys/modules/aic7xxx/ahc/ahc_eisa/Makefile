
# $FreeBSD: head/sys/modules/aic7xxx/ahc/ahc_eisa/Makefile 260401 2014-01-07 19:33:17Z scottl $

.PATH:	${.CURDIR}/../../../../dev/aic7xxx
KMOD=		ahc_eisa

SRCS=	ahc_eisa.c
SRCS+=	device_if.h bus_if.h eisa_if.h
SRCS+=	opt_scsi.h opt_cam.h opt_aic7xxx.h

CFLAGS+=	-I${.CURDIR}/../../../../dev/aic7xxx -I..

.include <bsd.kmod.mk>
