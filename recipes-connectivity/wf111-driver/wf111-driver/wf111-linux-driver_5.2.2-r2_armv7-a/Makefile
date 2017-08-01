KARCH = $(ARCH)

DEFAULT_MIB = mib111_drv_led.dat

DRIVER_PATH := $(PWD)/csr/os_linux/driver
FIRMWARE_PATH = $(PWD)/csr/firmware
MIB_PATH := $(PWD)/mib
TOOLS_PATH := $(PWD)/csr/os_linux/tools
SCRIPT_PATH := $(PWD)/scripts
SYNERGY_ROOT := $(PWD)/csr/synergy

OUTPUT = $(PWD)/output

include $(SYNERGY_ROOT)/paths.mk
include $(WIFI_ROOT)/ver.mk
UNIFI_VERSION := $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_FIXLEVEL)-$(VERSION_BUILD)

ifdef KDIR
override KDIR := $(realpath $(KDIR))
endif

ifeq ($(ARCH), powerpc)
EXTRA_CFLAGS += -D__powerpc__
endif

# set help to default target
help:

all: unifi_sdio unifi_config unifi_helper

-include Release.mk


# HELP
#######

help:
	@echo "Build environment for Linux drivers of Bluegiga WF111 module"
	@echo
	@echo "Usage:"
	@echo
	@echo "targets:"
	@echo "    unifi_sdio             - build unifi driver"
	@echo "    unifi_sdio_android     - build unifi driver for Android"
	@echo "    install                - build and install binaries to OUTPUT"
	@echo "    install_android        - build and install Android binaries"
	@echo "                             to OUTPUT"
	@echo "    install_static         - build and install statically linked"
	@echo "                             binaries to OUTPUT"
	@echo "    install_static_android - build and install statically linked"
	@echo "                             Android binaries to OUTPUT"
	@echo "    clean                  - clean the build tree"
	@echo
	@echo "variables:"
	@echo "    KDIR                   - path to kernel source tree"
	@echo "    ARCH                   - x86, arm, powerpc"
	@echo "    CROSS_COMPILE          - cross compile prefix (optional)"
	@echo "    OUTPUT                 - install destination path (default: output)"
	@echo
	@echo "Example: make KDIR=/path/to/linux ARCH=arm CROSS_COMPILE=arm-linux- install_static"

# UNIFI DRIVER
###############

unifi_sdio_android unifi_sdio_android_clean: EXTRA_CFLAGS += -DANDROID_BUILD
unifi_sdio_android: unifi_sdio
unifi_sdio_android_clean: unifi_sdio_clean
unifi_sdio: EXTRA_CFLAGS += -Wno-error=date-time

unifi_sdio:
ifndef KDIR
	$(error KDIR is not defined)
else
ifneq ($(shell egrep --count "^CONFIG_WIRELESS_EXT=y$$" "$(KDIR)/.config"), 1)
	$(error WIRELESS_EXT is missing from the kernel config)
endif
endif
	@$(MAKE) -C $(DRIVER_PATH) driver \
		ARCH=$(KARCH) KDIR=$(KDIR) CONFIG=release EXTRA_DRV_CFLAGS="$(EXTRA_CFLAGS)"

unifi_sdio_clean:
ifndef KDIR
	$(error KDIR is not defined)
endif
	@$(MAKE) -C $(DRIVER_PATH) clean_modules \
		ARCH=$(KARCH) KDIR=$(KDIR) CONFIG=release

unifi_sdio_install: unifi_sdio
	@$(MAKE) -C $(DRIVER_PATH) install_modules \
		ARCH=$(KARCH) KDIR=$(KDIR) CONFIG=release DESTDIR=$(OUTPUT)

unifi_config:
unifi_config_clean:
unifi_helper:
unifi_helper_clean:

# INSTALL
###########

OUTPUT_BIN := $(OUTPUT)/usr/sbin
OUTPUT_FIRMWARE := $(OUTPUT)/lib/firmware/unifi-sdio
install_android install_static_android: OUTPUT_BIN := $(OUTPUT)/system/bin
install_android install_static_android: OUTPUT_FIRMWARE := $(OUTPUT)/system/etc/firmware/unifi-sdio
install_android install_static_android: OUTPUT_MODULE := $(OUTPUT)/system/lib/modules

install_static_android: install_android install_static

install_android: unifi_sdio_android install
	@cp $(TOOLS_PATH)/android/hotplug \
		$(TOOLS_PATH)/android/unififw \
		$(TOOLS_PATH)/android/unifi_start \
		$(OUTPUT_BIN)

install_static: install
	@cp $(TOOLS_PATH)/static/unifi_helper $(TOOLS_PATH)/static/unifi_config $(OUTPUT_BIN)

install: unifi_sdio unifi_config unifi_helper
	@mkdir -p $(OUTPUT_BIN)
	@mkdir -p $(OUTPUT_FIRMWARE)
	@cp $(TOOLS_PATH)/unififw $(TOOLS_PATH)/unifi_helper $(TOOLS_PATH)/unifi_config $(OUTPUT_BIN)
	@cp $(FIRMWARE_PATH)/*.xbv $(OUTPUT_FIRMWARE)
	@cp $(MIB_PATH)/*.dat $(OUTPUT_FIRMWARE)
	@ln -sf $(DEFAULT_MIB) $(OUTPUT_FIRMWARE)/ufmib.dat
	@if [ -z "$(OUTPUT_MODULE)" ]; then \
		$(MAKE) unifi_sdio_install; \
	else \
		mkdir -p $(OUTPUT_MODULE) && cp $(DRIVER_PATH)/unifi_sdio.ko $(OUTPUT_MODULE); \
	fi


clean: unifi_sdio_clean unifi_config_clean unifi_helper_clean
	@rm -rf $(OUTPUT)

.PHONY: clean unifi_sdio unifi_helper
