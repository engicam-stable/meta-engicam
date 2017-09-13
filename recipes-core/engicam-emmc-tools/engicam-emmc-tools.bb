SUMMARY = "Tools for emmc programmig"
DESCRIPTION = "This package provides tools for emmc programmig"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"

inherit allarch

SRC_URI = "file://emmc_tools.sh \
	   file://copyright"
	   
RDEPENDS_${PN} += "bash dosfstools e2fsprogs pv"

do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/emmc_tools.sh ${D}${bindir}/emmc_tools.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_fs.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_fs_ker_dtb.sh
  ln -sf emmc_tools.sh ${D}${bindir}/emmc_fs_ker.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_ker.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_ker_dtb.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_dtb.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_boot.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_fs_tftp.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_ker_dtb_tftp.sh
  ln -sf emmc_tools.sh ${D}${bindir}/emmc_fs_ker_tftp.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_fs_ker_dtb_tftp.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_ker_tftp.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_dtb_tftp.sh
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_boot_tftp.sh	
	ln -sf emmc_tools.sh ${D}${bindir}/emmc_sdcard.sh
}
