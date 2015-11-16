#!/bin/bash

if [ "${1}" == "" ]; then
echo "Missing image file"
exit 1
fi

if [ "${2}" == "" ]; then
echo "Missing target device"
exit 1
fi

if [ ! -f "${1}" ]; then
echo "Image file \"${1}\" doesn't exist"
exit 1
fi
     
if [ "${2}" == "/dev/sda" ] || [ "${2}" == "/dev/sda1" ] || [ "${2}" == "/dev/sda2" ] || [ "${2}" == "/dev/sda3" ] || [ "${2}" == "/dev/sda4" ]; then
echo "ERROR: can't flash on ${2}"
exit 1
fi

bzcat ${1} | pv | sudo dd of=${2} bs=8192
exit $?


