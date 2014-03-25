# $FreeBSD: head/lib/libcrypt/tests/Makefile 263161 2014-03-14 08:56:19Z jmmv $

# exercise libcrypt

TESTSDIR= ${TESTSBASE}/lib/libcrypt

ATF_TESTS_C= crypt_tests

CFLAGS+= -I${.CURDIR:H}
LDADD+= -L${.OBJDIR:H} -lcrypt

.include <bsd.test.mk>
