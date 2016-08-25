#!/bin/bash
# EMMC programmer

ver="ver. 1.6, 2016-08-25"
filebytftp=false

function error
{
	if [ "$1" != "0" ];
	then
	
		if [ "$2" != "" ];
		then
			echo "ERROR: $2"
		fi
		
		exit
	fi
}

function create_emmc
{
echo "Partitioning emmc"
echo "o
n
p
1

+8M
n
p
2


t
1
c
w 
q" | fdisk /dev/mmcblk1 
error $?

echo "Format emmc"
mkdosfs /dev/mmcblk1p1
error $?

sync
}

function usage
{
	echo -e "$1: $ver\n" 
	if [ "$filebytftp" == true ];
	then
		ext="_tftp.sh"
		path=""
	else
		ext=".sh"
		path="<path of directory with files>"
	fi
	
	if [ "$1" == "emmc_fs" ];
	then
		echo "Usage: ${1}${ext} [-h]  $path"
	fi

	if [ "$1" == "emmc_ker_dtb" ];
	then
		echo "Usage: ${1}${ext} [-h]  $path <dtb name>"
	fi

	if [ "$1" == "emmc_fs_ker_dtb" ];
	then
		echo "Usage: ${1}${ext} [-h] $path <dtb name> [-p]"
	fi
	
	if [ "$1" == "emmc_ker" ];
	then
		echo "Usage: ${1}${ext} [-h] $path"
	fi

	if [ "$1" == "emmc_dtb" ];
	then
		echo "Usage: ${1}${ext} [-h] $path <dtb name>"
	fi

	if [ "$1" == "emmc_boot" ];
	then
		echo "Usage: ${1}${ext} [-h] $path"
	fi
	
	if [ "$1" == "emmc_sdcard" ];
	then
		echo "Usage: ${1}${ext} [-h] <path file.sdcard>"
	fi
	
	if [ "$filebytftp" == true ];
	then
		echo " Before to exec $1 give the command: export serverip=[xxx.xxx.xxx.xxx]"
	fi
	
	echo -e "\nThe order of the options is important!\n"
	exit
}

function download_tftp
{
	echo "Download $1 wait a while..."
	tftp -g -r $1 $serverip
	
	if [ $? -eq 1 ]; 
	then
		echo "TFTP ERROR"
		exit
	fi
	
	if [ ! -f $1 ]; 
	then
		echo "ERROR: Unable to download $1"
		rm -f $1
	fi
}

function check_file
{
	if [ ! -f $1 ];
	then
		echo "ERROR: file $1 not found"
		exit
	fi
}

function write_fs
{
	# Format filesystem
	mkfs.ext4 /dev/mmcblk1p2
	error $?

	rm -rf /tmp/mmcblk1p2
	mkdir /tmp/mmcblk1p2
	
	echo "Mount /dev/mmcblk1p2"
	mount /dev/mmcblk1p2 /tmp/mmcblk1p2
	if [ $? -eq 0 ];
	then
		
		echo "Extract filesystem"
		tar xvf $1 -C /tmp/mmcblk1p2
	
		echo "Umount device"
		umount /tmp/mmcblk1p2
		echo "sync"
		sync
	
		echo "Done"
	else
		echo "ERROR: Unable to mount /dev/mmcblk1p2"
	fi
	
	if [ "$filebytftp" == true ];
	then
		rm -f $1
	fi

	rm -rf /tmp/rmmcblk1p2
}

function write_ker
{
	rm -rf /tmp/mmcblk1p1
	mkdir /tmp/mmcblk1p1
	
	echo "Mount /dev/mmcblk1p1"
	mount /dev/mmcblk1p1 /tmp/mmcblk1p1
	if [ $? -eq 0 ];
	then
		
		echo "Copy $1"
		cp $1 /tmp/mmcblk1p1
	
		echo "Umount device"
		umount /tmp/mmcblk1p1
		echo "sync"
		sync
	
		echo "Done"
	else
		echo "ERROR: Unable to mount /dev/mmcblk1p1"
	fi
	
	if [ "$filebytftp" == true ];
	then
		rm -f $1
	fi

	rm -rf /tmp/mmcblk1p1
}

function write_dtb
{
	rm -rf /tmp/mmcblk1p1
	mkdir /tmp/mmcblk1p1
	
	echo "Mount /dev/mmcblk1p1"
	mount /dev/mmcblk1p1 /tmp/mmcblk1p1
	if [ $? -eq 0 ];
	then
		
		echo "Copy $1"
		cp $1 /tmp/mmcblk1p1
	
		echo "Umount device"
		umount /tmp/mmcblk1p1
		echo "sync"
		sync
	
		echo "Done"
	else
		echo "ERROR: Unable to mount /dev/mmcblk1p1"
	fi
	
	if [ "$filebytftp" == true ];
	then
		rm -f $1
	fi

	rm -rf /tmp/mmcblk1p1
}

