SUMMARY = "Test EPDC"
DESCRIPTION = "This package provides tools for test EPDC device"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"
PR = "01"
COMPATIBLE_MACHINE = "(epd)"

DEPENDS += "engicam-linux-fslc"

SRC_URI = "file://Makefile \
	   file://copyright \
	   file://90-usb.rules \
	   file://launch.sh \
	   file://mxc_epdc_v2_fb_test.c \
	   file://images/* \
         "

do_compile () {
    cd ${WORKDIR}
    oe_runmake V=1 VERBOSE='' \
               CROSS_COMPILE=${TARGET_PREFIX} \
               CFLAGS=" -I${STAGING_KERNEL_DIR}/include/uapi \
                    -I${STAGING_KERNEL_DIR}/include "
}
	   
do_install () {
	install -d ${D}/home
	install -d ${D}/home/root
	install -m 0755 ${WORKDIR}/launch.sh  ${D}/home/root
	install -d ${D}${sysconfdir}
	install -d ${D}${sysconfdir}/udev
	install -d ${D}${sysconfdir}/udev/rules.d
	install -m 0644 ${WORKDIR}/90-usb.rules  ${D}${sysconfdir}/udev/rules.d
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/mxc_epdc_fb_test ${D}${bindir}/mxc_epdc_fb_test
	install -d ${D}${datadir}/engicam
	install ${WORKDIR}/images/image3.jpg ${D}/${datadir}/engicam/image3.jpg
	install ${WORKDIR}/images/image4.jpg ${D}/${datadir}/engicam/image4.jpg
	install ${WORKDIR}/images/image5.png ${D}/${datadir}/engicam/image5.png
	install ${WORKDIR}/images/image6.jpg ${D}/${datadir}/engicam/image6.jpg
	install ${WORKDIR}/images/image7.jpg ${D}/${datadir}/engicam/image7.jpg
	install ${WORKDIR}/images/image8.jpg ${D}/${datadir}/engicam/image8.jpg
	install ${WORKDIR}/images/image9.png ${D}/${datadir}/engicam/image9.png
}

FILES_${PN} += "${datadir}/engicam "
FILES_${PN} += "/home/root "

