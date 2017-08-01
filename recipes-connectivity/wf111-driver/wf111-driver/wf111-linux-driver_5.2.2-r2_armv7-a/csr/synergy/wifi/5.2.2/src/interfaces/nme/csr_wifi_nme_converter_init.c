/*
 *
 * Copyright (C) 2012 by Cambridge Silicon Radio Ltd.
 *
 * Refer to LICENSE.txt included with this source code for details on
 * the license terms.
 *
 */

/* Note: this is an auto-generated file. */

#include "csr_msgconv.h"
#include "csr_pmem.h"
#include "csr_util.h"

#ifdef CSR_WIFI_NME_ENABLE

#ifdef CSR_LOG_ENABLE
#include "csr_log.h"
#endif

#ifndef EXCLUDE_CSR_WIFI_NME_MODULE
#include "csr_wifi_nme_serialize.h"
#include "csr_wifi_nme_prim.h"

static CsrMsgConvMsgEntry csrwifinme_conv_lut[] = {
    { CSR_WIFI_NME_PROFILE_SET_REQ, CsrWifiNmeProfileSetReqSizeof, CsrWifiNmeProfileSetReqSer, CsrWifiNmeProfileSetReqDes, CsrWifiNmeProfileSetReqSerFree },
    { CSR_WIFI_NME_PROFILE_DELETE_REQ, CsrWifiNmeProfileDeleteReqSizeof, CsrWifiNmeProfileDeleteReqSer, CsrWifiNmeProfileDeleteReqDes, CsrWifiNmeProfileDeleteReqSerFree },
    { CSR_WIFI_NME_PROFILE_DELETE_ALL_REQ, CsrWifiNmeProfileDeleteAllReqSizeof, CsrWifiNmeProfileDeleteAllReqSer, CsrWifiNmeProfileDeleteAllReqDes, CsrWifiNmeProfileDeleteAllReqSerFree },
    { CSR_WIFI_NME_PROFILE_ORDER_SET_REQ, CsrWifiNmeProfileOrderSetReqSizeof, CsrWifiNmeProfileOrderSetReqSer, CsrWifiNmeProfileOrderSetReqDes, CsrWifiNmeProfileOrderSetReqSerFree },
    { CSR_WIFI_NME_PROFILE_CONNECT_REQ, CsrWifiNmeProfileConnectReqSizeof, CsrWifiNmeProfileConnectReqSer, CsrWifiNmeProfileConnectReqDes, CsrWifiNmeProfileConnectReqSerFree },
    { CSR_WIFI_NME_WPS_REQ, CsrWifiNmeWpsReqSizeof, CsrWifiNmeWpsReqSer, CsrWifiNmeWpsReqDes, CsrWifiNmeWpsReqSerFree },
    { CSR_WIFI_NME_WPS_CANCEL_REQ, CsrWifiNmeWpsCancelReqSizeof, CsrWifiNmeWpsCancelReqSer, CsrWifiNmeWpsCancelReqDes, CsrWifiNmeWpsCancelReqSerFree },
    { CSR_WIFI_NME_CONNECTION_STATUS_GET_REQ, CsrWifiNmeConnectionStatusGetReqSizeof, CsrWifiNmeConnectionStatusGetReqSer, CsrWifiNmeConnectionStatusGetReqDes, CsrWifiNmeConnectionStatusGetReqSerFree },
    { CSR_WIFI_NME_SIM_IMSI_GET_RES, CsrWifiNmeSimImsiGetResSizeof, CsrWifiNmeSimImsiGetResSer, CsrWifiNmeSimImsiGetResDes, CsrWifiNmeSimImsiGetResSerFree },
    { CSR_WIFI_NME_SIM_GSM_AUTH_RES, CsrWifiNmeSimGsmAuthResSizeof, CsrWifiNmeSimGsmAuthResSer, CsrWifiNmeSimGsmAuthResDes, CsrWifiNmeSimGsmAuthResSerFree },
    { CSR_WIFI_NME_SIM_UMTS_AUTH_RES, CsrWifiNmeSimUmtsAuthResSizeof, CsrWifiNmeSimUmtsAuthResSer, CsrWifiNmeSimUmtsAuthResDes, CsrWifiNmeSimUmtsAuthResSerFree },
    { CSR_WIFI_NME_WPS_CONFIG_SET_REQ, CsrWifiNmeWpsConfigSetReqSizeof, CsrWifiNmeWpsConfigSetReqSer, CsrWifiNmeWpsConfigSetReqDes, CsrWifiNmeWpsConfigSetReqSerFree },
    { CSR_WIFI_NME_EVENT_MASK_SET_REQ, CsrWifiNmeEventMaskSetReqSizeof, CsrWifiNmeEventMaskSetReqSer, CsrWifiNmeEventMaskSetReqDes, CsrWifiNmeEventMaskSetReqSerFree },
    { CSR_WIFI_NME_PROFILE_SET_CFM, CsrWifiNmeProfileSetCfmSizeof, CsrWifiNmeProfileSetCfmSer, CsrWifiNmeProfileSetCfmDes, CsrWifiNmeProfileSetCfmSerFree },
    { CSR_WIFI_NME_PROFILE_DELETE_CFM, CsrWifiNmeProfileDeleteCfmSizeof, CsrWifiNmeProfileDeleteCfmSer, CsrWifiNmeProfileDeleteCfmDes, CsrWifiNmeProfileDeleteCfmSerFree },
    { CSR_WIFI_NME_PROFILE_DELETE_ALL_CFM, CsrWifiNmeProfileDeleteAllCfmSizeof, CsrWifiNmeProfileDeleteAllCfmSer, CsrWifiNmeProfileDeleteAllCfmDes, CsrWifiNmeProfileDeleteAllCfmSerFree },
    { CSR_WIFI_NME_PROFILE_ORDER_SET_CFM, CsrWifiNmeProfileOrderSetCfmSizeof, CsrWifiNmeProfileOrderSetCfmSer, CsrWifiNmeProfileOrderSetCfmDes, CsrWifiNmeProfileOrderSetCfmSerFree },
    { CSR_WIFI_NME_PROFILE_CONNECT_CFM, CsrWifiNmeProfileConnectCfmSizeof, CsrWifiNmeProfileConnectCfmSer, CsrWifiNmeProfileConnectCfmDes, CsrWifiNmeProfileConnectCfmSerFree },
    { CSR_WIFI_NME_WPS_CFM, CsrWifiNmeWpsCfmSizeof, CsrWifiNmeWpsCfmSer, CsrWifiNmeWpsCfmDes, CsrWifiNmeWpsCfmSerFree },
    { CSR_WIFI_NME_WPS_CANCEL_CFM, CsrWifiNmeWpsCancelCfmSizeof, CsrWifiNmeWpsCancelCfmSer, CsrWifiNmeWpsCancelCfmDes, CsrWifiNmeWpsCancelCfmSerFree },
    { CSR_WIFI_NME_CONNECTION_STATUS_GET_CFM, CsrWifiNmeConnectionStatusGetCfmSizeof, CsrWifiNmeConnectionStatusGetCfmSer, CsrWifiNmeConnectionStatusGetCfmDes, CsrWifiNmeConnectionStatusGetCfmSerFree },
    { CSR_WIFI_NME_PROFILE_UPDATE_IND, CsrWifiNmeProfileUpdateIndSizeof, CsrWifiNmeProfileUpdateIndSer, CsrWifiNmeProfileUpdateIndDes, CsrWifiNmeProfileUpdateIndSerFree },
    { CSR_WIFI_NME_PROFILE_DISCONNECT_IND, CsrWifiNmeProfileDisconnectIndSizeof, CsrWifiNmeProfileDisconnectIndSer, CsrWifiNmeProfileDisconnectIndDes, CsrWifiNmeProfileDisconnectIndSerFree },
    { CSR_WIFI_NME_SIM_IMSI_GET_IND, CsrWifiNmeSimImsiGetIndSizeof, CsrWifiNmeSimImsiGetIndSer, CsrWifiNmeSimImsiGetIndDes, CsrWifiNmeSimImsiGetIndSerFree },
    { CSR_WIFI_NME_SIM_GSM_AUTH_IND, CsrWifiNmeSimGsmAuthIndSizeof, CsrWifiNmeSimGsmAuthIndSer, CsrWifiNmeSimGsmAuthIndDes, CsrWifiNmeSimGsmAuthIndSerFree },
    { CSR_WIFI_NME_SIM_UMTS_AUTH_IND, CsrWifiNmeSimUmtsAuthIndSizeof, CsrWifiNmeSimUmtsAuthIndSer, CsrWifiNmeSimUmtsAuthIndDes, CsrWifiNmeSimUmtsAuthIndSerFree },
    { CSR_WIFI_NME_WPS_CONFIG_SET_CFM, CsrWifiNmeWpsConfigSetCfmSizeof, CsrWifiNmeWpsConfigSetCfmSer, CsrWifiNmeWpsConfigSetCfmDes, CsrWifiNmeWpsConfigSetCfmSerFree },
    { CSR_WIFI_NME_EVENT_MASK_SET_CFM, CsrWifiNmeEventMaskSetCfmSizeof, CsrWifiNmeEventMaskSetCfmSer, CsrWifiNmeEventMaskSetCfmDes, CsrWifiNmeEventMaskSetCfmSerFree },

    { 0, NULL, NULL, NULL, NULL },
};

