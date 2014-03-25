# $FreeBSD: head/lib/clang/libllvmpowerpcdesc/Makefile 261991 2014-02-16 19:44:07Z dim $

.include <bsd.own.mk>

LIB=	llvmpowerpcdesc

SRCDIR=	lib/Target/PowerPC/MCTargetDesc
SRCS=	PPCAsmBackend.cpp \
	PPCELFObjectWriter.cpp \
	PPCMCAsmInfo.cpp \
	PPCMCCodeEmitter.cpp \
	PPCMCExpr.cpp \
	PPCMCTargetDesc.cpp \
	PPCMachObjectWriter.cpp \
	PPCPredicates.cpp
CFLAGS+= -I${LLVM_SRCS}/${SRCDIR}/..

TGHDRS=	PPCGenInstrInfo \
	PPCGenMCCodeEmitter \
	PPCGenRegisterInfo \
	PPCGenSubtargetInfo

.include "../clang.lib.mk"
