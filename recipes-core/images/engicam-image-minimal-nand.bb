require core-image-minimal.bb

DESCRIPTION = "Engicam Small minimal image writable on NAND memory"


IMAGE_INSTALL_append += " mtd-utils imx-kobs mtd-utils-ubifs"

FSL_KERNEL_DEFCONFIG="icore-defconfig"

UBOOT_CONFIG = "nand"

SOC_IMAGE_INSTALL = ""
SOC_IMAGE_INSTALL_mx6 = "gpu-viv-bin-mx6q gpu-viv-g2d fsl-gpu-sdk"

IMAGE_INSTALL += " \
    ${SOC_IMAGE_INSTALL} \
    cpufrequtils \
    engicam-mtd-script \
    "
