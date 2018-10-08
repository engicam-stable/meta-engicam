DESCRIPTION = "Engicam image with QT5 demo image for Frame Buffer"

LICENSE = "MIT"

inherit core-image
inherit distro_features_check
inherit populate_sdk
inherit populate_sdk_${@bb.utils.contains('MACHINEOVERRIDES', 'icoremx6', 'qt5_icore', 'qt5_geam6ul', d)}

EXTRA_IMAGE_FEATURES = " debug-tweaks ssh-server-openssh tools-debug \
			"
IMAGE_INSTALL_append  = " \
	qtbase-dev \
	qtbase-mkspecs \
	qtbase-plugins \
	qtbase-staticdev \
	packagegroup-qt5-eng-qtcreator-debug \
	qtimageformats-plugins \
	qtsvg-dev \
	qtsvg-mkspecs \
	qtsvg-plugins \
	qtxmlpatterns-dev \
	qtxmlpatterns-mkspecs \
	engicam-emmc-script \
	tslib \
	evtest \
	tslib-conf \
	tslib-tests \
	tslib-calibrate \
	packagegroup-fonts-truetype \
	binutils \
	psplash \
	engicam-mtd-script \
	mtd-utils imx-kobs mtd-utils-ubifs \
	qtimageformats-dev \
	u-boot-eng-fw-utils \
	opkg \
"

###############RECIPES iMX6##########################

IMAGE_INSTALL_append_icoremx6 = " \
  packagegroup-fsl-tools-gpu kernel-module-imx-gpu-viv \
  firmware-imx \
	qtconnectivity-dev \
	qtconnectivity-mkspecs \
	qtconnectivity-qmlplugins \
	qtgraphicaleffects-qmlplugins \
	qtimageformats-plugins \
	qtdeclarative-dev \
	qtdeclarative-mkspecs \
	qtdeclarative-qmlplugins \
	qtdeclarative-staticdev \
	qtscript-dev \
	qtscript-mkspecs \
	qtmultimedia \
	packagegroup-fsl-gstreamer1.0-full \
	${@bb.utils.contains('STARTUPDEMO', 'resistive', ' democard engicam-startup-demo-resistive', '', d)} \
	${@bb.utils.contains('STARTUPDEMO', 'capacitive', ' democard engicam-startup-demo-capacitive', '', d)} \
"

############################################

###############RECIPES iMX6SX##########################

IMAGE_INSTALL_append_icoremx6sx = " \
  firmware-imx \
	qtconnectivity-dev \
	qtconnectivity-mkspecs \
	qtconnectivity-qmlplugins \
	qtgraphicaleffects-qmlplugins \
	qtimageformats-plugins \
	qtdeclarative-dev \
	qtdeclarative-mkspecs \
	qtdeclarative-qmlplugins \
	qtdeclarative-staticdev \
	qtscript-dev \
	qtscript-mkspecs \
	qtmultimedia \
	${@bb.utils.contains('STARTUPDEMO', 'resistive', ' democard engicam-startup-demo-resistive', '', d)} \
	${@bb.utils.contains('STARTUPDEMO', 'capacitive', ' democard engicam-startup-demo-capacitive', '', d)} \
"

###############RECIPES GEAM6UL##############

#PACKAGES QT
IMAGE_INSTALL_append_gea = " \
  qtquick1 \
	${@bb.utils.contains('STARTUPDEMO', 'capacitive', ' demogeam6ul engicam-startup-demogeam6ul-cap', '', d)} \
	${@bb.utils.contains('STARTUPDEMO', 'resistive', ' demogeam6ul engicam-startup-demogeam6ul', '', d)} \
"
#PACKAGES QT
IMAGE_INSTALL_append_isiot = " \
	qtgraphicaleffects \
	qtimageformats-dev \
  qtquick1 \
	${@bb.utils.contains('STARTUPDEMO', 'capacitive', ' demogeam6ul engicam-startup-demogeam6ul-cap', '', d)} \
	${@bb.utils.contains('STARTUPDEMO', 'resistive', ' demogeam6ul engicam-startup-demogeam6ul', '', d)} \
"

IMAGE_INSTALL_remove ="qt3d nativesdk-qt3d qt3d-native ruby-native"

IMAGE_INSTALL_remove_gea  += "qtdeclarative-plugins"

export IMAGE_BASENAME = "engicam-demo-qt"
