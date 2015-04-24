FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI += "file://0001-added-iCoreM6-support.patch"
SRC_URI += "file://0002-Added-i.Core-D-revision-support.patch"
SRC_URI += "file://0003-added-default-iMx6Solo-mmcargs.patch"
SRC_URI += "file://0004-add-sdcard-config-boards.patch"
SRC_URI += "file://0005-added-cma-default-value-for-solo-nand.patch"
SRC_URI += "file://0006-added-engicam-board-parameter.patch"
SRC_URI += "file://0007-added-default-config-for-boot-from-sd.patch"
SRC_URI += "file://0008-modified-default-value-for-iCoreM6D-Q-cma-value.patch"
SRC_URI += "file://0009-Add-support-for-u-boot-splashscreen.patch"
SRC_URI += "file://0010-Add-support-rqs-modules.patch"
SRC_URI += "file://0011-SDHC1-pad-improvment.patch"
SRC_URI += "file://0012-backlight-improvment.patch"
SRC_URI += "file://0013-tftp-ubi-improvment.patch"
SRC_URI += "file://0014-Add-new-board-ofcap.patch"
SRC_URI += "file://0015-LTIB-support-rqs-improvment.patch"
SRC_URI += "file://0016-temperature-extension.patch"
SRC_URI += "file://0017-mmc-envsize-increase.patch"
SRC_URI += "file://Engicam.bmp"

do_patch_prepend() {
    os.system("mv ${S}/../Engicam.bmp ${S}/tools/logos/");
}


