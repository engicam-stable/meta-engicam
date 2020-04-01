HOMEPAGE = "http://www.denx.de/wiki/U-Boot/WebHome"
SECTION = "bootloaders"
DEPENDS += "flex-native bison-native"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=30503fd321432fc713238f582193b78e"
PE = "1"

# We use the revision in order to avoid having to fetch it from the
# repo during parse
SRCREV = "20dff7f1818ce17c7ee7723a1ad00454c22f23d7"

UBOOT_SRC = "git://github.com/engicam-stable/u-boot-engicam_2019.04.git;protocol=https"
SRCBRANCH = "u-boot-engicam_2019.04_4.19.35"
SRC_URI = "${UBOOT_SRC};branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
