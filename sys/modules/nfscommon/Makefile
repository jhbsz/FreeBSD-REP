# $FreeBSD: head/sys/modules/nfscommon/Makefile 258541 2013-11-25 07:38:45Z attilio $

.PATH: ${.CURDIR}/../../fs/nfs 
KMOD=	nfscommon
SRCS=	vnode_if.h \
	nfs_commonacl.c \
	nfs_commonkrpc.c \
	nfs_commonport.c \
	nfs_commonsubs.c \
	opt_inet6.h \
	opt_kgssapi.h \
	opt_nfs.h \
	opt_ufs.h

.include <bsd.kmod.mk>
