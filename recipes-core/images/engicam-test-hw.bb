DESCRIPTION = "Engicam image with QT5 demo image for Frame Buffer"

LICENSE = "MIT"

inherit core-image

IMAGE_FSTYPES = "tar.bz2 sdcard ubifs"

EXTRA_IMAGE_FEATURES = "debug-tweaks ssh-server-openssh tools-debug \
			tools-profile tools-testapps \
			"

IMAGE_INSTALL_append_mx6 = " \
    firmware-imx-vpu-imx6q \
"
IMAGE_INSTALL_append = " \
    binutils \ 
    tslib evtest tslib-conf tslib-tests tslib-calibrate \
    psplash \
    engicam-mtd-script \
    engicam-emmc-script \
    iproute2 \
    canutils \
    cantest \
    mtd-utils imx-kobs mtd-utils-ubifs \
    serialtools \    
    devmem2 \
    i2c-tools \ 
    imx-kobs \
    u-boot-eng-fw-utils \
    fw-nandautosize \  
    alsa-utils \
    alsa-tools \
    alsa-state \
    alsa-lib \
    alsa-utils-alsaconf \
    test-sound \
"
#wf111-driver 
