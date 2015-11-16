DESCRIPTION = "Engicam image with QT5 demo image for Frame Buffer"

LICENSE = "MIT"

inherit core-image
inherit distro_features_check
#inherit populate_sdk populate_sdk_qt5

IMAGE_FSTYPES = "tar.bz2 sdcard ubifs"

EXTRA_IMAGE_FEATURES = "debug-tweaks ssh-server-openssh tools-debug"

IMAGE_INSTALL_append_mx6 = " \
    firmware-imx-vpu-imx6q \
"
IMAGE_INSTALL_append_mx6 = " \
    packagegroup-qt5-qtcreator-debug \    
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
    qtsvg-dev \
    qtsvg-mkspecs \
    qtsvg-plugins \
    qtxmlpatterns-dev \
    qtxmlpatterns-mkspecs \
    tslib evtest tslib-conf tslib-tests tslib-calibrate \
    psplash \
    engicam-startup-demo \ 
    engicam-qtdemo \
    engicam-mtd-script \
    engicam-emmc-script \
    iproute2 \
    canutils \
    cantest \
    mtd-utils imx-kobs mtd-utils-ubifs \
    "
 
IMAGE_INSTALL_append_mx6ul = " \
    packagegroup-qt5-qtcreator-debug \    
    binutils \   
    qtbase-dev \
    qtbase-fonts \
    qtbase-mkspecs \
    qtbase-plugins \
    qtbase-staticdev \
    qtimageformats-dev \
    qtimageformats-plugins \
    qtsvg-dev \
    qtsvg-mkspecs \
    qtsvg-plugins \
    tslib evtest tslib-conf tslib-tests tslib-calibrate \
    psplash \
    engicam-mtd-script \
    engicam-emmc-script \
    mtd-utils imx-kobs mtd-utils-ubifs \
    qwt-6ul \
    hydrophenia \
    engicam-startup-hydrophenia \
    "

export IMAGE_BASENAME = "engicam-demo-qt"
 
#    qtscript-dev 
#    qtscript-mkspecs 
