# $FreeBSD: head/lib/atf/libatf-c++/tests/detail/Makefile 263161 2014-03-14 08:56:19Z jmmv $

.include <bsd.init.mk>

TESTSDIR=	${TESTSBASE}/lib/atf/libatf-c++/detail

ATF=		${.CURDIR:H:H:H:H:H}/contrib/atf
.PATH:		${ATF}/atf-c++/detail

CFLAGS+=	-I${ATF}

.for _T in	application_test \
		env_test \
		exceptions_test \
		fs_test \
		process_test \
		sanity_test \
		text_test
ATF_TESTS_CXX+=	${_T}
SRCS.${_T}=	${_T}.cpp test_helpers.cpp
.endfor

.for p in version_helper
PROGS_CXX+=	${p}
SRCS.${p}=	${p}.cpp
MAN.${p}=	# defined
BINDIR.${p}=	${TESTSDIR}
.endfor
version_helper.o: atf-version

.include "../../../common.mk"
.include <bsd.test.mk>
