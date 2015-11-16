DESCRIPTION = "hydrophenia demo app"

SECTION = "applications"
LICENSE = "CLOSED"

DEPENDS += "qwt-6ul"

SRC_URI = " \
	file://hydrophenia-1.0 \	
"

inherit qmake5
 
EXTRA_QMAKEVARS_PRE = "CONFIG+=release"

FILES_${PN} += "/usr/bin/hydrophenia"

do_install () {
          install -d ${D}/usr/bin
          install -m 0755 ${WORKDIR}/build/hydrophenia ${D}/usr/bin
}

