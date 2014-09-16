SUMMARY = "Basic script for mtd programming"
DESCRIPTION = "This package provides basic script for mtd programming"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"

inherit allarch

SRC_URI = "file://prboot.sh \
           file://prfs.sh \
           file://prkernel.sh \
           file://tftp_boot.sh \
           file://tftp_kernel.sh \
	   file://copyright"



do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/prboot.sh ${D}${bindir}/prboot.sh 
	install -m 0755 ${WORKDIR}/prfs.sh ${D}${bindir}/prfs.sh 
	install -m 0755 ${WORKDIR}/prkernel.sh ${D}${bindir}/prkernel.sh 
	install -m 0755 ${WORKDIR}/tftp_boot.sh ${D}${bindir}/tftp_boot.sh 
	install -m 0755 ${WORKDIR}/tftp_kernel.sh ${D}${bindir}/tftp_kernel.sh
}



