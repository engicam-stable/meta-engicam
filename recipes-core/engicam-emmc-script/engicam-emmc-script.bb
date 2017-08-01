SUMMARY = "Basic script for emmc programmig for RQSq7 modules"
DESCRIPTION = "This package provides basic script for Engicam RQSq7 modules"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"

inherit allarch

SRC_URI = "file://tftp_rqs_sdcard.sh \
	   file://tftp_rqs_boot.sh \
	   file://tftp_rqsdl_kernel.sh \
	   file://tftp_rqsq_kernel.sh \
	   file://tftp_rqs_fs.sh \
	   file://copyright"



do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/tftp_rqs_sdcard.sh ${D}${bindir}/tftp_rqs_sdcard.sh
	install -m 0755 ${WORKDIR}/tftp_rqs_boot.sh ${D}${bindir}/tftp_rqs_boot.sh 
	install -m 0755 ${WORKDIR}/tftp_rqsdl_kernel.sh ${D}${bindir}/tftp_rqsdl_kernel.sh 
	install -m 0755 ${WORKDIR}/tftp_rqsq_kernel.sh ${D}${bindir}/tftp_rqsq_kernel.sh
	install -m 0755 ${WORKDIR}/tftp_rqs_fs.sh ${D}${bindir}/tftp_rqs_fs.sh
}



