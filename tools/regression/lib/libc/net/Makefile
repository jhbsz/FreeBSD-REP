# $FreeBSD: head/tools/regression/lib/libc/net/Makefile 263087 2014-03-12 10:59:51Z jmmv $

TESTS=	test-ether test-eui64_aton test-eui64_ntoa
CFLAGS+= -g -Wall

.PHONY: tests
tests: ${TESTS}
	for p in ${TESTS}; do ${.OBJDIR}/$$p; done

.PHONY: clean
clean:
	-rm -f ${TESTS}
