# Provides the iCore6 common settings

include conf/machine/include/tune-cortexa9.inc
include conf/machine/include/imx-base.inc

IMAGE_FSTYPES = "tar.bz2 ext4 sdcard"

SERIAL_CONSOLE = "115200 ttymxc3"

MACHINE_FEATURES += "wifi"
KERNEL_IMAGETYPE = "zImage"

PREFERRED_PROVIDER_virtual/kernel = "linux-engicam-imx"
PREFERRED_PROVIDER_u-boot = "u-boot-eng"
PREFERRED_PROVIDER_virtual/bootloader = "u-boot-eng"

UBOOT_CONFIG ?= "sd"

UBI_VOLNAME ?= "rootfs"

