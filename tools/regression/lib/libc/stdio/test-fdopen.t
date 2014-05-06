#!/bin/sh
# $FreeBSD:  264737 2014-04-21 17:40:23Z jilles $

cd `dirname $0`

executable=`basename $0 .t`

make $executable 2>&1 > /dev/null

exec ./$executable
