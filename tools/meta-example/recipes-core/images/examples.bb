inherit core-image
inherit distro_features_check

DESCRIPTION = "Example default custom board image with gstreamer version 0.1"

IMAGE_INSTALL_append = " mtd-utils imx-kobs "

FSL_KERNEL_DEFCONFIG="icore-defconfig"

SOC_IMAGE_INSTALL = ""
SOC_IMAGE_INSTALL_mx6 = "gpu-viv-bin-mx6q gpu-viv-g2d"

IMAGE_INSTALL += " \
    ${SOC_IMAGE_INSTALL} \
    cpufrequtils \
    "

UBOOT_CONFIG = "nand"

LICENSE = "MIT"


SOC_EXTRA_IMAGE_FEATURES ?= " "

IMAGE_INSTALL_append = " mtd-utils imx-kobs "

# Add extra image features
EXTRA_IMAGE_FEATURES += " \
    ${SOC_EXTRA_IMAGE_FEATURES} \
    nfs-server \
    ssh-server-dropbear \
"

IMAGE_INSTALL += " \
    packagegroup-fsl-gstreamer \
    packagegroup-fsl-gstreamer-streamer \
    gpu-viv-bin-mx6q \
    alsa-utils \
    alsa-tools \
    libfslcodec \
    libfslparser \
    libfslvpuwrap \
    firmware-imx \
    imx-lib \
    imx-vpu \
    cpufrequtils \
    engicam-mtd-script \
    iproute2 \
    canutils \
    cantest \	
    ppp \
    ppp-dialin \
    sqlite3 \
"	

CORE_IMAGE_EXTRA_INSTALL += " \
    packagegroup-fsl-gstreamer-full \
"

CONFLICT_DISTRO_FEATURES = "x11 wayland"

export IMAGE_BASENAME = "example"


