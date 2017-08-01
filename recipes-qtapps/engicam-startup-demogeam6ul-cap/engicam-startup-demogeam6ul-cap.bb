SUMMARY = "add default root passwd"
DESCRIPTION = "This package provides to add add default root passwd"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"


SRC_URI = "file://S99StartUpEngicam.sh \
	   file://copyright"


do_install () {
	install -d ${D}${sysconfdir}
	install -d ${D}${sysconfdir}/rcS.d
	install -m 0777 ${WORKDIR}/S99StartUpEngicam.sh  ${D}${sysconfdir}/rcS.d/
}

FILES_${PN} = "/etc/rcS.d"


