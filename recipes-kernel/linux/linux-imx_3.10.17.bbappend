FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI += "file://defconfig"
SRC_URI += "file://icore-defconfig"
SRC_URI += "file://0001-Added-i.Core-M6-support.patch"
SRC_URI += "file://0002-Added-iomux-for-sdhc2-and-uart3.patch"
SRC_URI += "file://0003-Added-i.Core-M6-hardware-revision-management.patch"
SRC_URI += "file://0004-Added-i.Core-M6-hardware-revision-management-part2.patch"
SRC_URI += "file://0005-Tested-SDIO-support-on-SDHC2.patch"
SRC_URI += "file://0006-Added-defconfig-for-i.Core.patch"


FSL_KERNEL_DEFCONFIG="icore-defconfig"

