# $FreeBSD: head/cddl/sbin/Makefile 168792 2007-04-16 21:20:26Z ru $

.include <src.opts.mk>

SUBDIR=	${_tests} ${_zfs} ${_zpool}

.if ${MK_TESTS} != "no"
_tests=	tests
.endif

.if ${MK_ZFS} != "no"
_zfs=	zfs
_zpool=	zpool
.endif

.include <bsd.subdir.mk>
