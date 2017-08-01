DESCRIPTION = "hydrophenia demo app"

SECTION = "applications"
LICENSE = "CLOSED"

DEPENDS += "qtquick1 qtbase qtdeclarative "

SRC_URI = " \
	file://demogeam6ul-1.0 \	
"

inherit qmake5

EXTRA_QMAKEVARS_PRE = "CONFIG+=release"

FILES_${PN} += "/usr/bin/demo6ul"

do_install () {
          install -d ${D}/usr/bin
          install -m 0755 ${WORKDIR}/build/demo6ul ${D}/usr/bin
}

RDEPENDS_${PN} = "qtdeclarative-qmlplugins "
