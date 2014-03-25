#!/usr/local/bin/bash

export NO_MODULES=yes

export COPTFLAGS="-O0 -g"
export KERNCONF=GENERIC
export WERROR=
export NO_WERROR=

cd /home/danilo/Mestrado/Sources/freebsd-head
make -j8 -DKERNFAST buildkernel KERNCONF=GENERIC
#make -DNO_CLEAN buildkernel
#make -j2 buildkernel
