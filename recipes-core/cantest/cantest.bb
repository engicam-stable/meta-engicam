SUMMARY = "Cantest for cansend example on engicam iCoreM6"
DESCRIPTION = "This package provides basic fuction for cantest programming"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"
SECTION = "console/tools"
DEPENDS = "linux-imx"
PR = "r1"

SRC_URI = "file://can.h \
           file://cansend.c \
           file://lib.c \
           file://lib.h \
           file://Makefile \
           file://raw.h \
	   file://copyright"

do_compile () {
    cd ${WORKDIR}
    make 
}

do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/cantest ${D}${bindir}/cantest
}



