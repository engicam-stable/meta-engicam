HOMEPAGE = "http://www.denx.de/wiki/U-Boot/WebHome"
SECTION = "bootloaders"
DEPENDS += "flex-native bison-native"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=30503fd321432fc713238f582193b78e"
PE = "1"

SRC_URI = "git://github.com/engicam-stable/u-boot-engicam_2019.04.git;protocol=https;branch=u-boot-engicam_2019.04_4.19.35"

SRCREV = "61cface17cde61f6c4e2b8c40661d10aacc7d989"

S = "${WORKDIR}/git"
