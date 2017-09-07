DESCRIPTION = "DemoCard App"

SECTION = "applications"
LICENSE = "CLOSED"

DEPENDS += "qtbase qtdeclarative"
RDEPENDS_${PN} = "qtdeclarative-qmlplugins qtgraphicaleffects"

SRC_URI = " \
	file://democard-1.0 \
"

inherit qmake5

EXTRA_QMAKEVARS_PRE = "CONFIG+=release"

FILES_${PN} += "/usr/bin/democard"

do_install () {
          install -d ${D}/usr/bin
          install -m 0755 ${WORKDIR}/build/democard ${D}/usr/bin
}


