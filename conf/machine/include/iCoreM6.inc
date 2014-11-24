# Provides the iCore6 common settings

require conf/machine/include/imx-base.inc
require conf/machine/include/tune-cortexa9.inc

SERIAL_CONSOLE = "115200 ttymxc3"

MACHINE_FIRMWARE_append_mx6 = " linux-firmware-ath6k"

MACHINE_FEATURES += "wifi"

KERNEL_IMAGETYPE = "uImage"
