serverip=192.168.2.96
filename=rqsq7.sdcard
tftp -g -r $filename -l $filename $serverip
if [ -f $filename ]; then
 	echo "Download " $filename
	dd if=$filename of=/dev/mmcblk1 bs=1M && sync
	sync
	rm $filename
else
	echo "Unable to download " $filename
fi
