# Provides the geamx6 common settings


include conf/machine/include/imx-base.inc
include conf/machine/include/tune-cortexa7.inc


IMAGE_FSTYPES = "tar.bz2 ext4 sdcard ubifs"

MACHINE_FEATURES += "wifi"
KERNEL_IMAGETYPE = "uImage"

PREFERRED_PROVIDER_virtual/kernel = "engicam-linux-fslc"
PREFERRED_PROVIDER_u-boot = "u-boot-eng"
PREFERRED_PROVIDER_virtual/bootloader = "u-boot-eng"

UBOOT_CONFIG ?= "sd"

UBINIZE_ARGS = "-m 2048 -p 128KiB -s 2048"
MKUBIFS_ARGS = "-m 2048 -e 126976 -c 1944"
UBI_VOLNAME = "rootfs"

MACHINEOVERRIDES ?= "mx6:mx6ul:"

SERIAL_CONSOLE ?= "115200 ttymxc0"
