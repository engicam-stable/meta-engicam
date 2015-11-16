FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI_append_mx6ul += "file://0001-add-geam6ul-support.patch \
  			 file://0002-add-geam6ul_defconfig.patch \
  			 file://0003-removed-pad-settings-for-sdhc.patch \
  			 file://0004-fix-backlight-settings-on-geam6ul.patch\
  			 file://0005-remove-power-key-form-geam6ul.patch \
  			 file://0006-add-ttymxc1-rs232-settings.patch \
			 file://defconfig \
"

SRC_URI_append_mx6 += "file://0001-Added-i.core-M6-support.patch   \
        file://0002-Fixed-DDR3-controller-setting-for-i.Core.patch   \
        file://0003-Added-iomux-for-sdhc2-and-uart3.patch   \
        file://0004-Added-i.Core-M6-hardware-revision-management.patch   \
        file://0005-Added-i.Core-M6-hardware-revision-management-part-2.patch   \
        file://0006-Tested-SDIO-support-on-SDHC2.patch   \
        file://0007-Tested-ADV7180-video-in-on-i.Core-M6-starterkit.patch   \
        file://0008-ADV7180-video-in-on-i.Core-part-2.patch   \
        file://0009-Tested-SGTL5000-driver-on-i.Core-M6.patch   \
        file://0010-added-capacitive-openframe-edt-ft5x06-touch-controll.patch   \
        file://0011-add-support-for-rqs-modules.patch   \
        file://0012-add-support-rs485.patch   \
        file://0013-adv7180_icoreq.patch   \
        file://0014-ofres-lvds_reset.patch   \
        file://0015-ofres-lvds_reset-fixed.patch   \
        file://0016-rqs-support-improvment.patch   \
        file://0017-rtc-pcf8563-support.patch   \
        file://0018-penmount6000-lvds-g121.patch   \
        file://0019-max1180_noise_reduction.patch   \
        file://0020-add-support-ofwi.patch   \
        file://0021-thermale-temperature-change.patch   \
        file://0022-support-ofloco.patch   \
        file://0023-max-frequency-setup.patch   \
        file://0024-new-lcd-for-of-wi.patch   \
        file://0025-ofloco-touch-improvment.patch   \
        file://0026-ofloco-bugfix-touchscreen.patch   \
        file://0027-rqs-fixed-mmc-dev.patch   \
	file://0028-add-icorem6sx-support.patch \
	file://0029-add-dtb-machine-on-mach.patch \
	file://0030-solox-dts-backligth.patch \
	file://defconfig \
"


