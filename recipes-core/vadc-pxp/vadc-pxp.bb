SUMMARY = "Serial tools for hardware debug"
DESCRIPTION = "This package provides tools for test camera with vadc for iMX 6SoloX"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/copyright;md5=3dd6192d306f582dee7687da3d8748ab"
PR = "01"
COMPATIBLE_MACHINE = "(mx6sx)"
DEPENDS_mx6sx = "virtual/kernel imx-lib"

SRC_URI = "file://Makefile \
	   file://copyright \
	   file://vadc_pxp.c"

do_compile () {
    cd ${WORKDIR}
    oe_runmake V=1 VERBOSE='' \
               CROSS_COMPILE=${TARGET_PREFIX} \
               CFLAGS=" -I${STAGING_KERNEL_DIR}/include/uapi \
                    -I${STAGING_KERNEL_DIR}/include "
}
	   
do_install () {
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/vadc_pxp ${D}${bindir}/vadc_pxp
}



