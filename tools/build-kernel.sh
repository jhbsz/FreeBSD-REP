#!/usr/local/bin/bash

#export NO_MODULES=yes
export MODULES_OVERRIDE="cyclic opensolaris dtrace dtrace/dtmalloc dtrace/dtnfscl dtrace/fbt dtrace/fasttrap dtrace/lockstat dtrace/sdt dtrace/systrace dtrace/profile"
	

export COPTFLAGS="-O0 -g"
export KERNCONF=GENERIC
export WERROR=
export NO_WERROR=

make -j8 buildkernel KERNCONF=GENERIC
