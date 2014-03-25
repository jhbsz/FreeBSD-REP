# $FreeBSD: head/usr.bin/clang/Makefile 261991 2014-02-16 19:44:07Z dim $

.include <bsd.own.mk>

SUBDIR=	clang clang-tblgen tblgen

.if !defined(TOOLS_PREFIX)
.if ${MK_CLANG_EXTRAS} != "no"
SUBDIR+=bugpoint \
	llc \
	lli \
	llvm-ar \
	llvm-as \
	llvm-bcanalyzer \
	llvm-diff \
	llvm-dis \
	llvm-extract \
	llvm-link \
	llvm-mc \
	llvm-nm \
	llvm-objdump \
	llvm-rtdyld \
	macho-dump \
	opt
.endif

.if ${MK_LLDB} != "no"
SUBDIR+=lldb
.endif
.endif # TOOLS_PREFIX

.include <bsd.subdir.mk>
