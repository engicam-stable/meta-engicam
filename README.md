meta-engicam
============

yocto engicam meta layer

Default parameter built for engicam starterkit. Image available for SODIMM and RQS6Q7 standards modules. Please refer to engicam board user manual for setup a different board.

Engicam availbale machine are:

icoreM6duallite/icorem6dual/icorem6quad/icorem6solo/icorem6solo512
rqsm6dual/rqsm6duallight/rqsm6quad/rqsm6solo


Engicam images:

engicam-dev-fb-qt5
engicam-dev-fb-qt5-demo
engicam-image-minimal-nand
engicam-image-minimal-mtdutils
engicam-image-gstreamer
core-image-minimal

#Before start
Before start remind to place the floder to this path in the virtual machine or to replace your meta-engicam previus folder

/home/user/yocto_daisy/fsl-community-bsp/sources/meta-engicam

After that remind to replace our engicam configuration script 

cp /home/user/yocto_daisy/fsl-community-bsp/ sources/meta-engicam/tools/engicam-setup-environment /home/user/yocto_daisy/fsl-community-bsp/

#Building an image
Create or open an existing build environment

MACHINE=<icoreM6 machine name> sources engicam-setup-environment <build directory>

Accept the license and then build the image

bitbake <image name>

The result of building process will be added in tmp/deploy/images/<machine name>

#Flash on sdcard:

sudo dd if=imagename.sdcard of=/dev/sdXX  bs=1M && sync

example:
sudo dd if=engicam-image-gstreamer-icorem6solo.sdcard of=/dev/sdb  bs=1M && sync


#Flash on nand

create and write an sdcard for nand programming with command:

bitbake engicam-image-minimal-mtdutils
sudo dd if=engicam-image-minimal-mtdutils.sdcard of=/dev/sdb  bs=1M && sync

after that, create a nand flash image , es. bitbake engicam-image-minimal-nand (remenber to set the UBOOT_CONFIG = "nand" on the machine file) and copy the files u-boot.bin, uImage, .dtb and rootfs.tar.bz2 in the sd card filesystem partition 

boot the board by sdcard, at hte end of the boot run the program script:

prboot.sh
prkernel.sh
prfs.sh

Or following this instruction for having additional details about the writing procedure

#programming u-boot

pad the uboot image with the dd command:

dd if= u-boot.bin of=/mnt/u-boot_my.imx bs=512 seek=2 

and flash it:
flash_erase /dev/mtd0 0 0
kobs-ng init -v /mnt/u-boot_my.imx


#kernel programming
flash_erase /dev/mtd1 0 0
nandwrite /dev/mtd1 -p uImage

#kernel device tree programming
flash_erase /dev/mtd2 0 0
nandwrite /dev/mtd2 -p  device_tree_file.dtb

#rootfs programming: 
ubiformat /dev/mtd3
ubiattach /dev/ubi_ctrl -m 3
ubimkvol /dev/ubi0 -N rootfs -s240000000
mkdir /rootfs
mount -t ubifs ubi0:rootfs /rootfs
tar xvf rootfs.tar.bz2 -C /rootfs 
sync

reboot the system by nand

#u-boot bootcmd SODIMM
In the u-boot bootloader are available two default bootargs and bootcmd for run the kernel and read the filesystem from SD card or NAND memory. 
Type from the u-boot promt the command "run bootcmd_mmc" from read fs and kernel from the SD card or type run "bootcmd_ubi for" for read fs and kernel from nand.

If you build your YOCTO image in sd configuration you will atuomatically read it form sd otherwhise you will automatically read it from nand memory. But if you would like to switch you can stop in the u-boot prompt and switch between the two mode.

#u-boot bootcmd RQS6Q7
At the same time on RQS7Q7 modules you can switch between external SD card and internal eMMC memory. You can switch between the two mode by type in u-boot promt this two command "run bootcmd_mmc" and "run bootcmd_emmc"
If you open or close the jumper you will automatically boot from external sd if you close the jumper and if you keep the jumper open by internal eMMC memory.

============
For all other information please refer to Engicam YOCTO BSP manual

