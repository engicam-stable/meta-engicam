# Provides the iCore6 common settings

include conf/machine/include/tune-cortexa9.inc
include conf/machine/include/imx-base.inc

MKUBIFS_ARGS ?= "${@bb.utils.contains('NANDREV', '2', '-m 2048 -e 126976 -c 3992', '-m 4096 -e 253952 -c 1996', d)}"
UBINIZE_ARGS ?= "${@bb.utils.contains('NANDREV', '2', '-m 2048 -p 131072 -s 2048', '-m 4096 -p 262144 -s 4096', d)}"

IMAGE_FSTYPES = "tar.bz2 ext4 sdcard ubifs"

SERIAL_CONSOLE = "115200 ttymxc3"

MACHINE_FEATURES += "wifi"
KERNEL_IMAGETYPE = "uImage"

PREFERRED_PROVIDER_virtual/kernel ??= "engicam-linux-fslc"
PREFERRED_PROVIDER_u-boot = "u-boot-eng"
PREFERRED_PROVIDER_virtual/bootloader = "u-boot-eng"

UBOOT_CONFIG ?= "sd"

UBI_VOLNAME ?= "rootfs"

