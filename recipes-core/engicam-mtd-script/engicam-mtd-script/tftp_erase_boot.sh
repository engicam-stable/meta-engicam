if env | grep -q ^serverip=; then
	tftp -g -r u-boot.imx -l u-boot.imx $serverip
	echo "Download u-boot.imx"
	if [ -f u-boot.imx ]; then
		dd if=u-boot.imx of=/mnt/u-boot_my.imx bs=512 seek=2 
		flash_erase /dev/mtd0 0 0
		kobs-ng init -v /mnt/u-boot_my.imx
		rm u-boot.imx
		rm /mnt/u-boot_my.imx
	else
		echo "Unable to download u-boot.imx"
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
