
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

require recipes-kernel/linux/linux-imx.inc
require recipes-kernel/linux/linux-dtb.inc

DEPENDS += "lzop-native bc-native"

# Put a local version until we have a true SRCREV to point to
SRC_URI = "git://github.com/engicam-stable/engicam-kernel-4.1.15.git;protocol=git;branch=som_release \
           file://defconfig"

SRCREV = "bc1a744f912d058e300c93f7031eb8bd432e2145"

S = "${WORKDIR}/git"

# We need to pass it as param since kernel might support more then one
# machine, with different entry points
#KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"

KERNEL_EXTRA_ARGS_mx6 += "LOADADDR=0x10008000"

KERNEL_EXTRA_ARGS_mx6ul += "LOADADDR=0x80008000"

COMPATIBLE_MACHINE = "(mx6|mx6ul)"

LINUX_VERSION_EXTENSION="-engicam"
