meta-engicam
============

Preliminary Yocto engicam meta layer for pyro yocto

__Version:__ 1.0.0

## Engicam available machine :##

* icoremx6solo
* icoremx6duallite
* icoremx6dual
* icoremx6quad


## Engicam available images:

* engicam-test-hw
* engicam-demo-qt


__Before start :__

Install the fsl-community-bsp-platform.

Please read the instructions on link:

http://freescale.github.io/#download

after repo tool end all tasks copy the meta-engicam  layer on sources folder.

## Quick start

### How to build image :

Create or open an existing build environment

MACHINE=<icoreM6 machine name> sources engicam-setup-environment <build directory>

Accept the license and then build the image

bitbake <image name>

The result of building process will be added in tmp/deploy/images/<machine name>

### Flash sdcard card image:

sudo dd if=imagename.sdcard of=/dev/sdXX  bs=1M && sync

example:
sudo dd if=engicam-image-gstreamer-icorem6solo.sdcard of=/dev/sdb  bs=1M && sync


## Flash nand image


### Before start

Create and write a sdcard wth engicam-test-hw:

```
bitbake engicam-test-wh
sudo dd if=engicam-test-hw.sdcard of=/dev/sdb  bs=1M && sync
```

after that, create flash image , es.
```
bitbake engicam-demo-qt (remenber to set the UBOOT_CONFIG = "nand" on the machine file)
```

and copy the files:
* u-boot.bin
* uImage
* starter-kit.dtb
* rootfs.tar.bz2

in the sd card filesystem partition.

## Programmind nand flash

### Programming u-boot on nand flash:

1. boot linux
2. copy the uImage kernel file on target
3. pad the uboot image with the dd command
```shell
dd if= u-boot.bin of=/mnt/u-boot_my.imx bs=512 seek=2
```

4. now flash the padded u-boo with command :
```shell
flash_erase /dev/mtd0 0 0
kobs-ng init -v /mnt/u-boot_my.imx
```

### Programming kernel on nand flash:

1. boot linux
2. copy the uImage kernel file on target
3. on terminal launch the following command :

```shell
flash_erase /dev/mtd1 0 0
nandwrite /dev/mtd1 -p uImage
```

### Programming devicetree on nand flash:
1. boot linux
2. copy the _device tree file.dtb_ on target
3. on terminal launch the following command :

```shell
flash_erase /dev/mtd2 0 0
nandwrite /dev/mtd2 -p  device_tree_file.dtb
```

### Programming rootfs on nand flash:
1. boot linux
2. copy the  on target
3. on terminal launch the following command :

```shell
ubiformat /dev/mtd3
ubiattach /dev/ubi_ctrl -m 3
ubimkvol /dev/ubi0 -N rootfs -s240000000
mkdir /rootfs
mount -t ubifs ubi0:rootfs /rootfs
tar xvf rootfs.tar.bz2 -C /rootfs
sync
```

________________________________________________________________________________

## Nand flash programming from u-boot

Check the u-boot variables mtdids and mtdpars.

```
set mtdids 'nand0=gpmi-nand'
set mtdparts 'mtdparts=gpmi-nand:4m(boot),8m(kernel),1m(dtb),-(rootfs)'
```

### Programming kernel
```
tftp 12000000 uImage
nand erase 0x00400000 0x00800000
nand write 12000000 0x00400000 0x00800000
```

### Programming device tree
```
tftp 12000000 uImage.dtb
nand erase 0x00c00000 0x00100000
nand write 12000000 0x00c00000 0x00100000
```

### Programming root filesystem
```
nand erase.part rootfs
tftp 12000000 rootfs.ubifs
ubi part rootfs
ubi create rootfs
ubi write 12000000 rootfs ${filesize}
ubifsmount ubi0:rootfs
ubifsls
```
# SDK generation

```
bitbake engicam-demo-qt -c populate_sdk
```
