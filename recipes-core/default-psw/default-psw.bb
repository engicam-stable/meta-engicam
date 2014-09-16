SUMMARY = "add default root passwd"
DESCRIPTION = "This package provides to add add default root passwd"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"


SRC_URI = "file://passwd \
           file://passwd- \
           file://shadow \
           file://shadow- \
           file://gshadow \
           file://gshadow- \
           file://group \
           file://group- \
	   file://copyright"



do_install () {
	install -d ${D}${sysconfdir}
	install -m 0644 ${WORKDIR}/pass* ${D}${sysconfdir}/
	install -m 0644 ${WORKDIR}/shadow* ${D}${sysconfdir}/
	install -m 0644 ${WORKDIR}/gshadow* ${D}${sysconfdir}/
	install -m 0644 ${WORKDIR}/group* ${D}${sysconfdir}/
}



