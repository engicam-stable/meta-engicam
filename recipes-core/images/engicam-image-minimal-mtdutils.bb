require core-image-minimal.bb

DESCRIPTION = "Engicam Small image capable of booting a device with support for the \
Minimal MTD Utilities, which let the user interact with the MTD subsystem in \
the kernel to perform operations on flash devices."

IMAGE_FSTYPES = "tar.bz2 sdcard ubifs"
 
IMAGE_INSTALL_append += " mtd-utils imx-kobs mtd-utils-ubifs"

EXTRA_IMAGE_FEATURES = "debug-tweaks ssh-server-openssh tools-debug"

UBOOT_CONFIG = "sd"

FSL_KERNEL_DEFCONFIG="icore-defconfig"

IMAGE_OVERHEAD_FACTOR = "200.0"

IMAGE_INSTALL += "engicam-mtd-script \ 
    engicam-emmc-script \
    engicam-mtd-script \
    engicam-emmc-script \
    fw-nandautosize \
    u-boot-fw-utils"


