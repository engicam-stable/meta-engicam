SUMMARY = "U-Boot bootloader fw_printenv/setenv utilities"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=c7383a594871c03da76b3707929d2919"
SECTION = "bootloader"
DEPENDS = "mtd-utils"


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

S = "${WORKDIR}/git"

INSANE_SKIP_${PN} = "already-stripped"
EXTRA_OEMAKE_class-target = 'CROSS_COMPILE=${TARGET_PREFIX} CC="${CC} ${CFLAGS} ${LDFLAGS}" V=1'
EXTRA_OEMAKE_class-cross = 'ARCH=${TARGET_ARCH} CC="${CC} ${CFLAGS} ${LDFLAGS}" V=1'



inherit uboot-config

do_compile () {
	oe_runmake ${UBOOT_MACHINE}
	oe_runmake env
}

do_install () {
	install -d ${D}${base_sbindir}
	install -d ${D}${sysconfdir}
	install -m 755 ${S}/tools/env/fw_printenv ${D}${base_sbindir}/fw_printenv
	install -m 755 ${S}/tools/env/fw_printenv ${D}${base_sbindir}/fw_setenv
	install -m 0644 ${S}/tools/env/fw_env.config ${D}${sysconfdir}/fw_env.config
}

do_install_class-cross () {
	install -d ${D}${bindir_cross}
	install -m 755 ${S}/tools/env/fw_printenv ${D}${bindir_cross}/fw_printenv
	install -m 755 ${S}/tools/env/fw_printenv ${D}${bindir_cross}/fw_setenv
}

SYSROOT_PREPROCESS_FUNCS_class-cross = "uboot_fw_utils_cross"
uboot_fw_utils_cross() {
	sysroot_stage_dir ${D}${bindir_cross} ${SYSROOT_DESTDIR}${bindir_cross}
}

PACKAGE_ARCH = "${MACHINE_ARCH}"
BBCLASSEXTEND = "cross"
