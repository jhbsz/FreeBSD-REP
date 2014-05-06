#
# $FreeBSD: head/sys/modules/cxgbe/Makefile 256725 2013-10-18 09:17:35Z trasz $
#

.include <src.opts.mk>

SUBDIR = if_cxgbe
SUBDIR+= t4_firmware
SUBDIR+= t5_firmware
SUBDIR+= ${_tom}
SUBDIR+= ${_iw_cxgbe}

.if ${MACHINE_CPUARCH} == "amd64"
_tom=		tom
.if ${MK_OFED} != "no" || defined(ALL_MODULES)
_iw_cxgbe=	iw_cxgbe
.endif
.endif

.if ${MACHINE_CPUARCH} == "i386"
_tom=		tom
.endif

.include <bsd.subdir.mk>
