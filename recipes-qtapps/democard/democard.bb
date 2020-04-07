DESCRIPTION = "DemoCard App"

SECTION = "applications"
LICENSE = "CLOSED"

DEPENDS += "qtbase qtdeclarative"
RDEPENDS_${PN} = "qtdeclarative-qmlplugins qtgraphicaleffects"

SRC_URI = " \
	file://democard-1.0 \
	file://demo.service \
"

inherit qmake5 systemd

EXTRA_QMAKEVARS_PRE = "CONFIG+=release"

FILES_${PN} += "/usr/bin/democard"
FILES_${PN} += "/lib/systemd/system"

do_install () {
          install -d ${D}/usr/bin
          install -m 0755 ${WORKDIR}/build/democard ${D}/usr/bin

					install -d ${D}/lib/systemd/system
					install -m 0644 ${WORKDIR}/demo.service ${D}/lib/systemd/system
}

SYSTEMD_SERVICE_${PN} = "demo.service"

REQUIRED_DISTRO_FEATURES= "systemd"
