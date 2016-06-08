SUMMARY = "Add autodetect nand size"
DESCRIPTION = "This package provides a script autodetect for nand auto size"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"


SRC_URI = "file://S98Fwgetsize.sh \
	   file://copyright"


do_install () {
	install -d ${D}${sysconfdir}
	install -d ${D}${sysconfdir}/rcS.d
	install -m 0644 ${WORKDIR}/S98Fwgetsize.sh  ${D}${sysconfdir}/rcS.d/
}

