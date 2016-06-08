if env | grep -q ^serverip=; then
	filename=rootfs.tar.bz2
	echo "Download " $filename
	tftp -g -r $filename -l $filename $serverip
	if [ $? -eq 1 ]; then
      	    echo "TFTP Error check network config"
	    exit
           fi
	if [ -f $filename ]; then
			mount -t ext4 /dev/mmcblk1p2 /mnt/
			tar -xvf rootfs.tar.bz2 -C /mnt
			umount /mnt
			sync
	else
		echo "Unable to download " $filename
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
