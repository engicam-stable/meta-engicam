#!/bin/sh

FILETOW=zImage

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
   #FILETOW=$1
else
   echo "ERROR $FILETOW not found."
   exit 1
fi

flash_erase /dev/mtd1 0 0
nandwrite /dev/mtd1 -p  $FILETOW