function write_boot
{
	dd if=$1 of=/dev/mmcblk1 bs=512 seek=2
	error $?
	sync
	
	if [ "$filebytftp" == true ];
	then
		rm -f $1
	fi
	
	echo "Done"
}

function write_sdcard
{
	dd if=$1 | pv | dd of=/dev/mmcblk1 bs=16M
	sync
	
	echo "Done"
}

############
### MAIN ###
############
command=$(basename $0)

# Check if booted from sdcard
boot_from_sdcard=$(grep /dev/mmcblk0p2 /proc/cmdline)

# Commands permitted
if [ "$boot_from_sdcard" == "" ];
then
	declare -a commands=("emmc_ker" "emmc_dtb" "emmc_boot")
else
	declare -a commands=("emmc_fs" "emmc_ker_dtb" "emmc_fs_ker_dtb" "emmc_ker" "emmc_dtb" "emmc_boot" "emmc_sdcard")
fi

# Check the command
findC=false
for i in "${commands[@]}"
do
	if [ "$i.sh" == "$command" -o "${i}_tftp.sh" == "$command" ]; 
	then
		
		if [ "${i}_tftp.sh" == "$command" ];
		then
			filebytftp=true
		fi
		
		findC=true
		command=$i
		
		break
	fi
done

if [ "$findC" == false ];
then
	echo "ERROR: Command $command not found"
	exit
fi

if [ "$1" == "-h" ];
then
	usage $command
fi

# Check env & sintax
dtbfile=""
pathfile="."
if [ "$filebytftp" == true ];
then
	has_serverip=$(env | grep -c  ^serverip=)
	if [ "$has_serverip" == "0" ];
	then
		usage $command
	fi
	
	if grep -q "dtb" <<< "$command" ;
	then
		if [ "$1" == "" -o "$1" == "-p" ]; # No dtb name specified
		then
			usage $command
		else
			dtbfile=$1
		fi
	fi
else
	if [ "$1" == "" ]; # No path specified
	then
		usage $command
	else
		pathfile=$1
	fi

	if grep -q "dtb" <<< "$command" ; 
	then
		if [ "$2" == "" -o "$2" == "-p" ]; # No dtb name specified
		then
			usage $command
		else
			dtbfile=$2
		fi
	fi
fi

# Check block device
if [ ! -b "/dev/mmcblk1" ];
then
	echo "ERROR: device /dev/mmcblk1 not found"
	exit
fi
 
# Download files 
if [ "$filebytftp" == true ]; 
then
	if grep -q "fs" <<< "$command" ;
	then
		rm -f "rootfs.tar.bz2"
		download_tftp "rootfs.tar.bz2"
	fi
	
	if grep -q "ker" <<< "$command" ;
	then
		rm -f "uImage"
		download_tftp "uImage"
	fi
	
	if grep -q "dtb" <<< "$command" ;
	then
		rm -f $dtbfile
		download_tftp $dtbfile
	fi
	
	if grep -q "boot" <<< "$command" ;
	then
		rm -f "u-boot.imx"
		download_tftp "u-boot.imx"
	fi	
fi

# Check files
if [ "$command" == "emmc_sdcard" ];
then
	check_file $1
else
	if [ "${pathfile: -1}" != "/" ];
	then
		pathfile+="/"
	fi

	if grep -q "fs" <<< "$command" ;
	then
		check_file "${pathfile}rootfs.tar.bz2"
	fi
		
	if grep -q "ker" <<< "$command" ;
	then
		check_file "${pathfile}uImage"
	fi
		
	if grep -q "dtb" <<< "$command" ;
	then
		check_file ${pathfile}${dtbfile}
	fi
		
	if [ "$command" == "emmc_boot" ];
	then
		check_file "${pathfile}u-boot.imx"
	fi	
fi

# DO COMMAND
if grep -q "fs" <<< "$command" ; # Write filestystem
then

	if [ "$command" == "emmc_fs_ker_dtb" ]; # Prepare emmc
	then
		if [ "$filebytftp" == true -a "$2" == "-p" ] || [ "$filebytftp" == false -a "$3" == "-p" ]; 
		then
			create_emmc
		fi
	fi
	
	write_fs "${pathfile}rootfs.tar.bz2"
fi

if grep -q "ker" <<< "$command" ; # Write kernel
then
	write_ker "${pathfile}uImage"
fi

if grep -q "dtb" <<< "$command" ; # Write dtb
then
	write_dtb ${pathfile}${dtbfile}
fi

if [ "$command" == "emmc_boot" ]; # Write u-boot
then
	write_boot "${pathfile}u-boot.imx"
fi

if [ "$command" == "emmc_sdcard" ];
then
	write_sdcard $1
fi
