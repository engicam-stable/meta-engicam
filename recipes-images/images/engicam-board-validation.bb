DESCRIPTION = "Engicam image for hardware test"

LICENSE = "MIT"

require recipes-fsl/images/fsl-image-multimedia.bb

EXTRA_IMAGE_FEATURES = " debug-tweaks splash ssh-server-openssh tools-debug tools-testapps hwcodecs "

IMAGE_INSTALL_append = " \
  \
  alsa-state \	
  alsa-tools \
  alsa-utils \
  \
  binutils \
  bzip2 \
  \
  cantest \
  coreutils \
  cpufrequtils \
  \
  devmem2 \
  dosfstools \
  \
  e2fsprogs \
  e2fsprogs-mke2fs \
  engicam-emmc-script \
  engicam-emmc-tools \
  engicam-mtd-script \
  ethtool \
  evtest \
  \
  fbset \
  fsl-alsa-plugins \
  \
  gzip \
  \
  i2c-tools \
  imx-kobs \
  imx-test \
  iproute2 \
  iw \
  \
  kmod \
  \
  lprng \
  \
  minicom \
  mtd-utils \
  mtd-utils-ubifs \
  \
  opkg \
  \
  parted \
  psplash \
  \
  rng-tools \
  \
  serialtools \
  \
  tar \
  test-sound \
  tslib \
  tslib-calibrate \	
  tslib-conf \
  tslib-tests \
  \
  usbutils \
  util-linux \
  \
  v4l-utils \
  \
  wpa-supplicant \
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

