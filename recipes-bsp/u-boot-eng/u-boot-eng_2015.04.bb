# Copyright (C) 2012-2014 O.S. Systems Software LTDA.
# Released under the MIT license (see COPYING.MIT for the terms)

require recipes-bsp/u-boot/u-boot.inc

DESCRIPTION = "U-Boot based on mainline U-Boot used by FSL Community BSP in \
order to provide support for some backported features and fixes, or because it \
was submitted for revision and it takes some time to become part of a stable \
version, or because it is not applicable for upstreaming."
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=c7383a594871c03da76b3707929d2919"

PROVIDES += "u-boot"

SRCBRANCH ??= "imx_v2015.04_3.14.38_6ul_ga"

SRCREV = "5d63276bfebc82cffa10d66ddaa903dd2ab0df43"

SRC_URI = "git://git.freescale.com/imx/uboot-imx.git;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"


inherit fsl-u-boot-localversion

LOCALVERSION ?= "-${SRCBRANCH}"

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(mx6|mx6ul|mx7)"

SRC_URI += "file://0001-Added-GEA-M6UL-support.patch"
SRC_URI += "file://0002-geam6ul-enet0-tested.patch"
SRC_URI += "file://0003-geam6ul-configured-audio-mclk-for-sgtl5000.patch"
SRC_URI += "file://0004-only-sdhc1-configured-for-geam6ul.patch"
SRC_URI += "file://0005-geam6ul_added_config_for_nand_and_sd.patch"
SRC_URI += "file://0006-Added-i.Core-SoloX-support-EDIMM-and-SMARC.patch"
SRC_URI += "file://0007-Added-icoreM6-edimm-som-support.patch"
SRC_URI += "file://0008-fix-fdt_addr-for-imx6qdl-and-default-dtb-name.patch"
SRC_URI += "file://0009-fix-icorem6-fdt-varable.patch"
SRC_URI += "file://0010-custom-logo.patch"
SRC_URI += "file://0011-add-UBIFS-command-to-geam6ul.patch"
SRC_URI += "file://0012-fix-fdt_address-for-icorem6sx.patch"
SRC_URI += "file://0013-fix-uboot-env-geam6ul.patch"
SRC_URI += "file://Engicam.bmp"


do_patch_prepend() {
    os.system("mv ${S}/../Engicam.bmp ${S}/tools/logos/");
}



