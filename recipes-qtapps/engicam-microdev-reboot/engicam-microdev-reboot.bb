SUMMARY = "RESET modem = 1 after reboot"
DESCRIPTION = "This package provides to RESET modem = 1 after reboot"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"


SRC_URI = "file://S20RebootEngicam.sh \
	   file://copyright"


do_install () {
	install -d ${D}${sysconfdir}
	install -d ${D}${sysconfdir}/rc6.d
	install -m 0755 ${WORKDIR}/S20RebootEngicam.sh  ${D}${sysconfdir}/rc6.d/
}

FILES_${PN} = "/etc/rc6.d"


