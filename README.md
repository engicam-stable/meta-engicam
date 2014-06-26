meta-engicam
============

yocto engicam meta layer

for icoreM6solo starterkit:

set mmcargs 'setenv bootargs console=${console},${baudrate} ${smp} root=${mmcroot} cma=96MB gpumem=16MB video=mxcfb0:dev=lcd,Amp-WD'

for icoreM6duallite/icorem6dual/icorem6duad starterkit:

set mmcargs 'setenv bootargs console=${console},${baudrate} ${smp} root=${mmcroot} video=mxcfb0:dev=lcd,Amp-WD'




Engicam machines:

icorem6dual 
icorem6duallite 
icorem6quad
icorem6solo
icorem6solo512


Engicam images:

engicam-image-minimal-mtdutils <tested>
engicam-image-minimal-nand     <tested>

for nand boot:	 	
set bootargs 'console=ttymxc3,115200 ubi.mtd=3 root=ubi0:rootfs rootfstype=ubifs mtdparts= -nand:4m(boot),8m(kernel),1m(dtb),-(rootfs)'


Flash on nand :

1. create a sdcard for nand programming with command:

bitbake engicam-image-minimal-mtdutils

boot it and set the u-boot variable:
 
set mmcargs 'setenv bootargs console=${console},${baudrate} ${smp} root=${mmcroot}  cma=96MB gpumem=16MB video=mxcfb0:dev=lcd,Amp-WD mtdparts=gpmi-nand:4m(boot),8m(kernel),1m(dtb),-(rootfs)'

after that, create a nand flash image , es. bitbake engicam-image-minimal-nand (remenber to set the UBOOT_CONFIG = "nand" on the machine file)

2.

#programming u-boot

pad the uboot image with the dd command:

dd if= <u-boot file> of=/mnt/u-boot_my.imx bs=512 seek=2 

and flash it:
flash_erase /dev/mtd0 0 0
kobs-ng init -v /mnt/u-boot_my.imx


#kernel programming:
flash_erase /dev/mtd1 0 0
nandwrite /dev/mtd1 -p <uImage file> 

#device tree programming
flash_erase /dev/mtd2 0 0
nandwrite /dev/mtd2 -p  <device tree file>

#rootfs programming:  
ubiformat /dev/mtd3
ubiattach /dev/ubi_ctrl -m 3
ubimkvol /dev/ubi0 -N rootfs -s240000000
mkdir /rootfs
mount -t ubifs ubi0:rootfs /rootfs
tar xvf <rootfs.tar.bz2 file> -C /rootfs 
sync

reboot the system and change the u-boot bootargs varibale:

set  bootargs 'console=ttymxc3,115200 ubi.mtd=3  root=ubi0:rootfs rootfstype=ubifs mtdparts=gpmi-nand:4m(boot),8m(kernel),1m(dtb),-(rootfs)'


