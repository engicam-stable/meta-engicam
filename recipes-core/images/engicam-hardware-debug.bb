require core-image-minimal.bb

DESCRIPTION = "Engicam image with tools for hardware debug"


IMAGE_INSTALL_append += " mtd-utils imx-kobs mtd-utils-ubifs"

EXTRA_IMAGE_FEATURES = "debug-tweaks ssh-server-openssh tools-debug"

FSL_KERNEL_DEFCONFIG="icore-defconfig"

IMAGE_FSTYPES = "sdcard ubifs"

SOC_IMAGE_INSTALL = ""
SOC_IMAGE_INSTALL_mx6 = "gpu-viv-g2d"

IMAGE_INSTALL += " \
    ${SOC_IMAGE_INSTALL} \
    engicam-mtd-script \
    engicam-emmc-script \
    iproute2 \
    cantest \
    wf111-driver \
    wireless-tools \
    wpa-supplicant \
    netperf \
    usbutils \
    i2c-tools \
    devmem2 \
    e2fsprogs \
    "
