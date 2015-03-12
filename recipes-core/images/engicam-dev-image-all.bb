DESCRIPTION = "Engicam dev Image Frame Buffer Image QT5"

LICENSE = "MIT"

inherit core-image
 
IMAGE_INSTALL_append = " \
    firmware-imx-vpu-imx6q \
    firmware-imx-vpu-imx6d \
"
 
IMAGE_OVERHEAD_FACTOR = "2.0"

export IMAGE_BASENAME = "engicam-dev-image-all"

EXTRA_IMAGE_FEATURES = "debug-tweaks ssh-server-openssh "

IMAGE_INSTALL_append = " binutils libgcc libstdc++ \
ccache chkconfig glib-networking glibmm \
packagegroup-core-buildessential pkgconfig  \
boost cmake zlib glib-2.0 glive \
    packagegroup-qt5-qtcreator-debug \    
    cpufrequtils \
    gdb \
    gstreamer \
    gst-meta-video \
    gst-fsl-plugin \
    gst-plugins-base-app \
    gst-plugins-base \
    gst-plugins-good \
    gst-plugins-good-rtsp \
    gst-plugins-good-udp \
    gst-plugins-good-rtpmanager \
    gst-plugins-good-rtp \
    gst-plugins-good-video4linux2 \
    openssh-sftp-server \
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
    qtsvg \
    qtsvg-plugins \
    qtimageformats-plugins \
    qtsystems \
    qtsystems-tools \
    qtsystems-examples \
    qtsystems-qmlplugins \
    qtscript \
    qtgraphicaleffects-qmlplugins \
    qtconnectivity-qmlplugins \
    cairo pango fontconfig freetype pulseaudio dbus \
    alsa-lib alsa-tools alsa-state alsa-utils-alsaconf fsl-alsa-plugins \
    tslib evtest tslib-conf tslib-tests tslib-calibrate \
    i2c-tools \ 
    default-psw \
    engicam-startup-demo \ 
    engicam-mtd-script \
    engicam-emmc-script \
    psplash \
    iproute2 \
    cantest \
	mtd-utils imx-kobs mtd-utils-ubifs \
    "


IMAGE_INSTALL += " \
    packagegroup-fsl-gstreamer \
    packagegroup-fsl-gstreamer-streamer \
    packagegroup-fsl-tools-testapps \
    packagegroup-fsl-tools-benchmark \
    gpu-viv-bin-mx6q \
    libfslcodec \
    libfslparser \
    libfslvpuwrap \
    firmware-imx \
    imx-lib \
"	

CORE_IMAGE_EXTRA_INSTALL += " \
    packagegroup-fsl-gstreamer-full \
"

DISTRO_FEATURES_remove = "x11 wayland"
