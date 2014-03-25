#!/bin/sh
# $FreeBSD: head/tools/regression/file/fcntlflags/fcntlflags.t 254888 2013-08-25 21:52:04Z jilles $

cd `dirname $0`

executable=`basename $0 .t`

make $executable 2>&1 > /dev/null

exec ./$executable
