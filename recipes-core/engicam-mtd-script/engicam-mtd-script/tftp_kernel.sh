if env | grep -q ^serverip=; then
	tftp -g -r uImage -l uImage $serverip
	if [ -f uImage ]; then
	 echo "Download uImage"
	 tftp -g -r uImage.dtb -l uImage.dtb $serverip
	 if [ -f uImage.dtb ]; then
		echo "Download uImage.dtb"

		#kernel programming:
		flash_erase /dev/mtd1 0 0
		nandwrite /dev/mtd1 -p uImage

		#kernel device tree programming:
		flash_erase /dev/mtd2 0 0
		nandwrite /dev/mtd2 -p  uImage.dtb

		rm uImage
		rm uImage.dtb
	 else
		rm uImage
		echo "Unable to download uImage.dtb"
	 fi
	else
	 echo "Unable to download uImage"
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
