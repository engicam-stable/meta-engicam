/*
 *
 * Copyright (C) 2012 by Cambridge Silicon Radio Ltd.
 *
 * Refer to LICENSE.txt included with this source code for details on
 * the license terms.
 *
 */

/* Note: this is an auto-generated file. */

#include "csr_pmem.h"
#include "csr_wifi_nme_prim.h"
#include "csr_wifi_nme_lib.h"

/*----------------------------------------------------------------------------*
 *  NAME
 *      CsrWifiNmeFreeDownstreamMessageContents
 *
 *  DESCRIPTION
 *
 *
 *  PARAMETERS
 *      eventClass: only the value CSR_WIFI_NME_PRIM will be handled
 *      message:    the message to free
 *----------------------------------------------------------------------------*/
void CsrWifiNmeFreeDownstreamMessageContents(CsrUint16 eventClass, void *message)
{
    if (eventClass != CSR_WIFI_NME_PRIM)
    {
        return;
    }
    if (NULL == message)
    {
        return;
    }

    switch (*((CsrWifiNmePrim *) message))
    {
        case CSR_WIFI_NME_PROFILE_SET_REQ:
        {
            CsrWifiNmeProfileSetReq *p = (CsrWifiNmeProfileSetReq *)message;
            switch (p->profile.credentials.credentialType)
            {
                case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
                    CsrPmemFree(p->profile.credentials.credential.eap.userName);
                    p->profile.credentials.credential.eap.userName = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.userPassword);
                    p->profile.credentials.credential.eap.userPassword = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.authServerUserIdentity);
                    p->profile.credentials.credential.eap.authServerUserIdentity = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.clientCertificate);
                    p->profile.credentials.credential.eap.clientCertificate = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.certificateAuthorityCertificate);
                    p->profile.credentials.credential.eap.certificateAuthorityCertificate = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.privateKey);
                    p->profile.credentials.credential.eap.privateKey = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.privateKeyPassword);
                    p->profile.credentials.credential.eap.privateKeyPassword = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.session);
                    p->profile.credentials.credential.eap.session = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.pac);
                    p->profile.credentials.credential.eap.pac = NULL;
                    CsrPmemFree(p->profile.credentials.credential.eap.pacPassword);
                    p->profile.credentials.credential.eap.pacPassword = NULL;
                    break;
                case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
                    CsrPmemFree(p->profile.credentials.credential.wapiPassphrase.passphrase);
                    p->profile.credentials.credential.wapiPassphrase.passphrase = NULL;
                    break;
                case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
                    CsrPmemFree(p->profile.credentials.credential.wpa2Passphrase.passphrase);
                    p->profile.credentials.credential.wpa2Passphrase.passphrase = NULL;
                    break;
                case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
                    CsrPmemFree(p->profile.credentials.credential.wpaPassphrase.passphrase);
                    p->profile.credentials.credential.wpaPassphrase.passphrase = NULL;
                    break;
                case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
                    CsrPmemFree(p->profile.credentials.credential.wapi.certificate);
                    p->profile.credentials.credential.wapi.certificate = NULL;
                    CsrPmemFree(p->profile.credentials.credential.wapi.privateKey);
                    p->profile.credentials.credential.wapi.privateKey = NULL;
                    CsrPmemFree(p->profile.credentials.credential.wapi.caCertificate);
                    p->profile.credentials.credential.wapi.caCertificate = NULL;
                    break;
                default:
                    break;
            }
            break;
        }
        case CSR_WIFI_NME_PROFILE_ORDER_SET_REQ:
        {
            CsrWifiNmeProfileOrderSetReq *p = (CsrWifiNmeProfileOrderSetReq *)message;
            CsrPmemFree(p->profileIdentitys);
            p->profileIdentitys = NULL;
            break;
        }
        case CSR_WIFI_NME_SIM_IMSI_GET_RES:
        {
            CsrWifiNmeSimImsiGetRes *p = (CsrWifiNmeSimImsiGetRes *)message;
            CsrPmemFree(p->imsi);
            p->imsi = NULL;
            break;
        }
        case CSR_WIFI_NME_SIM_GSM_AUTH_RES:
        {
            CsrWifiNmeSimGsmAuthRes *p = (CsrWifiNmeSimGsmAuthRes *)message;
            CsrPmemFree(p->kcs);
            p->kcs = NULL;
            CsrPmemFree(p->sres);
            p->sres = NULL;
            break;
        }
        case CSR_WIFI_NME_SIM_UMTS_AUTH_RES:
        {
            CsrWifiNmeSimUmtsAuthRes *p = (CsrWifiNmeSimUmtsAuthRes *)message;
            CsrPmemFree(p->resParameter);
            p->resParameter = NULL;
            break;
        }
        case CSR_WIFI_NME_WPS_CONFIG_SET_REQ:
        {
            CsrWifiNmeWpsConfigSetReq *p = (CsrWifiNmeWpsConfigSetReq *)message;
            CsrPmemFree(p->wpsConfig.secondaryDeviceType);
            p->wpsConfig.secondaryDeviceType = NULL;
            break;
        }

        default:
            break;
    }
}


