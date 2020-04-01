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

if env | grep -q ^serverip=; then
	echo "Download zImage wait a while..."
	tftp -g -r $FILETOW  $serverip
  if [ $? -eq 1 ]; then
     echo "TFTP Error check network config"
     exit
  fi

  if [ -f $FILETOW ]; then
  		#kernel device tree programming:
  		echo "kernel programming..."
  		flash_erase /dev/mtd1 0 0
  		nandwrite /dev/mtd1 -p  $FILETOW
      echo "done"
  else
  		echo "Unable to download $FILETOW"
  fi
else
	echo "Serverip not setted:"
	echo "    export serverip=192.168.XXX.XXX"
fi
