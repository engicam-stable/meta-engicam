DESCRIPTION = "Engicam image for hardware test"

LICENSE = "MIT"

inherit core-image

EXTRA_IMAGE_FEATURES = " debug-tweaks ssh-server-openssh tools-debug "

IMAGE_INSTALL_append_mx6 = " \
	firmware-imx-vpu-imx6q \
	firmware-imx-vpu-imx6d \
	gstreamer1.0-plugins-imx \
	packagegroup-fsl-gstreamer1.0-full \
	imx-gst1.0-plugin \
	imx-test \
	wf111-driver \
	wireless-tools \
	wpa-supplicant \
"
IMAGE_INSTALL_append_mx6ul = " \
	wf111-driver \
	wireless-tools \
	wpa-supplicant \
"

IMAGE_INSTALL_remove_mx6sx = " gstreamer1.0-plugins-imx"

IMAGE_INSTALL_append_mx6sx = " vadc-pxp"

IMAGE_INSTALL_append = " \
	binutils \
	psplash \
	engicam-emmc-tools \
	engicam-mtd-script \
	iproute2 \
	canutils \
	cantest \
	mtd-utils \
	mtd-utils-ubifs \
	serialtools \
	devmem2 \
	i2c-tools \
	imx-kobs \
	fw-nandautosize \
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
	lwb-bcm4343w-fw \
	bluez5 \
	brcm-patchram-plus \
	obexftp \
	hostapd \
    	${@base_contains('MACHINE', 'isiot-geamx6ul', 'engicam-isiot-startup', '', d)} \
"

#TSLIB & EVTEST PACKAGES
IMAGE_INSTALL_append = " \
	tslib \
	tslib-conf \
	tslib-tests \
	tslib-calibrate \
	evtest \
"

#ALSA PACKAGES
IMAGE_INSTALL_append = " \
	alsa-lib	\                                    
	alsa-oss	\
	alsa-plugins	\
	alsa-state	\                                         
	alsa-tools	\                                         
	alsa-utils	\                                         
	alsa-utils-scripts	\                                 
	flite-alsa	\                                         
	imx-alsa-plugins	\                                    
"
