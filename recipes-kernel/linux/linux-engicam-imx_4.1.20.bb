
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

require recipes-kernel/linux/linux-imx.inc
require recipes-kernel/linux/linux-dtb.inc

DEPENDS += "lzop-native bc-native"

# Put a local version until we have a true SRCREV to point to
SRC_URI = "git://github.com/engicam-stable/engicam-4.1-2.0.x-imx.git;protocol=git;branch=master \
           file://defconfig"

SRCREV = "2a95ccc81bad0ae53e5d3de94367b3cd6c67322f"

S = "${WORKDIR}/git"

# We need to pass it as param since kernel might support more then one
# machine, with different entry points
#KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"

KERNEL_EXTRA_ARGS_mx6 += "LOADADDR=0x10008000"

KERNEL_EXTRA_ARGS_mx6ull += "LOADADDR=0x80008000"

COMPATIBLE_MACHINE = "(mx6|mx6ull)"

LINUX_VERSION_EXTENSION="-engicam"
