# $FreeBSD: head/sbin/mdconfig/tests/Makefile 263222 2014-03-16 02:32:44Z jmmv $

TESTSDIR=	${TESTSBASE}/sbin/mdconfig

TAP_TESTS_SH=			legacy_test
TAP_TESTS_SH_SED_legacy_test=   's,__PERL__,${TAP_PERL_INTERPRETER},g'
TEST_METADATA.legacy_test+=	required_programs="${TAP_PERL_INTERPRETER}"

FILESDIR=	${TESTSDIR}
FILES=		mdconfig.test
FILES+=		run.pl

.include <bsd.test.mk>
