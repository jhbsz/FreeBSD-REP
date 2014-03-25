# $FreeBSD: head/sys/boot/mips/beri/Makefile.inc 262197 2014-02-18 23:18:32Z rwatson $

BINDIR?=	/boot
CFLAGS+=	-ffreestanding
LDFLAGS+=	-nostdlib

.include "../Makefile.inc"
