# $FreeBSD: head/sys/modules/dtrace/Makefile 257037 2013-10-24 02:39:07Z markj $

.include <bsd.own.mk>
.include "Makefile.inc"

SUBDIR=		dtmalloc	\
		dtnfscl		\
		dtnfsclient	\
		dtrace		\
		dtraceall	\
		dtrace_test	\
		lockstat	\
		profile		\
		prototype	\
		sdt		\
		systrace

.if ${MACHINE_CPUARCH} == "amd64" || ${MACHINE_CPUARCH} == "i386"
SUBDIR+=	fasttrap fbt systrace_linux32
.endif
.if ${MACHINE_CPUARCH} == "powerpc"
SUBDIR+=	fbt fasttrap
.endif
.if ${MACHINE_CPUARCH} == "amd64" || ${MACHINE_ARCH} == "powerpc64"
SUBDIR+=	systrace_freebsd32
.endif

.include <bsd.subdir.mk>
