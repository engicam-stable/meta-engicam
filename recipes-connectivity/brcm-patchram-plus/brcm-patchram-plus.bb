#
#@DESCRIPTION: brcm_patchram_plus network apps

PR = "r0"
LICENSE = "GPLv2"

S = "${WORKDIR}"

LIC_FILES_CHKSUM = "file://brcm_patchram_plus.c;md5=627e9612337e5ef6027a87a79c491446"
SRC_URI = "file://brcm_patchram_plus.c"

do_compile() {
             ${CC} ${CFLAGS} ${LDFLAGS} -o brcm_patchram_plus brcm_patchram_plus.c
}

do_install() {
             install -d ${D}${bindir}/
             install -m 0755 ${S}/brcm_patchram_plus ${D}${bindir}/
}

FILES_${PN} = "${bindir}/brcm_patchram_plus"
