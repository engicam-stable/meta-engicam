serverip=192.168.2.58
filename=uImage
dtb=uImage.dtb


if env | grep -q ^serverip=; then
 	echo "Download " $filename
	tftp -g -r $filename -l $filename $serverip
	tftp -g -r $dtb -l $dtb  $serverip
	if [ -f $filename ]; then
        mount -t vfat /dev/mmcblk0p1 /mnt/
	mv $filename /mnt/$filename
        mv $dtb /mnt/$dtb
	sync
	umount /mnt
else
	echo "Unable to download " $filename
fi

else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi



