DESCRIPTION = "Engicam image for hardware test"

LICENSE = "MIT"

inherit core-image

EXTRA_IMAGE_FEATURES = " debug-tweaks ssh-server-openssh tools-debug "


IMAGE_INSTALL_append = " \
	binutils \
	psplash \
	engicam-mtd-script \
	engicam-emmc-script \
	engicam-emmc-tools \
	iproute2 \
	canutils \
	cantest \
	mtd-utils \
	mtd-utils-ubifs \
	serialtools \
	devmem2 \
	i2c-tools \
	imx-kobs \
	test-sound \
	fbset \
	minicom \
	ethtool \
	dosfstools \
	e2fsprogs \
	fsl-alsa-plugins \
	v4l-utils \
	usbutils \
	cpufrequtils \
	iw \
	wpa-supplicant \
	tslib \
	tslib-conf \
	tslib-tests \
	tslib-calibrate \
	evtest \
	alsa-utils \
	alsa-tools \
	alsa-state \
	fbset \
	opkg rng-tools lprng\
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

