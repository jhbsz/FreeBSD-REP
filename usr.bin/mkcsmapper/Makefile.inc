# $FreeBSD: head/usr.bin/mkcsmapper/Makefile.inc 259730 2013-12-22 17:51:33Z dim $

.include <bsd.compiler.mk>

SRCS+=	lex.l yacc.y
CFLAGS+= -I${.CURDIR} -I${.CURDIR}/../mkcsmapper \
	 -I${.CURDIR}/../../lib/libc/iconv \
	 -I${.CURDIR}/../../lib/libiconv_modules/mapper_std
CFLAGS.gcc+= --param max-inline-insns-single=64
