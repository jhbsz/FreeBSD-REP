# $FreeBSD: head/secure/usr.bin/Makefile 156813 2006-03-17 18:54:44Z ru $

.include <src.opts.mk>

SUBDIR=
.if ${MK_OPENSSL} != "no"
SUBDIR+=bdes openssl
.if ${MK_OPENSSH} != "no"
SUBDIR+=scp sftp ssh ssh-add ssh-agent ssh-keygen ssh-keyscan
.endif
.endif

.if ${MK_TESTS} != "no"
SUBDIR+=tests
.endif

.include <bsd.subdir.mk>
