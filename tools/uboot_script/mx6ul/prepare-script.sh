#!/bin/bash


for dir in "$@"
do
	FILE=`echo $dir|sed 's/\..\{3\}$//'`
	echo $FILE
	mkimage -A arm -O linux -T script -C none -a 0 -e 0  -n "${FILE} script" -d ${FILE}.txt ${FILE}.scr
done



