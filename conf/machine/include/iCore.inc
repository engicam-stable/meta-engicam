# Provides the iCore6 common settings

require conf/machine/include/imx-base.inc

SDCARD_ROOTFS = "${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ext4"
IMAGE_FSTYPES = "tar.bz2 ext4 sdcard"

SERIAL_CONSOLE = "115200 ttymxc3"

MACHINE_FEATURES += "wifi"
KERNEL_IMAGETYPE = "uImage"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-icore"

PREFERRED_PROVIDER_u-boot ?= "u-boot-eng"
PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot-eng"

UBOOT_CONFIG ?= "sd"

UBI_VOLNAME ?= "rootfs"

PREFERRED_VERSION_imx-kobs_mx6ul  = "5.1"
PREFERRED_VERSION_imx-kobs_mx6  = "3.14.28%"