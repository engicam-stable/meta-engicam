inherit core-image
inherit distro_features_check

DESCRIPTION = "Engicam default image with gstreamer version 1.0"

IMAGE_INSTALL_append = " mtd-utils imx-kobs "

FSL_KERNEL_DEFCONFIG="icore-defconfig"

SOC_IMAGE_INSTALL = ""
SOC_IMAGE_INSTALL_mx6 = "gpu-viv-bin-mx6q gpu-viv-g2d fsl-gpu-sdk"

IMAGE_INSTALL += " \
    ${SOC_IMAGE_INSTALL} \
    cpufrequtils \
    "

UBOOT_CONFIG = "sd"

LICENSE = "MIT"


SOC_EXTRA_IMAGE_FEATURES ?= "tools-testapps"

IMAGE_INSTALL_append = " mtd-utils imx-kobs "

# Add extra image features
EXTRA_IMAGE_FEATURES += " \
    ${SOC_EXTRA_IMAGE_FEATURES} \
    nfs-server \
    tools-debug \
    tools-profile \
    ssh-server-dropbear \
"

IMAGE_INSTALL += " \
    packagegroup-fslc-gstreamer1.0-full \
    gstreamer1.0-plugins-imx-meta \    
    gpu-viv-bin-mx6q \
    alsa-utils \
    alsa-tools \
    libfslcodec \
    libfslparser \
    libfslvpuwrap \
    firmware-imx \
    engicam-mtd-script \
    engicam-emmc-script \
    fw-nandautosize \
    u-boot-fw-utils \
    imx-lib \
    imx-test \
    imx-vpu \
    tslib \
"	


CONFLICT_DISTRO_FEATURES = "x11 wayland"

export IMAGE_BASENAME = "engicam-image-gstreamer-1.0"


