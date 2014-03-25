# $FreeBSD: head/lib/clang/liblldbPluginProcessFreeBSD/Makefile 258892 2013-12-03 21:29:45Z emaste $

.include <bsd.own.mk>

LIB=	lldbPluginProcessFreeBSD

# include_directories(.)
CFLAGS+=-I${.CURDIR}/../../../contrib/llvm/tools/lldb/source/Plugins/Process/FreeBSD
CFLAGS+=-I${.CURDIR}/../../../contrib/llvm/tools/lldb/source/Plugins/Process/POSIX

SRCDIR=	tools/lldb/source/Plugins/Process/FreeBSD
SRCS=	FreeBSDThread.cpp \
	ProcessFreeBSD.cpp \
	ProcessMonitor.cpp

TGHDRS=	DiagnosticCommonKinds \
	DeclNodes \
	StmtNodes \
	CommentCommandList

.include "../lldb.lib.mk"
