# $FreeBSD: head/sys/modules/dtrace/dtraceall/Makefile 262818 2014-03-06 01:59:13Z marcel $

SYSDIR?=	${.CURDIR}/../../..

KMOD=		dtraceall
SRCS=		dtraceall.c opt_compat.h opt_nfs.h

CFLAGS+=	-I${SYSDIR}

.if !defined(KERNBUILDDIR)
.if ${MACHINE_ARCH} == "amd64"
opt_compat.h:
	echo "#define COMPAT_FREEBSD32 1" >> ${.TARGET}
.endif
.endif

.include <bsd.kmod.mk>

CFLAGS+=	-include ${SYSDIR}/cddl/compat/opensolaris/sys/debug_compat.h
