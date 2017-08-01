ARCH := arm
TMP_DIR := $(PWD)
SDIO_DRIVER := mmc
SME := wext_ap
KDIR ?= $(TMP_DIR)/../../../../../kernel
CROSS_COMPILE := $(TMP_DIR)/../../../../../prebuilt/linux-x86/toolchain/arm-eabi-4.2.1/bin/arm-eabi-
EXTRA_DRV_CFLAGS := -DUNIFI_NET_NAME=\"wlan\" -DANDROID_BUILD
export EXTRA_DRV_CFLAGS

include config.generic.mk
