# $FreeBSD: head/sys/modules/ip6_mroute_mod/Makefile 258541 2013-11-25 07:38:45Z attilio $

.include <bsd.own.mk>

.PATH: ${.CURDIR}/../../netinet6

KMOD=	ip6_mroute

SRCS=	ip6_mroute.c
SRCS+=	opt_inet6.h opt_mrouting.h

.if !defined(KERNBUILDDIR)
opt_inet6.h:
	echo "#define INET6 1" > ${.TARGET}
opt_mrouting.h:
	echo "#define MROUTING 1" > ${.TARGET}
.endif

.include <bsd.kmod.mk>
