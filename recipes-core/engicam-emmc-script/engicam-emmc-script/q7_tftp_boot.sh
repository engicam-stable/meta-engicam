serverip=192.168.2.96
filename=u-boot.imx
tftp -g -r $filename -l $filename $serverip
if [ -f $filename ]; then
 	echo "Download " $filename
	#dd if=$filename of=u-boot_my.imx bs=512 seek=2 
	dd if=$filename of=/dev/mmcblk1 bs=512 seek=2
	#rm u-boot_my.imx
	rm $filename
	sync
else
	echo "Unable to download " $filename
fi
