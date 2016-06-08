
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel fsl-kernel-localversion
require recipes-kernel/linux/linux-dtb.inc

DEPENDS += "lzop-native bc-native"

# Put a local version until we have a true SRCREV to point to

SRC_URI = "git://github.com/engicam-stable/engicam-kernel-geam6ul-3.14.38.git;protocol=git \
           file://defconfig \
"

SRCREV = "40fdd5a781bf0c592c291c1db79f1b821cc61de1"

S = "${WORKDIR}/git"

# We need to pass it as param since kernel might support more then one
# machine, with different entry points
KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"


COMPATIBLE_MACHINE = "(mx6ul)"
