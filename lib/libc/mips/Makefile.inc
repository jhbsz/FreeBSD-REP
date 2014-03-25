#	$NetBSD: Makefile.inc,v 1.7 2005/09/17 11:49:39 tsutsui Exp $
# $FreeBSD: head/lib/libc/mips/Makefile.inc 262722 2014-03-04 02:19:39Z marcel $

CFLAGS+=-DSOFTFLOAT

MDSRCS+= machdep_ldisd.c
SYM_MAPS+= ${LIBC_SRCTOP}/mips/Symbol.map
