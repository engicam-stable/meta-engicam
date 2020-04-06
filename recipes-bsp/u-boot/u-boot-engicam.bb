# Copyright (C) 2013-2016 Freescale Semiconductor
# Copyright 2017-2019 NXP

DESCRIPTION = "i.MX U-Boot suppporting Engicam boards."

require u-boot.inc
inherit pythonnative
require u-boot-common.inc

PROVIDES += "u-boot"

DEPENDS_append = " python dtc-native"
DEPENDS += "flex-native bison-native"

S = "${WORKDIR}/git"

inherit fsl-u-boot-localversion

LOCALVERSION ?= "-4.19.35-1.1.0"

BOOT_TOOLS = "imx-boot-tools"

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(mx6)"

UBOOT_NAME_mx6 = "u-boot-${MACHINE}.bin-${UBOOT_CONFIG}"
