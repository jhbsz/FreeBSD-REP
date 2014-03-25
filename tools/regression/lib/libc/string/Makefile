# $FreeBSD: head/tools/regression/lib/libc/string/Makefile 263085 2014-03-12 10:45:22Z jmmv $

TESTS=	test-stpncpy test-strerror test-wcscasecmp test-wcsnlen

.PHONY: tests
tests: ${TESTS}
	for p in ${TESTS}; do ${.OBJDIR}/$$p; done

.PHONY: clean
clean:
	-rm -f ${TESTS}
