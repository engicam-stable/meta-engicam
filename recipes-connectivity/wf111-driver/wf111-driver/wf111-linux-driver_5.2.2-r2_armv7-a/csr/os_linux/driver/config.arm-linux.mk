ARCH := arm
CROSS_COMPILE := arm-linux-

ifeq ($(KDIR),)
$(error Set KDIR to the kernel tree to build against)
endif

include config.generic.mk
