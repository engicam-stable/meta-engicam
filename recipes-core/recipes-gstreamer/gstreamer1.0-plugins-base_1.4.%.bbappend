FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"


SRC_URI_remove = " file://gstplaybin-remove-flag-deinterlace.patch "

# Enable pango lib
PACKAGECONFIG_append = " pango "

PACKAGE_ARCH_mxs = "${MACHINE_SOCARCH}"
PACKAGE_ARCH_mx5 = "${MACHINE_SOCARCH}"
PACKAGE_ARCH_mx6 = "${MACHINE_SOCARCH}"
