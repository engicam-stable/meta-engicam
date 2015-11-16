if env | grep -q ^serverip=; then
	echo "Download rootfs.tar.bz2 wait a while..."
	tftp -g -r rootfs.tar.bz2 -l rootfs.tar.bz2 $serverip
	if [ -f rootfs.tar.bz2 ]; then
		ubiformat /dev/mtd3
		ubiattach /dev/ubi_ctrl -m 3
		ubimkvol /dev/ubi0 -N rootfs -s240000000
		mkdir /rootfs
		mount -t ubifs ubi0:rootfs /rootfs
		tar xvf rootfs.tar.bz2 -C /rootfs 
		sync
		rm rootfs.tar.bz2
	else
		echo "Unable to download rootfs.tar.bz2"
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
