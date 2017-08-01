DESCRIPTION = "test touch qt based"

SECTION = "applications"
LICENSE = "CLOSED"

DEPENDS += "qtquick1 qtbase qtdeclarative "

SRC_URI = " \
	file://qt-test-touch-mx6ul-1.0 \	
"

inherit qmake5

EXTRA_QMAKEVARS_PRE = "CONFIG+=release"

FILES_${PN} += "/usr/bin/TestTouch"

do_install () {
          install -d ${D}/usr/bin
          install -m 0755 ${WORKDIR}/build/TestTouch ${D}/usr/bin
}

RDEPENDS_${PN} = "qtdeclarative-qmlplugins "
