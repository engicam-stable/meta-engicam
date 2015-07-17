inherit core-image
inherit distro_features_check

DESCRIPTION = "Engicam gstreamer 1.0 image minimal, for 256Mb nand size"

IMAGE_INSTALL_append = "imx-kobs "

FSL_KERNEL_DEFCONFIG="icore-defconfig"

SOC_IMAGE_INSTALL = ""
SOC_IMAGE_INSTALL_mx6 = "gpu-viv-bin-mx6q gpu-viv-g2d"

IMAGE_INSTALL += " \
    ${SOC_IMAGE_INSTALL} \
    "

UBOOT_CONFIG = "sd"

LICENSE = "MIT"

IMAGE_FSTYPES = "tar.bz2 sdcard ubifs"

SOC_EXTRA_IMAGE_FEATURES ?= "tools-testapps"

IMAGE_INSTALL_append = "imx-kobs "

# Add extra image features
EXTRA_IMAGE_FEATURES += " \
    ${SOC_EXTRA_IMAGE_FEATURES} \
    ssh-server-dropbear \
"

IMAGE_INSTALL += " \
    packagegroup-fslc-gstreamer1.0-full \
    gstreamer1.0-plugins-imx-meta \    
    gpu-viv-bin-mx6q \
    libfslcodec \
    libfslparser \
    libfslvpuwrap \
    firmware-imx \
    engicam-mtd-script \
    engicam-emmc-script \
    fw-nandautosize \
    u-boot-fw-utils \
    imx-lib \
    imx-vpu \
    e2fsprogs \
"	


CONFLICT_DISTRO_FEATURES = "x11 wayland"

export IMAGE_BASENAME = "engicam-image-gstreamer-1.0-minimal"


