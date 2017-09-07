#!/bin/sh

FILETOW=u-boot.imx

print_help() {
   echo "Usage: "
   echo "$0 <FILE NAME>"
   echo "If FILE NAME is not specified try with $FILETOW"
}

if [ -z "$1" ]
then
    echo "No file specified ... using default "
else
    if [ $1 == "-h" ]
    then
      	print_help
      	exit 0
    else
        FILETOW=$1
    fi
fi

if env | grep -q ^serverip=; then
	echo "Download $FILETOW wait a while..."
	tftp -g -r $FILETOW $serverip
	if [ $? -eq 1 ]; then
      echo "TFTP Error check network config"
	    exit
  fi

	if [ -f $FILETOW ]; then
		fw_printenv > parametri.txt
		cat parametri.txt | sed -e 's/=/ /' > convertito.txt
		dd if=$FILETOW of=/mnt/u-boot_my.imx bs=512 seek=2
		flash_erase /dev/mtd0 0 0
		kobs-ng init -v /mnt/u-boot_my.imx
		fw_setenv -s convertito.txt
		rm /mnt/u-boot_my.imx
	else
		echo "Unable to download $FILETOW"
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
