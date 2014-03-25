# $FreeBSD: head/sys/modules/bwi/Makefile 257882 2013-11-09 08:11:24Z adrian $

.PATH: ${.CURDIR}/../../dev/bwi

KMOD	= if_bwi

SRCS	= if_bwi.c if_bwi_pci.c bwimac.c bwiphy.c bwirf.c
SRCS	+= device_if.h bus_if.h pci_if.h opt_inet.h opt_bwi.h opt_wlan.h

.include <bsd.kmod.mk>
