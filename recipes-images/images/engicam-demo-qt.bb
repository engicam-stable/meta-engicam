DESCRIPTION = "Engicam image with QT5 demo image for Frame Buffer"

LICENSE = "MIT"

inherit core-image
inherit distro_features_check
inherit populate_sdk_qt5


IMAGE_FEATURES += "dev-pkgs"

EXTRA_IMAGE_FEATURES = " debug-tweaks ssh-server-openssh tools-debug \
			"
IMAGE_INSTALL_append  = " \
	qtbase-dev \
	qtbase-mkspecs \
	qtbase-plugins \
	qtbase-staticdev \
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
	u-boot-engicam-fw-utils \
	opkg \
"

IMAGE_INSTALL_append_microdev = " \
	democard \
"


IMAGE_INSTALL_append_microdev = " \
	engicam-microdev-startup \
	bluez5 \
	brcm-patchram-plus \
	obexftp \
	hostapd \
	ppp \
	lwb-backports-laird \
	lwb-bcm4343w-fw \
"


IMAGE_INSTALL_remove ="qt3d nativesdk-qt3d qt3d-native ruby-native"

IMAGE_INSTALL_remove_microdev  += "qtdeclarative-plugins"

export IMAGE_BASENAME = "engicam-demo-qt"
