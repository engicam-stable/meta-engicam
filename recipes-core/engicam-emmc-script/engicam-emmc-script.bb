SUMMARY = "Basic script for emmc programmig for RQSq7 modules"
DESCRIPTION = "This package provides basic script for Engicam RQSq7 modules"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"

inherit allarch

SRC_URI = "file://q7_tftp_sdcard.sh \
	   file://q7_tftp_boot.sh \
	   file://q7_tftp_kernel.sh \
	   file://q7_tftp_boot_saveenv.sh \
	   file://smarc_tftp_sdcard.sh \
	   file://smarc_tftp_boot.sh \
	   file://smarc_tftp_kernel.sh \
	   file://smarc_tftp_boot_saveenv.sh \
	   file://copyright"



do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/q7_tftp_sdcard.sh ${D}${bindir}/q7_tftp_sdcard.sh
	install -m 0755 ${WORKDIR}/q7_tftp_boot.sh ${D}${bindir}/q7_tftp_boot.sh 
	install -m 0755 ${WORKDIR}/q7_tftp_kernel.sh ${D}${bindir}/q7_tftp_kernel.sh 
	install -m 0755 ${WORKDIR}/q7_tftp_boot_saveenv.sh ${D}${bindir}/q7_tftp_boot_saveenv.sh
	install -m 0755 ${WORKDIR}/smarc_tftp_boot.sh ${D}${bindir}/smarc_tftp_boot.sh 
	install -m 0755 ${WORKDIR}/smarc_tftp_sdcard.sh ${D}${bindir}/smarc_tftp_sdcard.sh 
	install -m 0755 ${WORKDIR}/smarc_tftp_kernel.sh ${D}${bindir}/smarc_tftp_kernel.sh 
	install -m 0755 ${WORKDIR}/smarc_tftp_boot_saveenv.sh ${D}${bindir}/smarc_tftp_boot_saveenv.sh
}



