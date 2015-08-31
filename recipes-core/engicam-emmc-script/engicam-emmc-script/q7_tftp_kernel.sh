if env | grep -q ^serverip=; then
	filename=uImage
	dtb1=imx6dl-icore-rqs.dtb
	dtb2=imx6q-icore-rqs.dtb
	echo "Download " $filename "-" $dtb1 "/" $dtb2
	tftp -g -r $filename -l $filename $serverip
	if [ -f $filename ]; then
		tftp -g -r $dtb1 -l $dtb1  $serverip
		if [ -f $dtb1 ]; then
		    tftp -g -r $dtb2 -l $dtb2  $serverip
		    if [ -f $dtb2 ]; then
			mount -t vfat /dev/mmcblk0p1 /mnt/
			mv $filename /mnt/$filename
			mv $dtb1 /mnt/$dtb1
			mv $dtb2 /mnt/$dtb2
			sync
			umount /mnt
		    else
		      echo "Unable to download " $dtb2
		    fi
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
