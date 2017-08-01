# 
# Makefile for Linux driver
#
# Copyright (C) 2005-2011 by Cambridge Silicon Radio Ltd.
#
# Refer to LICENSE.txt included with this source code for details on
# the license terms.
#

ifeq ($(CONFIG),)
$(error CONFIG not set)
endif

all: driver tools

include config.$(CONFIG).mk

ifeq ($(USER_TOOLS),)
$(error USER_TOOLS not set)
endif

DRIVERTOP := $(shell pwd)/..
OSTOP := $(DRIVERTOP)/os_linux/driver

# If the ../packaging/ is missing this is a build from released
# sources, so build in-place.
ifeq ($(shell test -d $(DRIVERTOP)/packaging && echo y),y)
BUILDDIR := $(DRIVERTOP)/../builds/driver/$(CONFIG)
else
BUILDDIR := $(DRIVERTOP)/..
endif

#
# This file defines all the synergy root paths
# FW_ROOT, BT_ROOT, WIFI_ROOT, NUCLEUS_ROOT etc
# $(SYNERGY_ROOT) MUST BE DEFINED
#
SYNERGY_ROOT=$(DRIVERTOP)/../synergy/
include $(SYNERGY_ROOT)/paths.mk

SYNERGY_FW_ROOT := $(subst $(DRIVERTOP)/../,,$(FW_ROOT))
SYNERGY_WIFI_ROOT := $(subst $(DRIVERTOP)/../,,$(WIFI_ROOT))


# Include version definition file
include $(DRIVERTOP)/../$(SYNERGY_WIFI_ROOT)/ver.mk
ifeq ($(VERSION_BUILD),0)
WIFI_VERSION := "$(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_FIXLEVEL)"
else
WIFI_VERSION := "$(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_FIXLEVEL)-$(VERSION_BUILD)"
endif


driver: buildtree modules

tools: buildtree
	$(MAKE) -C $(BUILDDIR)/os_linux/tools $(USER_TOOLS) EXTRA_CFLAGS="$(EXTRA_DRV_CFLAGS)"

install: install_driver install_tools post_install_hook

install_driver: driver install_modules

install_tools: tools
	$(MAKE) -C $(BUILDDIR)/os_linux/tools install_$(USER_TOOLS)

clean: clean_modules clean_tools

clean_tools:
	$(MAKE) -C $(BUILDDIR)/os_linux/tools clean

# Need to create the required directory structure for linking
# files into the build directory. The files linked from the synergy
# directory are controlled by the lists in the synergy_filelist.mk
# file, but the common, os_linux/driver and os_linux/tools just have
# all their files linked.
buildtree: $(BUILDDIR) 

include synergy_filelist.mk
$(BUILDDIR): synergy_filelist.mk
	mkdir -p $(BUILDDIR); echo SYNERGY_WIFI_ROOT=$(SYNERGY_WIFI_ROOT) echo SYNERGY_FW_ROOT=$(SYNERGY_FW_ROOT)
	# Link the contents of the whole directory
	set -e ; for d in common os_linux/driver os_linux/tools ; do \
		rm -rf $(BUILDDIR)/$$d ; \
		mkdir -p $(BUILDDIR)/$$d ; \
		( cd $(BUILDDIR)/$$d && $(DRIVERTOP)/scripts/lndir $(DRIVERTOP)/../$$d ) ; \
	done
	# Link only the files listed in the synergy_filelist.mk
	rm -rf $(BUILDDIR)/synergy		
	set -e ; for f in $(SYNERGY_FILES) ; do \
		if [ -f $(DRIVERTOP)/../$$f ] ; \
			then ( mkdir -p $(BUILDDIR)/`dirname $$f` ; cd $(BUILDDIR)/`dirname $$f` && ln -s $(DRIVERTOP)/../$$f $(BUILDDIR)/`dirname $$f` ) ; \
		    else ( echo "ERROR: Missing file $$f" ; exit 1 ); \
		fi ; \
	done		

.PHONY: post_install_hook buildtree
