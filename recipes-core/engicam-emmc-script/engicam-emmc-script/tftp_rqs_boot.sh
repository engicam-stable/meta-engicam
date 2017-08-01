if env | grep -q ^serverip=; then
	filename=u-boot.imx
	echo "Download " $filename
	tftp -g -r $filename -l $filename $serverip
	if [ $? -eq 1 ]; then
      	    echo "TFTP Error check network config"
	    exit
           fi
	if [ -f $filename ]; then
		dd if=$filename of=/dev/mmcblk1 bs=512 seek=2
		rm $filename
		sync
	else
		echo "Unable to download " $filename
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
