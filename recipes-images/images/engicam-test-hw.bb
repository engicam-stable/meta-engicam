DESCRIPTION = "Engicam image for hardware test"

LICENSE = "MIT"

inherit core-image

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
  wpa-supplicant \
"

IMAGE_INSTALL_append_microdev = " \
	bluez5 \
	obexftp \
	hostapd \
	ppp \
	brcm-patchram-plus \
	lwb-backports-laird \
	lwb-etsi-firmware \
"

