#!/usr/local/bin/bash

export DESTDIR=/mnt

mdconfig -a -t vnode -f /home/danilo/Mestrado/VMs/freebsd-repi.img
mount /dev/md0p2 /mnt/
make installworld
#make distribution

umount /mnt
mdconfig -d -u md0
