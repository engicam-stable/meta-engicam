require core-image-minimal.bb

DESCRIPTION = "Engicam dev Image Frame Buffer Image QT5 with WebKit included"

inherit populate_sdk populate_sdk_qt5
 
IMAGE_INSTALL_append = " \
    firmware-imx-vpu-imx6q \
    firmware-imx-vpu-imx6d \
"
 
IMAGE_OVERHEAD_FACTOR = "2.0"

export IMAGE_BASENAME = "engicam-dev-fb-webqt5"

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
    qtwebkit \
    qtwebkit-qmlplugins \
    qtwebengine \
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
    ruby \
    cpufrequtils \
    qt3d \
    qt3d-examples \
    qt3d-qmlplugins \
    qt3d-tools \    
    qtlocation-plugins \
    qtlocation-qmlplugins \    
    "

DISTRO_FEATURES_remove = "x11 wayland"
PACKAGECONFIG_remove = " x11 wayland"

 
