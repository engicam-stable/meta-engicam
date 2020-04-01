# Copyright (C) 2013-2016 Freescale Semiconductor
# Copyright 2017-2019 NXP

DESCRIPTION = "i.MX U-Boot suppporting Engicam boards."

require u-boot.inc
inherit pythonnative

PROVIDES += "u-boot"

DEPENDS_append = " python dtc-native"
DEPENDS += "flex-native bison-native"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/gpl-2.0.txt;md5=b234ee4d69f5fce4486a80fdaf4a4263"

UBOOT_SRC ?= "git://github.com/engicam-stable/u-boot-engicam_2019.04.git;protocol=https"
SRCBRANCH = "u-boot-engicam_2019.04_4.19.35"
SRC_URI = "${UBOOT_SRC};branch=${SRCBRANCH}"
SRCREV = "7a1bb26d428d10b803f155eba9076f834cf2efe9"

S = "${WORKDIR}/git"

inherit fsl-u-boot-localversion

LOCALVERSION ?= "-4.19.35-1.1.0"

BOOT_TOOLS = "imx-boot-tools"

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(mx6)"

UBOOT_NAME_mx6 = "u-boot-${MACHINE}.bin-${UBOOT_CONFIG}"
