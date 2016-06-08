
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel fsl-kernel-localversion
require recipes-kernel/linux/linux-dtb.inc

DEPENDS += "lzop-native bc-native"

# Put a local version until we have a true SRCREV to point to

SRC_URI = "git://github.com/engicam-stable/engicam-kernel-icore-3.14.28.git;protocol=git \
           file://defconfig \
"

SRCREV = "4505954f1d8a7c0e64f3670b51f4138e5c5c5175"

S = "${WORKDIR}/git"

# We need to pass it as param since kernel might support more then one
# machine, with different entry points
KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"

SRC_URI_append_mx6sxm4 += "file://0001-M4-App-On-DDR.patch \
	file://defconfig"

COMPATIBLE_MACHINE = "(mx6)"
