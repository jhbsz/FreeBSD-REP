# $FreeBSD: head/secure/libexec/Makefile 204949 2010-03-10 11:33:15Z des $

.include <src.opts.mk>

SUBDIR=
.if ${MK_OPENSSH} != "no"
SUBDIR+=sftp-server ssh-keysign ssh-pkcs11-helper
.endif

.if ${MK_TESTS} != "no"
SUBDIR+=tests
.endif

.include <bsd.subdir.mk>
