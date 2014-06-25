require core-image-minimal.bb

DESCRIPTION = "Engicam Small image capable of booting a device with support for the \
Minimal MTD Utilities, which let the user interact with the MTD subsystem in \
the kernel to perform operations on flash devices."

IMAGE_INSTALL_append = " mtd-utils imx-kobs "

FSL_KERNEL_DEFCONFIG="icore-defconfig"

UBOOT_CONFIG = "nand"


