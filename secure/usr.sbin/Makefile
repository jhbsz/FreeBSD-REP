# $FreeBSD: head/secure/usr.sbin/Makefile 156813 2006-03-17 18:54:44Z ru $

.include <src.opts.mk>

SUBDIR= 
.if ${MK_OPENSSH} != "no"
SUBDIR+=sshd
.endif

.if ${MK_TESTS} != "no"
SUBDIR+=tests
.endif

.include <bsd.subdir.mk>
