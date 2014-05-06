# $FreeBSD: head/gnu/lib/Makefile 255321 2013-09-06 20:08:03Z theraven $

.include <src.opts.mk>

SUBDIR= csu libgcc libgcov libdialog libgomp libregex libreadline

.if ${MK_SSP} != "no"
SUBDIR+= libssp
.endif

.if ${MK_TESTS} != "no"
SUBDIR+= tests
.endif

# libsupc++ uses libstdc++ headers, although 'make includes' should
# have taken care of that already.
.if ${MK_GNUCXX} != "no" && ${MK_CXX} != "no"
SUBDIR+= libstdc++ libsupc++
.endif

.include <bsd.subdir.mk>
