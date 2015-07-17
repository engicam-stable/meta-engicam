DESCRIPTION = "Engicam image with QT5 demo image for Frame Buffer"

LICENSE = "MIT"

inherit core-image

IMAGE_FSTYPES = "tar.bz2 sdcard ubifs"

EXTRA_IMAGE_FEATURES = "debug-tweaks ssh-server-openssh tools-debug"

IMAGE_INSTALL_append = " \
    firmware-imx-vpu-imx6q \
"
IMAGE_INSTALL_append = " \
    binutils \   
    qtbase-dev \
    qtbase-fonts \
    qtbase-mkspecs \
    qtbase-plugins \
    qtbase-staticdev \
    qtconnectivity-dev \
    qtconnectivity-mkspecs \
    qtconnectivity-qmlplugins \
    qtdeclarative-dev \
    qtdeclarative-mkspecs \
    qtdeclarative-plugins \
    qtdeclarative-qmlplugins \
    qtdeclarative-staticdev \
    qtenginio-dev \
    qtenginio-mkspecs \
    qtenginio-qmlplugins \
    qtgraphicaleffects-qmlplugins \
    qtimageformats-dev \
    qtimageformats-plugins \
    qtscript-dev \
    qtscript-mkspecs \
    qtsvg-dev \
    qtsvg-mkspecs \
    qtsvg-plugins \
    qtxmlpatterns-dev \
    qtxmlpatterns-mkspecs \
    tslib evtest tslib-conf tslib-tests tslib-calibrate \
    init-ifupdown \
    default-psw \
    psplash \
    engicam-startup-demo \ 
    engicam-qtdemo \
    engicam-mtd-script \
    engicam-emmc-script \
    fw-nandautosize \
    u-boot-fw-utils \
    iproute2 \
    canutils \
    cantest \
    mtd-utils imx-kobs mtd-utils-ubifs \
    e2fsprogs \
    "

export IMAGE_BASENAME = "engicam-demo-qt"
 

