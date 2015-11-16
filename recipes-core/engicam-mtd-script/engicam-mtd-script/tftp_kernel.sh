if env | grep -q ^serverip=; then
	echo "Download uImage wait a while..."
	tftp -g -r uImage -l uImage $serverip
	if [ -f uImage ]; then
	 echo "Download uImage.dtb wait a while..."
	 tftp -g -r uImage.dtb -l uImage.dtb $serverip
	 if [ -f uImage.dtb ]; then

		#kernel programming:
		echo "kernel programming..."
		flash_erase /dev/mtd1 0 0
		nandwrite /dev/mtd1 -p uImage
		echo "done"

		#kernel device tree programming:
		echo "kernel device tree programming..."
		flash_erase /dev/mtd2 0 0
		nandwrite /dev/mtd2 -p  uImage.dtb
		echo "done"

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
