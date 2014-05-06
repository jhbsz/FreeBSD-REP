# $FreeBSD: head/games/Makefile 105515 2002-10-20 11:18:56Z markm $

.include <src.opts.mk>

SUBDIR= \
	bcd \
	caesar \
	factor \
	fortune \
	grdc \
	morse \
	number \
	pom \
	ppt \
	primes \
	random \
	${_tests}

.if ${MK_TESTS} != "no"
_tests=	tests
.endif

.include <bsd.subdir.mk>
