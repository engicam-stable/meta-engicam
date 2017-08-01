SUMMARY = "Basic script for mtd programming"
DESCRIPTION = "This package provides basic script for mtd programming"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=608bed987af1b677f1378e29e4878154"

inherit allarch

#DEPENDS += "u-boot-eng-fw-utils"

SRC_URI = "file://prboot.sh \
           file://prfs.sh \
           file://prkernel.sh \
           file://tftp_boot.sh \
           file://tftp_kernel.sh \
           file://tftp_fs.sh \
           file://fw_savenv.sh \
	         file://copyright"

do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/prboot.sh ${D}${bindir}/prboot.sh
	install -m 0755 ${WORKDIR}/prfs.sh ${D}${bindir}/prfs.sh
	install -m 0755 ${WORKDIR}/prkernel.sh ${D}${bindir}/prkernel.sh
	install -m 0755 ${WORKDIR}/tftp_boot.sh ${D}${bindir}/tftp_boot.sh
	install -m 0755 ${WORKDIR}/tftp_kernel.sh ${D}${bindir}/tftp_kernel.sh
	install -m 0755 ${WORKDIR}/tftp_fs.sh ${D}${bindir}/tftp_fs.sh
	install -m 0755 ${WORKDIR}/fw_savenv.sh ${D}${bindir}/fw_savenv.sh
}
