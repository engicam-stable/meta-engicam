SUMMARY = "Basic script for mtd programming"
DESCRIPTION = "This package provides basic script for mtd programming"
LICENSE = "CLOSED"

inherit allarch

SRC_URI = "file://ring.wav \
           file://megamix_lr.wav \
	   file://playring.sh \
	   file://playleftright.sh \
	"

do_install () {
	install -d ${D}/testfiles
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/ring.wav ${D}/testfiles/ring.wav 
	install -m 0755 ${WORKDIR}/megamix_lr.wav  ${D}/testfiles/megamix_lr.wav
	install -m 0755 ${WORKDIR}/playring.sh ${D}${bindir}/playring.sh 
	install -m 0755 ${WORKDIR}/playleftright.sh ${D}${bindir}/playleftright.sh 
}

FILES_${PN} += "testfiles"

