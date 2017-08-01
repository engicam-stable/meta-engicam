DESCRIPTION = "Firmware files for use with BCM4343w wifi"
S = "${WORKDIR}"

LICENSE = "CLOSED"

SRC_URI = "file://brcm4343w"

do_install() {
	install -d ${D}/lib/firmware/brcm
	install -m 0755 ${S}/brcm4343w/* ${D}/lib/firmware/brcm/
	cd ${D}/lib/firmware/brcm
	ln -s fw_bcmdhd_4343w-11_15_2016.bin brcmfmac43430-sdio.bin
	ln -s bcmdhd_4343w_etsi-11_15_2016.cal brcmfmac43430-sdio.txt
}

FILES_${PN} =  "/lib/firmware/brcm/*"
