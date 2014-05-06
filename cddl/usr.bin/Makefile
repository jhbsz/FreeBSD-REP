# $FreeBSD: head/cddl/usr.bin/Makefile 219089 2011-02-27 19:41:40Z pjd $

.include <src.opts.mk>

SUBDIR= \
	ctfconvert \
	ctfdump \
	ctfmerge \
	sgsmsg \
	${_tests} \
	${_zinject} \
	${_zlook} \
	${_zstreamdump} \
	${_ztest}

.if ${MK_TESTS} != "no"
_tests=	tests
.endif

.if ${MK_ZFS} != "no"
_zinject= zinject
#_zlook= zlook
.if ${MK_LIBTHR} != "no"
_ztest=	ztest
_zstreamdump = zstreamdump
.endif
.endif

.include <bsd.subdir.mk>
