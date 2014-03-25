#!/usr/local/bin/bash

#export NO_MODULES=yes
export MODULES_OVERRIDE="cyclic opensolaris dtrace dtrace/dtmalloc dtrace/dtnfscl dtrace/fbt dtrace/fasttrap dtrace/lockstat dtrace/sdt dtrace/systrace dtrace/profile"
export DESTDIR=/mnt

export COPTFLAGS="-O0 -g"
export WERROR=
export NO_WERROR=

mdconfig -a -t vnode -f /home/danilo/Mestrado/VMs/freebsd-repi.img
mount /dev/md0p2 /mnt/

make installkernel KERNCONF=GENERIC

umount /mnt
mdconfig -d -u md0