CsrMsgConvMsgEntry* CsrWifiNmeConverterLookup(CsrMsgConvMsgEntry *ce, CsrUint16 msgType)
{
    if (msgType & CSR_PRIM_UPSTREAM)
    {
        CsrUint16 idx = (msgType & ~CSR_PRIM_UPSTREAM) + CSR_WIFI_NME_PRIM_DOWNSTREAM_COUNT;
        if (idx < (CSR_WIFI_NME_PRIM_UPSTREAM_COUNT + CSR_WIFI_NME_PRIM_DOWNSTREAM_COUNT) &&
            csrwifinme_conv_lut[idx].msgType == msgType)
        {
            return &csrwifinme_conv_lut[idx];
        }
    }
    else
    {
        if (msgType < CSR_WIFI_NME_PRIM_DOWNSTREAM_COUNT &&
            csrwifinme_conv_lut[msgType].msgType == msgType)
        {
            return &csrwifinme_conv_lut[msgType];
        }
    }
    return NULL;
}


void CsrWifiNmeConverterInit(void)
{
    CsrMsgConvInsert(CSR_WIFI_NME_PRIM, csrwifinme_conv_lut);
    CsrMsgConvCustomLookupRegister(CSR_WIFI_NME_PRIM, CsrWifiNmeConverterLookup);
}


#ifdef CSR_LOG_ENABLE
static const CsrLogPrimitiveInformation csrwifinme_conv_info = {
    CSR_WIFI_NME_PRIM,
    (CsrCharString *)"CSR_WIFI_NME_PRIM",
    csrwifinme_conv_lut
};
const CsrLogPrimitiveInformation* CsrWifiNmeTechInfoGet(void)
{
    return &csrwifinme_conv_info;
}


#endif /* CSR_LOG_ENABLE */
#endif /* EXCLUDE_CSR_WIFI_NME_MODULE */
#endif /* CSR_WIFI_NME_ENABLE */
