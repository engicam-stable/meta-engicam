if env | grep -q ^serverip=; then
	filename=u-boot.imx
	echo "Download " $filename
	tftp -g -r $filename -l $filename $serverip
	if [ -f $filename ]; then
		fw_printenv > parametri.txt
		cat parametri.txt | sed -e 's/=/ /' > convertito.txt
		dd if=$filename of=/dev/mmcblk1 bs=512 seek=2
		rm $filename
		fw_setenv -s convertito.txt
		rm parametri.txt
		rm convertito.txt
		sync
	else
		echo "Unable to download " $filename
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi

