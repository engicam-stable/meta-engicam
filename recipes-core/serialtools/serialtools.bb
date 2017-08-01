SUMMARY = "Serial tools for hardware debug"
DESCRIPTION = "This package provides basic tools for serial debugging"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"
SECTION = "console/tools"
DEPENDS = "virtual/kernel"
PR = "r1"

SRC_URI = "file://Makefile \
           file://serial_lib.c \
           file://serial_lib.h \
           file://test_gps.c \
           file://test_serial.c \
           file://test_serial2.c \           
	   file://copyright"

do_compile () {
    cd ${WORKDIR}
    make 
}

do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/test_serial ${D}${bindir}/test_serial
	install -m 0755 ${WORKDIR}/test_serial2 ${D}${bindir}/test_serial2
	install -m 0755 ${WORKDIR}/test_gps ${D}${bindir}/test_gps
}

FILES_${PN} = "${bindir}/*"
INSANE_SKIP_${PN} = "ldflags"



