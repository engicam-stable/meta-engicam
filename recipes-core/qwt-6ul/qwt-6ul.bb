DESCRIPTION = "WF111 driver and bin utils"
SECTION = "wireless driver"
LICENSE = "CLOSED"

INSANE_SKIP_${PN} = "already-stripped"
DEPENDS += "qtsvg"

require recipes-qt/qt5/qt5.inc

SRC_URI = " \
	file://qwt-6.1.2_6ul.tar.bz2 \	
"
 
EXTRA_QMAKEVARS_PRE = "CONFIG+=release"

FILES_${PN} += "usr/lib"

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP_${PN} = "installed-vs-shipped " 


