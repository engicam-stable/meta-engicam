#!/bin/sh

FILETOW=rootfs.tar.bz2

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
		ubiformat /dev/mtd3
		ubiattach /dev/ubi_ctrl -m 3
		if cat /proc/mtd | grep -q 1f500000; then
			ubimkvol /dev/ubi0 -N rootfs -s495000000
		else
			ubimkvol /dev/ubi0 -N rootfs -s240000000
		fi
		mkdir /rootfs
		mount -t ubifs ubi0:rootfs /rootfs
		tar xvf $FILETOW -C /rootfs
		sync
	else
		echo "Unable to download $FILETOW"
	fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
