if env | grep -q ^serverip=; then
	echo "Download u-boot.imx wait a while..."
	tftp -g -r u-boot.imx -l u-boot.imx $serverip
	if [ -f u-boot.imx ]; then
		fw_printenv > parametri.txt
		cat parametri.txt | sed -e 's/=/ /' > convertito.txt
		dd if=u-boot.imx of=/mnt/u-boot_my.imx bs=512 seek=2 
		flash_erase /dev/mtd0 0 0
		kobs-ng init -v /mnt/u-boot_my.imx
		fw_setenv -s convertito.txt
		rm u-boot.imx
		rm /mnt/u-boot_my.imx
		rm parametri.txt
		rm convertito.txt
	else
		echo "Unable to download u-boot.imx"
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
