KDIR ?= /lib/modules/$(shell uname -r)/build
SDIO_DRIVER ?= emb
SME ?= wext_ap
USER_TOOLS ?= csr_only

ifeq ($(SDIO_DRIVER),emb)
ifeq ($(SDIODIR),)
$(error Set SDIODIR to the sdioemb driver path e.g. ../../sdioemb )
endif
endif

modules:
	echo FW_ROOT = $(FW_ROOT)
	echo WIFI_ROOT = $(WIFI_ROOT)
	echo SYNERGY_FW_ROOT = $(SYNERGY_FW_ROOT)
	echo SYNERGY_WIFI_ROOT = $(SYNERGY_WIFI_ROOT)
	$(MAKE) -C $(KDIR) M=$(BUILDDIR)/os_linux/driver \
		O=$(O) V=$(V) WIFI_VERSION=$(WIFI_VERSION)

install_modules:
	$(MAKE) -C $(KDIR) M=$(BUILDDIR)/os_linux/driver modules_install INSTALL_MOD_PATH=$(DESTDIR) \
		O=$(O) V=$(V)

# Kbuild's clean target doesn't play nicely with our Kbuild file:
# ../lib_hip/ isn't cleaned because it's above M; and .config isn't
# included so SDIO_PLATFORM isn't defined.
clean_modules:
	$(MAKE) -C $(KDIR) M=$(BUILDDIR)/os_linux/driver clean \
		O=$(O) V=$(V) SDIO_PLATFORM=unused
	rm -f $(BUILDDIR)/lib_hip/*.o $(BUILDDIR)/lib_hip/.*.o.cmd
	rm -f $(BUILDDIR)/os_linux/driver/Module.markers
	rm -f $(BUILDDIR)/os_linux/driver/modules.order

ifneq ($(CROSS_COMPILE),)
export CROSS_COMPILE
endif

ifneq ($(ARCH),)
export ARCH
endif

export SDIO_DRIVER
export SDIODIR
export SME
export USER_TOOLS
