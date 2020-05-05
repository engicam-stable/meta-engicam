SUMMARY = "Root filesystem for swupdate as rescue system"
DESCRIPTION = "Root FS to start swupdate in rescue mode"
LICENSE = "MIT"

inherit core-image

EXTRA_IMAGE_FEATURES = " debug-tweaks ssh-server-openssh tools-debug "

USE_DEVFS = "1"

# This variable is triggered to check if sysvinit must be overwritten by a single rcS
export SYSVINIT = "no"

IMAGE_INSTALL_append = " \
	base-files \
	base-passwd \
	busybox \
	mtd-utils \
	mtd-utils-ubifs \
	dosfstools \
  	e2fsprogs \
	libconfig \
	swupdate \
	util-linux-sfdisk \
	u-boot-fw-utils \
	cpio \
"
set_hwrevision() {
  echo "mx8mmini 1.0" > ${IMAGE_ROOTFS}/etc/hwrevision
}
 
ROOTFS_POSTPROCESS_COMMAND += "set_hwrevision;"

IMAGE_FSTYPES += "ext4.gz ext4.gz.u-boot"