ubiformat /dev/mtd3
ubiattach /dev/ubi_ctrl -m 3
if cat /proc/mtd | grep -q 1f500000; then
ubimkvol /dev/ubi0 -N rootfs -s495000000
else
ubimkvol /dev/ubi0 -N rootfs -s240000000
fi
mkdir /rootfs
mount -t ubifs ubi0:rootfs /rootfs
tar xvf /rootfs.tar.bz2 -C /rootfs 
sync
