# 
# List of files required to create the linux OSS tarball
# as part of the release process. One of the issues with
# creation of the OSS tarball and building of the linux driver
# as a day to day activity is that the two activities are performed
# by different scripts and quite often the contents of the OSS tarball
# failed to build because the scripts were not updated. So to try and
# prevent this problem the following list of files is used in the OSS
# tarball generation and the os_linux build process. 
#
# Copyright (C) 2010-2010 by Cambridge Silicon Radio Ltd.
#
# Refer to LICENSE.txt included with this source code for details on
# the license terms.
#

SYNERGY_FRAMEWORK_FILES = \
$(SYNERGY_FW_ROOT)/bsp/inc/csr_framework_ext.h \
$(SYNERGY_FW_ROOT)/bsp/inc/csr_sdio.h \
$(SYNERGY_FW_ROOT)/bsp/inc/csr_pmem.h \
$(SYNERGY_FW_ROOT)/bsp/inc/csr_util.h \
$(SYNERGY_FW_ROOT)/bsp/inc/csr_sched.h \
$(SYNERGY_FW_ROOT)/bsp/inc/csr_time.h \
$(SYNERGY_FW_ROOT)/bsp/inc/csr_panic.h \
$(SYNERGY_FW_ROOT)/bsp/inc/csr_msg_transport.h \
$(SYNERGY_FW_ROOT)/bsp/ports/pclin/inc/csr_framework_ext_types.h \
$(SYNERGY_FW_ROOT)/bsp/ports/pclin/inc/csr_types.h \
$(SYNERGY_FW_ROOT)/bsp/ports/pclin/inc/platform/csr_panic_init.h \
$(SYNERGY_FW_ROOT)/bsp/ports/pclin/src/kernel/framework_ext/csr_framework_ext.c \
$(SYNERGY_FW_ROOT)/bsp/ports/pclin/src/kernel/time/csr_time.c \
$(SYNERGY_FW_ROOT)/bsp/ports/pclin/src/kernel/panic/csr_panic.c \
$(SYNERGY_FW_ROOT)/bsp/ports/pclin/src/kernel/pmem/csr_pmem.c \
$(SYNERGY_FW_ROOT)/bsp/ports/pclin/src/kernel/util/csr_util.c \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_result.h \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_macro.h \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_prim_defs.h \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_log_text.h \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_log_configure.h \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_log.h \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_msgconv.h \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_unicode.h \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_formatted_io.h \
$(SYNERGY_FW_ROOT)/gsp/src/utils/formatted_io/csr_formatted_io.c \
$(SYNERGY_FW_ROOT)/gsp/src/utils/msgconv/csr_msgconv.c \
$(SYNERGY_FW_ROOT)/gsp/src/utils/msgconv/csr_serialize_primitive_types.c \
$(SYNERGY_FW_ROOT)/gsp/src/utils/unicode/csr_utf16.c \
$(SYNERGY_FW_ROOT)/gsp/inc/csr_lib.h


SYNERGY_WIFI_FILES = \
$(SYNERGY_WIFI_ROOT)/ver.mk \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_fsm_event.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_lib.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_common.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_sme_task.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_task.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_sme_prim.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_sme_ap_prim.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_prim.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_ap_prim.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_sme_lib.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_sme_ap_lib.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_lib.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_ap_lib.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_router_task.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_router_prim.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_router_lib.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_hostio_prim.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_msgconv.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_router_converter_init.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_router_serialize.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_sme_converter_init.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_converter_init.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_sme_serialize.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_serialize.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_ap_converter_init.h \
$(SYNERGY_WIFI_ROOT)/inc/csr_wifi_nme_ap_serialize.h \
$(SYNERGY_WIFI_ROOT)/src/interfaces/router/csr_wifi_router_converter_init.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/router/csr_wifi_router_serialize.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/router/csr_wifi_router_free_downstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/router/csr_wifi_router_free_upstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/router_ctrl/csr_wifi_router_ctrl_converter_init.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/router_ctrl/csr_wifi_router_ctrl_serialize.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/router_ctrl/csr_wifi_router_ctrl_free_downstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/router_ctrl/csr_wifi_router_ctrl_free_upstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/sme/csr_wifi_sme_converter_init.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/nme/csr_wifi_nme_converter_init.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/sme/csr_wifi_sme_serialize.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/nme/csr_wifi_nme_serialize.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/sme/csr_wifi_sme_free_downstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/nme/csr_wifi_nme_free_downstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/sme/csr_wifi_sme_free_upstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/nme/csr_wifi_nme_free_upstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/nme_ap/csr_wifi_nme_ap_serialize.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/nme_ap/csr_wifi_nme_ap_converter_init.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/nme_ap/csr_wifi_nme_ap_free_downstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/interfaces/nme_ap/csr_wifi_nme_ap_free_upstream_contents.c \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_fsm.h \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_fsm_types.h \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_result.h \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_router_ctrl_prim.h \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_router_ctrl_lib.h \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_router_ctrl_converter_init.h \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_router_ctrl_serialize.h \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_private_common.h \
$(SYNERGY_WIFI_ROOT)/src/inc/csr_wifi_vif_utils.h \
$(SYNERGY_WIFI_ROOT)/src/hip/inc/csr_wifi_hip_conversions.h \
$(SYNERGY_WIFI_ROOT)/src/hip/inc/csr_wifi_hip_signals.h \
$(SYNERGY_WIFI_ROOT)/src/hip/inc/csr_wifi_hip_sigs.h \
$(SYNERGY_WIFI_ROOT)/src/hip/inc/csr_wifi_hip_unifi_udi.h \
$(SYNERGY_WIFI_ROOT)/src/hip/inc/csr_wifi_hip_unifi.h \
$(SYNERGY_WIFI_ROOT)/src/hip/inc/csr_wifi_hip_unifiversion.h \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_card_sdio_intr.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_card_sdio_mem.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_card_sdio.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_card_sdio.h \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_card.h \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_chiphelper_private.h \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_chiphelper.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_chiphelper.h \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_download.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_dump.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_packing.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_sdio_evaluation_test.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_send.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_signals.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_ta_sampling.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_ta_sampling.h \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_udi.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_unifi_signal_names.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_unifihw.h \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_xbv.c \
$(SYNERGY_WIFI_ROOT)/src/hip/lib_hip/csr_wifi_hip_xbv.h \
$(SYNERGY_WIFI_ROOT)/src/wifi_util/csr_wifi_lib.c \
$(SYNERGY_WIFI_ROOT)/src/wifi_util/msgconv/csr_wifi_serialize_primitive_types.c

SYNERGY_FILES = \
$(SYNERGY_FRAMEWORK_FILES) \
$(SYNERGY_WIFI_FILES) \
synergy/paths.mk
