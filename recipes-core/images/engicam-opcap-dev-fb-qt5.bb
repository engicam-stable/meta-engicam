DESCRIPTION = "Engicam dev Image Frame Buffer Image QT5"

LICENSE = "MIT"

inherit core-image populate_sdk populate_sdk_qt5
 
IMAGE_INSTALL_append = " \
    firmware-imx-vpu-imx6q \
    firmware-imx-vpu-imx6d \
"
 
IMAGE_OVERHEAD_FACTOR = "2.0"

export IMAGE_BASENAME = "engicam-opcap-dev-fb-qt5"

SOC_IMAGE_INSTALL_mx6 += "gpu-viv-bin-mx6q gpu-viv-g2d fsl-gpu-sdk"
EXTRA_IMAGE_FEATURES += "debug-tweaks ssh-server-openssh tools-debug"

IMAGE_INSTALL_append = " binutils libgcc libstdc++ \
    ${SOC_IMAGE_INSTALL} \
    ccache chkconfig glib-networking glibmm \
    packagegroup-core-buildessential pkgconfig  \
    boost cmake zlib glib-2.0 glive \
    cpufrequtils \
    gdb \
    gstreamer \
    gst-meta-video \
    gst-fsl-plugin \
    gst-plugins-base-app \
    gst-plugins-base \
    gst-plugins-good \
    gst-plugins-good-video4linux2 \
    packagegroup-fsl-gstreamer \
    imx-vpu \
    imx-test \    	
    qtbase-fonts \
    qtbase-plugins \
    qtbase-tools \
    qtbase-examples \
    qtdeclarative \
    qtdeclarative-plugins \
    qtdeclarative-tools \
    qtdeclarative-examples \
    qtdeclarative-qmlplugins \
    qtmultimedia \
    qtmultimedia-plugins \
    qtmultimedia-examples \
    qtmultimedia-qmlplugins \
    qtwebkit \
    qtsvg \
    qtquick1 \
    qtsvg-plugins \
    qtimageformats-plugins \
    qtscript \
    qtgraphicaleffects-qmlplugins \
    cairo pango fontconfig freetype pulseaudio dbus \
    alsa-lib alsa-tools alsa-state alsa-utils-alsaconf fsl-alsa-plugins \
    evtest \
    i2c-tools \ 
    default-psw \
    engicam-mtd-script \
    engicam-emmc-script \
    fw-nandautosize \
    u-boot-fw-utils \
    psplash \
    iproute2 \
    cantest \
    mtd-utils imx-kobs mtd-utils-ubifs \
    packagegroup-qt5-qtcreator-debug \
    packagegroup-qt5-toolchain-target \
    "

DISTRO_FEATURES_remove = "x11 wayland"
