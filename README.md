meta-engicam
============

Yocto engicam meta layer for krogoth yocto

__Version:__ 1.0.0

## Engicam available machine :##

* geamx6ul
* gealmx6ull
* isiot-geamx6ul
* icoremx6solo
* icoremx6duallite
* icoremx6dual
* icoremx6quad
* icoremx6solorqs
* icoremx6dualliterqs
* icoremx6dualrqs
* icoremx6quadrqs

## Engicam available images:

* engicam-test-hw
* engicam-demo-qt


__Before start :__

Install the fsl-bsp-platform.

Essential Yocto Project host packages are:
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev

i.MX layers host packages for a Ubuntu 12.04 or 14.04 host setup are:
sudo apt-get install libsdl1.2-dev xterm sed cvs subversion coreutils texi2html docbook-utils python-pysqlite2 help2man make gcc g++ desktop-file-utils \
libgl1-mesa-dev libglu1-mesa-dev mercurial autoconf automake groff curl lzop asciidoc

i.MX layers host packages for a Ubuntu 12.04 host setup only are:
sudo apt-get install uboot-mkimage

i.MX layers host packages for a Ubuntu 14.04 host setup only are:
sudo apt-get install u-boot-tools

mkdir ~/bin (this step may not be needed if the bin folder already exists)
curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
chmod a+x ~/bin/repo
export PATH=~/bin:$PATH

git config --global user.name "Your Name"
git config --global user.email "Your Email"
git config --list

mkdir fsl-release-bsp
cd fsl-release-bsp
repo init -u git://git.freescale.com/imx/fsl-arm-yocto-bsp.git -b imx-4.1-krogoth
repo sync

after repo tool end all tasks copy the meta-engicam  layer on sources folder.


## Quick start

### How to build image :

Create or open an existing build environment

MACHINE=<icoreM6 machine name> sources engicam-setup-environment <build directory>

Accept the license and then build the image

bitbake <image name>

The result of building process will be added in tmp/deploy/images/<machine name>

### Flash sdcard card image:

sudo dd if=imagename.sdcard of=/dev/sdX  bs=10M && sync

example:
sudo dd if=engicam-test-hw-icorem6solo.sdcard of=/dev/sdb  bs=10M && sync


## Flash nand image


### Before start

Create and write a sdcard wth engicam-test-hw:

bitbake engicam-test-hw
sudo dd if=engicam-test-hw.sdcard of=/dev/sdb  bs=10M && sync

after that, create flash image , es.
bitbake engicam-demo-qt (remenber to set the UBOOT_CONFIG = "nand" on the machine file)

and copy the files:
* u-boot.imx
* uImage
* starterkit.dtb
* rootfs.tar.bz2

in the sd card filesystem partition.

## Programmind nand flash

### Programming u-boot on nand flash:

1. boot linux
2. copy the uImage kernel file on target
3. pad the uboot image with the dd command

##shell##
dd if= u-boot.imx of=/mnt/u-boot_my.imx bs=512 seek=2
#########

4. now flash the padded u-boo with command :

##shell##
flash_erase /dev/mtd0 0 0
kobs-ng init -v /mnt/u-boot_my.imx
#########

### Programming kernel on nand flash:

1. boot linux
2. copy the uImage kernel file on target
3. on terminal launch the following command :

##shell##
flash_erase /dev/mtd1 0 0
nandwrite /dev/mtd1 -p uImage
#########

### Programming devicetree on nand flash:
1. boot linux
2. copy the _device tree file.dtb_ on target
3. on terminal launch the following command :

##shell##
flash_erase /dev/mtd2 0 0
nandwrite /dev/mtd2 -p  device_tree_file.dtb
#########

### Programming rootfs on nand flash:
1. boot linux
2. copy the  on target
3. on terminal launch the following command :

##shell##
ubiformat /dev/mtd3
ubiattach /dev/ubi_ctrl -m 3
ubimkvol /dev/ubi0 -N rootfs -s240000000
mkdir /rootfs
mount -t ubifs ubi0:rootfs /rootfs
tar xvf rootfs.tar.bz2 -C /rootfs
sync
#########

________________________________________________________________________________

## Nand flash programming from u-boot

Check the u-boot variables mtdids and mtdpars.

set mtdids 'nand0=gpmi-nand'
set mtdparts 'mtdparts=gpmi-nand:4m(boot),8m(kernel),1m(dtb),-(rootfs)'

### Programming kernel
tftp 12000000 uImage
nand erase 0x00400000 0x00800000
nand write 12000000 0x00400000 0x00800000

### Programming device tree
tftp 12000000 uImage.dtb
nand erase 0x00c00000 0x00100000
nand write 12000000 0x00c00000 0x00100000

### Programming root filesystem
nand erase.part rootfs
tftp 12000000 rootfs.ubifs
ubi part rootfs
ubi create rootfs
ubi write 12000000 rootfs ${filesize}
ubifsmount ubi0:rootfs
ubifsls

# SDK generation

bitbake engicam-demo-qt -c populate_sdk

#Install the toolchain
./tmp/deploy/sdk/poky-glibc-x86_64-engicam-demo-qt-cortexa9hf-neon-toolchain-2.1.1.sh
using the default directory

________________________________________________________________________________

### Programming i.Coremx6 1.5

### Flash sdcard card image:

sudo dd if=imagename.sdcard of=/dev/sdX  bs=10M && sync

example:
sudo dd if=engicam-test-hw-icorem6solo.sdcard of=/dev/sdb  bs=10M && sync

### Copy operating system on sdcard :
sudo cp uImage /media/hostname/a1418232-4ab3-4353-a5b0-15d4f32a8b62/
sudo cp <machine name>-icore-mipi.dtb /media/hostname/a1418232-4ab3-4353-a5b0-15d4f32a8b62/
sudo cp rootfs.tar.bz2 /media/hostname/a1418232-4ab3-4353-a5b0-15d4f32a8b62/
sudo cp u-boot-emmc-2016.07-r0.imx /media/hostname/a1418232-4ab3-4353-a5b0-15d4f32a8b62/u-boot.imx

### Starting operating system by sdcard:
1.Close the connetctor JM1 on the carrier
2.Insert sdcard in the carrier board
3.Power on system
4.To stop in the u-boot by pressing any key on the keyboard
5.setenv fdt_file icoremx6dl-icore-mipi.dtb
6.boot

### Programming module:
emmc_fs_ker_dtb.sh / <machine name>-icore-mipi.dtb -p
emmc_boot.sh /
 
