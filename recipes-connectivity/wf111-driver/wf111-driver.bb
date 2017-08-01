DESCRIPTION = "WF111 driver and bin utils"
SECTION = "wireless driver"
LICENSE = "CLOSED"

INSANE_SKIP_${PN} = "already-stripped"
DEPENDS += "imx-test"


SRC_URI = " \
	file://wf111-linux-driver-5.2.2-r2-armv7-a.tar.gz \	
"

do_compile () {
    cd ${WORKDIR}/wf111-linux-driver_5.2.2-r2_armv7-a    
    unset LDFLAG    
    echo ${EXTRA_CFLAGS}
    make install_static KDIR=${STAGING_KERNEL_BUILDDIR} ARCH=arm  CROSS_COMPILE=arm-poky-linux-gnueabi-
}

do_install (){
	install -d ${D}
	cp -rf ${WORKDIR}/wf111-linux-driver_5.2.2-r2_armv7-a/output/* ${D}
} 


FILES_${PN} = "/usr/* \
		/lib* "



