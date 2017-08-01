/*
 *
 * Copyright (C) 2012 by Cambridge Silicon Radio Ltd.
 *
 * Refer to LICENSE.txt included with this source code for details on
 * the license terms.
 *
 */

/* Note: this is an auto-generated file. */

#ifndef CSR_WIFI_SME_TASK_H__
#define CSR_WIFI_SME_TASK_H__

#include "csr_types.h"
#include "csr_sched.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CSR_WIFI_SME_LOG_ID 0x1202FFFF
extern CsrSchedQid CSR_WIFI_SME_IFACEQUEUE;
void CsrWifiSmeInit(void **gash);
void CsrWifiSmeDeinit(void **gash);
void CsrWifiSmeHandler(void **gash);

#ifdef __cplusplus
}
#endif

#endif /* CSR_WIFI_SME_TASK_H__ */

