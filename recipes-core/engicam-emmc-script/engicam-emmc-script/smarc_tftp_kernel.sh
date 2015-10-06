if env | grep -q ^serverip=; then
	filename=uImage
	dtb1=uImage.dtb
	echo "Download " $filename "-" $dtb1
	tftp -g -r $filename -l $filename $serverip
	if [ -f $filename ]; then
		tftp -g -r $dtb1 -l $dtb1  $serverip
		if [ -f $dtb1 ]; then
		    mount -t vfat /dev/mmcblk1p1 /mnt/
		    mv $filename /mnt/$filename
		    mv $dtb1 /mnt/$dtb1
		    sync
		    umount /mnt
		else
		  echo "Unable to download " $dtb1
		fi
	else
		echo "Unable to download " $filename
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
