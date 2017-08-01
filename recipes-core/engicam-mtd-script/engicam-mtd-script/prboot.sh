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


if [ -f "$FILETOW" ]
then
   echo "$FILETOW found."
else
   echo "ERROR $FILETOW not found."
   exit 1
fi


dd if=$FILETOW of=/mnt/u-boot_my.imx bs=512 seek=2
flash_erase /dev/mtd0 0 0
kobs-ng init -v /mnt/u-boot_my.imx
rm /mnt/u-boot_my.imx
