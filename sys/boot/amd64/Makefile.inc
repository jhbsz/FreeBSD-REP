# Common defines for all of /sys/boot/amd64/
#
# $FreeBSD:  264095 2014-04-04 00:16:46Z emaste $

BINDIR?=	/boot

# See conf/kern.mk for the correct set of these
CFLAGS+=	-ffreestanding
CFLAGS+=	-mno-mmx -mno-sse -mno-aes -mno-avx -msoft-float
LDFLAGS+=	-nostdlib

.include "../Makefile.inc"
