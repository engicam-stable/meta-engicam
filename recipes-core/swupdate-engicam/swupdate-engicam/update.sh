#!/bin/sh

function create_emmc
{
echo "create_emmc"

echo "Partitioning emmc"
echo "
o
n
p
1
16384
+64M
n
p
3


n
p
2


d
3
t
1
c
w 
q
" | fdisk /dev/mmcblk2

echo "Format emmc"

mkdosfs /dev/mmcblk2p1

# Format filesystem
mkfs.ext4 -F /dev/mmcblk2p2

sync
}

create_emmc