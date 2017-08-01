SUMMARY = "Qt5 everywhere demo"
DESCRIPTION = "Quick tour of Qt 5.0, primarily focusing on its graphical capabilities."
HOMEPAGE = "https://code.qt.io"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://main.cpp;md5=a3ecdc1d777da347f1bf35dd9966606f"

DEPENDS = "qtdeclarative qtgraphicaleffects qtmultimedia"

SRCREV = "6178748a6ea34df40a8e3c9ce67137e33383bb0e"
SRC_URI = "git://code.qt.io/qt-labs/qt5-everywhere-demo.git"

S = "${WORKDIR}/git/QtDemo"

require recipes-qt/qt5/qt5.inc

do_install() {
    install -d ${D}${datadir}/${P}
    install -m 0755 ${B}/QtDemo ${D}${datadir}/${P}   
    cp -a ${S}/qml ${D}${datadir}/${P}  
}

FILES_${PN}-dbg += "${datadir}/${P}/.debug"
FILES_${PN} += "${datadir}"

RDEPENDS_${PN} = "qtdeclarative-qmlplugins qtgraphicaleffects-qmlplugins"
