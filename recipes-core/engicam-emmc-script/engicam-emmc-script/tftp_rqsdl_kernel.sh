if env | grep -q ^serverip=; then
	filename=uImage
	dtb=icorem6dl-starterkit-rqs.dtb
	echo "Download " $filename "-" $dtb
	tftp -g -r $filename -l $filename $serverip
	if [ $? -eq 1 ]; then
      	    echo "TFTP Error check network config"
	    exit
           fi
	if [ -f $filename ]; then
		tftp -g -r $dtb -l $dtb  $serverip
		if [ -f $dtb ]; then
			mount -t vfat /dev/mmcblk1p1 /mnt/
			mv $filename /mnt/$filename
			mv $dtb /mnt/$dtb
			sync
			umount /mnt
		else
		  echo "Unable to download " $dtb
		fi
	else
		echo "Unable to download " $filename
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
