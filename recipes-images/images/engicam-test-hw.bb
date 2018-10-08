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
	u-boot-eng-fw-utils \
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
	wireless-tools \
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
	opkg \
"

IMAGE_INSTALL_append_icoremx6 = " \
	firmware-imx-vpu-imx6q \
	gstreamer1.0-plugins-imx \
	packagegroup-fsl-gstreamer1.0-full \
	imx-test \
	wf111-driver \
"

IMAGE_INSTALL_append_isiot = " \
	engicam-isiot-startup \
	lwb-bcm4343w-fw \
	bluez5 \
	brcm-patchram-plus \
	obexftp \
	wf111-driver \
"

IMAGE_INSTALL_append_epd = " \
	epdc-test \
	ffmpeg \
	file \
	firmware-epdc \
	engicam-epd-startup \
	wf111-driver \
"

IMAGE_INSTALL_append_microdev = " \
        lwb-bcm4343w-fw \
        bluez5 \
        brcm-patchram-plus \
        obexftp \
	hostapd \
	ppp \
"

