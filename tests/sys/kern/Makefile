# $FreeBSD: head/tests/sys/kern/Makefile 263161 2014-03-14 08:56:19Z jmmv $

TESTSDIR=	${TESTSBASE}/sys/kern

ATF_TESTS_C+=	kern_descrip_test
ATF_TESTS_C+=	unix_seqpacket_test
TEST_METADATA.unix_seqpacket_test+=	timeout="15"

LDADD.unix_seqpacket_test+=		-lpthread

WARNS?=	5

.include <bsd.test.mk>
