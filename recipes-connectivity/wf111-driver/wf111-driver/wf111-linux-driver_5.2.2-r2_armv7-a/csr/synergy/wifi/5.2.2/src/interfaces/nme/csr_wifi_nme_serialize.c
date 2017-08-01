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
#include "csr_msgconv.h"
#include "csr_unicode.h"

#ifdef CSR_WIFI_NME_ENABLE

#include "csr_wifi_nme_prim.h"
#include "csr_wifi_nme_serialize.h"

void CsrWifiNmePfree(void *ptr)
{
    CsrPmemFree(ptr);
}


CsrSize CsrWifiNmeProfileSetReqSizeof(void *msg)
{
    CsrWifiNmeProfileSetReq *primitive = (CsrWifiNmeProfileSetReq *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 104) */
    bufferSize += 6;  /* CsrUint8 primitive->profile.profileIdentity.bssid.a[6] */
    bufferSize += 32; /* CsrUint8 primitive->profile.profileIdentity.ssid.ssid[32] */
    bufferSize += 1;  /* CsrUint8 primitive->profile.profileIdentity.ssid.length */
    bufferSize += 1;  /* CsrWifiNmeWmmQosInfoMask primitive->profile.wmmQosInfoMask */
    bufferSize += 1;  /* CsrWifiNmeBssType primitive->profile.bssType */
    bufferSize += 1;  /* CsrUint8 primitive->profile.channelNo */
    bufferSize += 1;  /* CsrUint8 primitive->profile.ccxOptionsMask */
    bufferSize += 1;  /* CsrBool primitive->profile.cloakedSsid */
    bufferSize += 2;  /* CsrWifiNmeCredentialType primitive->profile.credentials.credentialType */
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiNmeEapMethodMask primitive->profile.credentials.credential.eap.eapMethodMask */
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.eap.authMode */
            bufferSize += 2;                                                                                                                                                              /* CsrWifiNmeEncryptionMask primitive->profile.credentials.credential.eap.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.eap.userName?CsrStrLen(primitive->profile.credentials.credential.eap.userName) : 0) + 1;                             /* CsrCharString* primitive->profile.credentials.credential.eap.userName (0 byte len + 1 for NULL Term) */
            bufferSize += (primitive->profile.credentials.credential.eap.userPassword?CsrStrLen(primitive->profile.credentials.credential.eap.userPassword) : 0) + 1;                     /* CsrCharString* primitive->profile.credentials.credential.eap.userPassword (0 byte len + 1 for NULL Term) */
            bufferSize += (primitive->profile.credentials.credential.eap.authServerUserIdentity?CsrStrLen(primitive->profile.credentials.credential.eap.authServerUserIdentity) : 0) + 1; /* CsrCharString* primitive->profile.credentials.credential.eap.authServerUserIdentity (0 byte len + 1 for NULL Term) */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.clientCertificateLength */
            bufferSize += primitive->profile.credentials.credential.eap.clientCertificateLength;                                                                                          /* CsrUint8 primitive->profile.credentials.credential.eap.clientCertificate */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength */
            bufferSize += primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength;                                                                            /* CsrUint8 primitive->profile.credentials.credential.eap.certificateAuthorityCertificate */
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.eap.privateKeyLength */
            bufferSize += primitive->profile.credentials.credential.eap.privateKeyLength;                                                                                                 /* CsrUint8 primitive->profile.credentials.credential.eap.privateKey */
            bufferSize += (primitive->profile.credentials.credential.eap.privateKeyPassword?CsrStrLen(primitive->profile.credentials.credential.eap.privateKeyPassword) : 0) + 1;         /* CsrCharString* primitive->profile.credentials.credential.eap.privateKeyPassword (0 byte len + 1 for NULL Term) */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.sessionLength */
            bufferSize += primitive->profile.credentials.credential.eap.sessionLength;                                                                                                    /* CsrUint8 primitive->profile.credentials.credential.eap.session */
            bufferSize += 1;                                                                                                                                                              /* CsrBool primitive->profile.credentials.credential.eap.allowPacProvisioning */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.pacLength */
            bufferSize += primitive->profile.credentials.credential.eap.pacLength;                                                                                                        /* CsrUint8 primitive->profile.credentials.credential.eap.pac */
            bufferSize += (primitive->profile.credentials.credential.eap.pacPassword?CsrStrLen(primitive->profile.credentials.credential.eap.pacPassword) : 0) + 1;                       /* CsrCharString* primitive->profile.credentials.credential.eap.pacPassword (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapiPassphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wapiPassphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wapiPassphrase.passphrase) : 0) + 1;   /* CsrCharString* primitive->profile.credentials.credential.wapiPassphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wpa2Passphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wpa2Passphrase.passphrase) : 0) + 1;   /* CsrCharString* primitive->profile.credentials.credential.wpa2Passphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpa2Psk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wpa2Psk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapiPsk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wapiPsk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpaPassphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wpaPassphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wpaPassphrase.passphrase) : 0) + 1;     /* CsrCharString* primitive->profile.credentials.credential.wpaPassphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.wapi.certificateLength */
            bufferSize += primitive->profile.credentials.credential.wapi.certificateLength;                                                                                               /* CsrUint8 primitive->profile.credentials.credential.wapi.certificate */
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapi.privateKeyLength */
            bufferSize += primitive->profile.credentials.credential.wapi.privateKeyLength;                                                                                                /* CsrUint8 primitive->profile.credentials.credential.wapi.privateKey */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.wapi.caCertificateLength */
            bufferSize += primitive->profile.credentials.credential.wapi.caCertificateLength;                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wapi.caCertificate */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.wep128Key.wepAuthType */
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep128Key.selectedWepKey */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key1[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key2[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key3[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key4[13] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpaPsk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wpaPsk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.openSystem.empty */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.wep64Key.wepAuthType */
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.selectedWepKey */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key1[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key2[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key3[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key4[5] */
            break;
        default:
            break;
    }
    return bufferSize;
}


CsrUint8* CsrWifiNmeProfileSetReqSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeProfileSetReq *primitive = (CsrWifiNmeProfileSetReq *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrMemCpySer(ptr, len, (const void *) primitive->profile.profileIdentity.bssid.a, ((CsrUint16) (6)));
    CsrMemCpySer(ptr, len, (const void *) primitive->profile.profileIdentity.ssid.ssid, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.profileIdentity.ssid.length);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.wmmQosInfoMask);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.bssType);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.channelNo);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.ccxOptionsMask);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.cloakedSsid);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credentialType);
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.eapMethodMask);
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.authMode);
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.userName);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.userPassword);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.authServerUserIdentity);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.clientCertificateLength);
            if (primitive->profile.credentials.credential.eap.clientCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.clientCertificate, ((CsrUint16) (primitive->profile.credentials.credential.eap.clientCertificateLength)));
            }
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength);
            if (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.certificateAuthorityCertificate, ((CsrUint16) (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)));
            }
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.privateKeyLength);
            if (primitive->profile.credentials.credential.eap.privateKeyLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.privateKey, ((CsrUint16) (primitive->profile.credentials.credential.eap.privateKeyLength)));
            }
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.privateKeyPassword);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.sessionLength);
            if (primitive->profile.credentials.credential.eap.sessionLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.session, ((CsrUint16) (primitive->profile.credentials.credential.eap.sessionLength)));
            }
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.eap.allowPacProvisioning);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.pacLength);
            if (primitive->profile.credentials.credential.eap.pacLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.pac, ((CsrUint16) (primitive->profile.credentials.credential.eap.pacLength)));
            }
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.pacPassword);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapiPassphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wapiPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wpa2Passphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpa2Psk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wpa2Psk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapiPsk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapiPsk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpaPassphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wpaPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.wapi.certificateLength);
            if (primitive->profile.credentials.credential.wapi.certificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.certificate, ((CsrUint16) (primitive->profile.credentials.credential.wapi.certificateLength)));
            }
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapi.privateKeyLength);
            if (primitive->profile.credentials.credential.wapi.privateKeyLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.privateKey, ((CsrUint16) (primitive->profile.credentials.credential.wapi.privateKeyLength)));
            }
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.wapi.caCertificateLength);
            if (primitive->profile.credentials.credential.wapi.caCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.caCertificate, ((CsrUint16) (primitive->profile.credentials.credential.wapi.caCertificateLength)));
            }
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wep128Key.wepAuthType);
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.wep128Key.selectedWepKey);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key1, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key2, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key3, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key4, ((CsrUint16) (13)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpaPsk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wpaPsk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.openSystem.empty);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wep64Key.wepAuthType);
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.wep64Key.selectedWepKey);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key1, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key2, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key3, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key4, ((CsrUint16) (5)));
            break;
        default:
            break;
    }
    return(ptr);
}


void* CsrWifiNmeProfileSetReqDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeProfileSetReq *primitive = (CsrWifiNmeProfileSetReq *) CsrPmemAlloc(sizeof(CsrWifiNmeProfileSetReq));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrMemCpyDes(primitive->profile.profileIdentity.bssid.a, buffer, &offset, ((CsrUint16) (6)));
    CsrMemCpyDes(primitive->profile.profileIdentity.ssid.ssid, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->profile.profileIdentity.ssid.length, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.wmmQosInfoMask, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.bssType, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.channelNo, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.ccxOptionsMask, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.cloakedSsid, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credentialType, buffer, &offset);
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.eapMethodMask, buffer, &offset);
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.authMode, buffer, &offset);
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.userName, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.userPassword, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.authServerUserIdentity, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.clientCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.clientCertificateLength)
            {
                primitive->profile.credentials.credential.eap.clientCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.clientCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.clientCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.clientCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.clientCertificate = NULL;
            }
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)
            {
                primitive->profile.credentials.credential.eap.certificateAuthorityCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.certificateAuthorityCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.certificateAuthorityCertificate = NULL;
            }
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.privateKeyLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.privateKeyLength)
            {
                primitive->profile.credentials.credential.eap.privateKey = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.privateKeyLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.privateKey, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.privateKeyLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.privateKey = NULL;
            }
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.privateKeyPassword, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.sessionLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.sessionLength)
            {
                primitive->profile.credentials.credential.eap.session = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.sessionLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.session, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.sessionLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.session = NULL;
            }
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.eap.allowPacProvisioning, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.pacLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.pacLength)
            {
                primitive->profile.credentials.credential.eap.pac = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.pacLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.pac, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.pacLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.pac = NULL;
            }
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.pacPassword, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapiPassphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wapiPassphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wpa2Passphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpa2Psk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wpa2Psk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapiPsk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wapiPsk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpaPassphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wpaPassphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.wapi.certificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.certificateLength)
            {
                primitive->profile.credentials.credential.wapi.certificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.certificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.certificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.certificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.certificate = NULL;
            }
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapi.privateKeyLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.privateKeyLength)
            {
                primitive->profile.credentials.credential.wapi.privateKey = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.privateKeyLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.privateKey, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.privateKeyLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.privateKey = NULL;
            }
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.wapi.caCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.caCertificateLength)
            {
                primitive->profile.credentials.credential.wapi.caCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.caCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.caCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.caCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.caCertificate = NULL;
            }
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wep128Key.wepAuthType, buffer, &offset);
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.wep128Key.selectedWepKey, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key1, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key2, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key3, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key4, buffer, &offset, ((CsrUint16) (13)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpaPsk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wpaPsk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.openSystem.empty, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wep64Key.wepAuthType, buffer, &offset);
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.wep64Key.selectedWepKey, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key1, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key2, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key3, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key4, buffer, &offset, ((CsrUint16) (5)));
            break;
        default:
            break;
    }

    return primitive;
}


void CsrWifiNmeProfileSetReqSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeProfileSetReq *primitive = (CsrWifiNmeProfileSetReq *) voidPrimitivePointer;
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrPmemFree(primitive->profile.credentials.credential.eap.userName);
            CsrPmemFree(primitive->profile.credentials.credential.eap.userPassword);
            CsrPmemFree(primitive->profile.credentials.credential.eap.authServerUserIdentity);
            CsrPmemFree(primitive->profile.credentials.credential.eap.clientCertificate);
            CsrPmemFree(primitive->profile.credentials.credential.eap.certificateAuthorityCertificate);
            CsrPmemFree(primitive->profile.credentials.credential.eap.privateKey);
            CsrPmemFree(primitive->profile.credentials.credential.eap.privateKeyPassword);
            CsrPmemFree(primitive->profile.credentials.credential.eap.session);
            CsrPmemFree(primitive->profile.credentials.credential.eap.pac);
            CsrPmemFree(primitive->profile.credentials.credential.eap.pacPassword);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wapiPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wpa2Passphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wpaPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrPmemFree(primitive->profile.credentials.credential.wapi.certificate);
            CsrPmemFree(primitive->profile.credentials.credential.wapi.privateKey);
            CsrPmemFree(primitive->profile.credentials.credential.wapi.caCertificate);
            break;
        default:
            break;
    }
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeProfileDeleteReqSizeof(void *msg)
{
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 42) */
    bufferSize += 6;  /* CsrUint8 primitive->profileIdentity.bssid.a[6] */
    bufferSize += 32; /* CsrUint8 primitive->profileIdentity.ssid.ssid[32] */
    bufferSize += 1;  /* CsrUint8 primitive->profileIdentity.ssid.length */
    return bufferSize;
}


CsrUint8* CsrWifiNmeProfileDeleteReqSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeProfileDeleteReq *primitive = (CsrWifiNmeProfileDeleteReq *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrMemCpySer(ptr, len, (const void *) primitive->profileIdentity.bssid.a, ((CsrUint16) (6)));
    CsrMemCpySer(ptr, len, (const void *) primitive->profileIdentity.ssid.ssid, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profileIdentity.ssid.length);
    return(ptr);
}


void* CsrWifiNmeProfileDeleteReqDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeProfileDeleteReq *primitive = (CsrWifiNmeProfileDeleteReq *) CsrPmemAlloc(sizeof(CsrWifiNmeProfileDeleteReq));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrMemCpyDes(primitive->profileIdentity.bssid.a, buffer, &offset, ((CsrUint16) (6)));
    CsrMemCpyDes(primitive->profileIdentity.ssid.ssid, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->profileIdentity.ssid.length, buffer, &offset);

    return primitive;
}


CsrSize CsrWifiNmeProfileOrderSetReqSizeof(void *msg)
{
    CsrWifiNmeProfileOrderSetReq *primitive = (CsrWifiNmeProfileOrderSetReq *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 45) */
    bufferSize += 2; /* CsrUint16 primitive->interfaceTag */
    bufferSize += 1; /* CsrUint8 primitive->profileIdentitysCount */
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->profileIdentitysCount; i1++)
        {
            bufferSize += 6;  /* CsrUint8 primitive->profileIdentitys[i1].bssid.a[6] */
            bufferSize += 32; /* CsrUint8 primitive->profileIdentitys[i1].ssid.ssid[32] */
            bufferSize += 1;  /* CsrUint8 primitive->profileIdentitys[i1].ssid.length */
        }
    }
    return bufferSize;
}


CsrUint8* CsrWifiNmeProfileOrderSetReqSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeProfileOrderSetReq *primitive = (CsrWifiNmeProfileOrderSetReq *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profileIdentitysCount);
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->profileIdentitysCount; i1++)
        {
            CsrMemCpySer(ptr, len, (const void *) primitive->profileIdentitys[i1].bssid.a, ((CsrUint16) (6)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profileIdentitys[i1].ssid.ssid, ((CsrUint16) (32)));
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profileIdentitys[i1].ssid.length);
        }
    }
    return(ptr);
}


void* CsrWifiNmeProfileOrderSetReqDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeProfileOrderSetReq *primitive = (CsrWifiNmeProfileOrderSetReq *) CsrPmemAlloc(sizeof(CsrWifiNmeProfileOrderSetReq));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profileIdentitysCount, buffer, &offset);
    primitive->profileIdentitys = NULL;
    if (primitive->profileIdentitysCount)
    {
        primitive->profileIdentitys = (CsrWifiNmeProfileIdentity *)CsrPmemAlloc(sizeof(CsrWifiNmeProfileIdentity) * primitive->profileIdentitysCount);
    }
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->profileIdentitysCount; i1++)
        {
            CsrMemCpyDes(primitive->profileIdentitys[i1].bssid.a, buffer, &offset, ((CsrUint16) (6)));
            CsrMemCpyDes(primitive->profileIdentitys[i1].ssid.ssid, buffer, &offset, ((CsrUint16) (32)));
            CsrUint8Des((CsrUint8 *) &primitive->profileIdentitys[i1].ssid.length, buffer, &offset);
        }
    }

    return primitive;
}


void CsrWifiNmeProfileOrderSetReqSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeProfileOrderSetReq *primitive = (CsrWifiNmeProfileOrderSetReq *) voidPrimitivePointer;
    CsrPmemFree(primitive->profileIdentitys);
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeProfileConnectReqSizeof(void *msg)
{
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 44) */
    bufferSize += 2;  /* CsrUint16 primitive->interfaceTag */
    bufferSize += 6;  /* CsrUint8 primitive->profileIdentity.bssid.a[6] */
    bufferSize += 32; /* CsrUint8 primitive->profileIdentity.ssid.ssid[32] */
    bufferSize += 1;  /* CsrUint8 primitive->profileIdentity.ssid.length */
    return bufferSize;
}


CsrUint8* CsrWifiNmeProfileConnectReqSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeProfileConnectReq *primitive = (CsrWifiNmeProfileConnectReq *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrMemCpySer(ptr, len, (const void *) primitive->profileIdentity.bssid.a, ((CsrUint16) (6)));
    CsrMemCpySer(ptr, len, (const void *) primitive->profileIdentity.ssid.ssid, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profileIdentity.ssid.length);
    return(ptr);
}


void* CsrWifiNmeProfileConnectReqDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeProfileConnectReq *primitive = (CsrWifiNmeProfileConnectReq *) CsrPmemAlloc(sizeof(CsrWifiNmeProfileConnectReq));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrMemCpyDes(primitive->profileIdentity.bssid.a, buffer, &offset, ((CsrUint16) (6)));
    CsrMemCpyDes(primitive->profileIdentity.ssid.ssid, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->profileIdentity.ssid.length, buffer, &offset);

    return primitive;
}


CsrSize CsrWifiNmeWpsReqSizeof(void *msg)
{
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 52) */
    bufferSize += 2;  /* CsrUint16 primitive->interfaceTag */
    bufferSize += 8;  /* CsrUint8 primitive->pin[8] */
    bufferSize += 32; /* CsrUint8 primitive->ssid.ssid[32] */
    bufferSize += 1;  /* CsrUint8 primitive->ssid.length */
    bufferSize += 6;  /* CsrUint8 primitive->bssid.a[6] */
    return bufferSize;
}


CsrUint8* CsrWifiNmeWpsReqSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeWpsReq *primitive = (CsrWifiNmeWpsReq *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrMemCpySer(ptr, len, (const void *) primitive->pin, ((CsrUint16) (8)));
    CsrMemCpySer(ptr, len, (const void *) primitive->ssid.ssid, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->ssid.length);
    CsrMemCpySer(ptr, len, (const void *) primitive->bssid.a, ((CsrUint16) (6)));
    return(ptr);
}


void* CsrWifiNmeWpsReqDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeWpsReq *primitive = (CsrWifiNmeWpsReq *) CsrPmemAlloc(sizeof(CsrWifiNmeWpsReq));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrMemCpyDes(primitive->pin, buffer, &offset, ((CsrUint16) (8)));
    CsrMemCpyDes(primitive->ssid.ssid, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->ssid.length, buffer, &offset);
    CsrMemCpyDes(primitive->bssid.a, buffer, &offset, ((CsrUint16) (6)));

    return primitive;
}


CsrSize CsrWifiNmeSimImsiGetResSizeof(void *msg)
{
    CsrWifiNmeSimImsiGetRes *primitive = (CsrWifiNmeSimImsiGetRes *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 7) */
    bufferSize += 2;                                                    /* CsrResult primitive->status */
    bufferSize += (primitive->imsi?CsrStrLen(primitive->imsi) : 0) + 1; /* CsrCharString* primitive->imsi (0 byte len + 1 for NULL Term) */
    bufferSize += 1;                                                    /* CsrWifiNmeSimCardType primitive->cardType */
    bufferSize += 1;                                                    /* CsrUint8 primitive->mncLength */
    return bufferSize;
}


CsrUint8* CsrWifiNmeSimImsiGetResSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeSimImsiGetRes *primitive = (CsrWifiNmeSimImsiGetRes *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->status);
    CsrCharStringSer(ptr, len, primitive->imsi);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->cardType);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->mncLength);
    return(ptr);
}


void* CsrWifiNmeSimImsiGetResDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeSimImsiGetRes *primitive = (CsrWifiNmeSimImsiGetRes *) CsrPmemAlloc(sizeof(CsrWifiNmeSimImsiGetRes));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->status, buffer, &offset);
    CsrCharStringDes(&primitive->imsi, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->cardType, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->mncLength, buffer, &offset);

    return primitive;
}


void CsrWifiNmeSimImsiGetResSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeSimImsiGetRes *primitive = (CsrWifiNmeSimImsiGetRes *) voidPrimitivePointer;
    CsrPmemFree(primitive->imsi);
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeSimGsmAuthResSizeof(void *msg)
{
    CsrWifiNmeSimGsmAuthRes *primitive = (CsrWifiNmeSimGsmAuthRes *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 9) */
    bufferSize += 2;                     /* CsrResult primitive->status */
    bufferSize += 1;                     /* CsrUint8 primitive->kcsLength */
    bufferSize += primitive->kcsLength;  /* CsrUint8 primitive->kcs */
    bufferSize += 1;                     /* CsrUint8 primitive->sresLength */
    bufferSize += primitive->sresLength; /* CsrUint8 primitive->sres */
    return bufferSize;
}


CsrUint8* CsrWifiNmeSimGsmAuthResSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeSimGsmAuthRes *primitive = (CsrWifiNmeSimGsmAuthRes *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->status);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->kcsLength);
    if (primitive->kcsLength)
    {
        CsrMemCpySer(ptr, len, (const void *) primitive->kcs, ((CsrUint16) (primitive->kcsLength)));
    }
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->sresLength);
    if (primitive->sresLength)
    {
        CsrMemCpySer(ptr, len, (const void *) primitive->sres, ((CsrUint16) (primitive->sresLength)));
    }
    return(ptr);
}


void* CsrWifiNmeSimGsmAuthResDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeSimGsmAuthRes *primitive = (CsrWifiNmeSimGsmAuthRes *) CsrPmemAlloc(sizeof(CsrWifiNmeSimGsmAuthRes));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->status, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->kcsLength, buffer, &offset);
    if (primitive->kcsLength)
    {
        primitive->kcs = (CsrUint8 *)CsrPmemAlloc(primitive->kcsLength);
        CsrMemCpyDes(primitive->kcs, buffer, &offset, ((CsrUint16) (primitive->kcsLength)));
    }
    else
    {
        primitive->kcs = NULL;
    }
    CsrUint8Des((CsrUint8 *) &primitive->sresLength, buffer, &offset);
    if (primitive->sresLength)
    {
        primitive->sres = (CsrUint8 *)CsrPmemAlloc(primitive->sresLength);
        CsrMemCpyDes(primitive->sres, buffer, &offset, ((CsrUint16) (primitive->sresLength)));
    }
    else
    {
        primitive->sres = NULL;
    }

    return primitive;
}


void CsrWifiNmeSimGsmAuthResSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeSimGsmAuthRes *primitive = (CsrWifiNmeSimGsmAuthRes *) voidPrimitivePointer;
    CsrPmemFree(primitive->kcs);
    CsrPmemFree(primitive->sres);
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeSimUmtsAuthResSizeof(void *msg)
{
    CsrWifiNmeSimUmtsAuthRes *primitive = (CsrWifiNmeSimUmtsAuthRes *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 54) */
    bufferSize += 2;                             /* CsrResult primitive->status */
    bufferSize += 1;                             /* CsrWifiNmeUmtsAuthResult primitive->result */
    bufferSize += 16;                            /* CsrUint8 primitive->umtsCipherKey[16] */
    bufferSize += 16;                            /* CsrUint8 primitive->umtsIntegrityKey[16] */
    bufferSize += 1;                             /* CsrUint8 primitive->resParameterLength */
    bufferSize += primitive->resParameterLength; /* CsrUint8 primitive->resParameter */
    bufferSize += 14;                            /* CsrUint8 primitive->auts[14] */
    return bufferSize;
}


CsrUint8* CsrWifiNmeSimUmtsAuthResSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeSimUmtsAuthRes *primitive = (CsrWifiNmeSimUmtsAuthRes *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->status);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->result);
    CsrMemCpySer(ptr, len, (const void *) primitive->umtsCipherKey, ((CsrUint16) (16)));
    CsrMemCpySer(ptr, len, (const void *) primitive->umtsIntegrityKey, ((CsrUint16) (16)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->resParameterLength);
    if (primitive->resParameterLength)
    {
        CsrMemCpySer(ptr, len, (const void *) primitive->resParameter, ((CsrUint16) (primitive->resParameterLength)));
    }
    CsrMemCpySer(ptr, len, (const void *) primitive->auts, ((CsrUint16) (14)));
    return(ptr);
}


void* CsrWifiNmeSimUmtsAuthResDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeSimUmtsAuthRes *primitive = (CsrWifiNmeSimUmtsAuthRes *) CsrPmemAlloc(sizeof(CsrWifiNmeSimUmtsAuthRes));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->status, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->result, buffer, &offset);
    CsrMemCpyDes(primitive->umtsCipherKey, buffer, &offset, ((CsrUint16) (16)));
    CsrMemCpyDes(primitive->umtsIntegrityKey, buffer, &offset, ((CsrUint16) (16)));
    CsrUint8Des((CsrUint8 *) &primitive->resParameterLength, buffer, &offset);
    if (primitive->resParameterLength)
    {
        primitive->resParameter = (CsrUint8 *)CsrPmemAlloc(primitive->resParameterLength);
        CsrMemCpyDes(primitive->resParameter, buffer, &offset, ((CsrUint16) (primitive->resParameterLength)));
    }
    else
    {
        primitive->resParameter = NULL;
    }
    CsrMemCpyDes(primitive->auts, buffer, &offset, ((CsrUint16) (14)));

    return primitive;
}


void CsrWifiNmeSimUmtsAuthResSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeSimUmtsAuthRes *primitive = (CsrWifiNmeSimUmtsAuthRes *) voidPrimitivePointer;
    CsrPmemFree(primitive->resParameter);
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeWpsConfigSetReqSizeof(void *msg)
{
    CsrWifiNmeWpsConfigSetReq *primitive = (CsrWifiNmeWpsConfigSetReq *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 240) */
    bufferSize += 1;  /* CsrUint8 primitive->wpsConfig.wpsVersion */
    bufferSize += 16; /* CsrUint8 primitive->wpsConfig.uuid[16] */
    bufferSize += 32; /* CsrUint8 primitive->wpsConfig.deviceName[32] */
    bufferSize += 1;  /* CsrUint8 primitive->wpsConfig.deviceNameLength */
    bufferSize += 64; /* CsrUint8 primitive->wpsConfig.manufacturer[64] */
    bufferSize += 1;  /* CsrUint8 primitive->wpsConfig.manufacturerLength */
    bufferSize += 32; /* CsrUint8 primitive->wpsConfig.modelName[32] */
    bufferSize += 1;  /* CsrUint8 primitive->wpsConfig.modelNameLength */
    bufferSize += 32; /* CsrUint8 primitive->wpsConfig.modelNumber[32] */
    bufferSize += 1;  /* CsrUint8 primitive->wpsConfig.modelNumberLength */
    bufferSize += 32; /* CsrUint8 primitive->wpsConfig.serialNumber[32] */
    bufferSize += 8;  /* CsrUint8 primitive->wpsConfig.primDeviceType.deviceDetails[8] */
    bufferSize += 1;  /* CsrUint8 primitive->wpsConfig.secondaryDeviceTypeCount */
    {
        CsrUint16 i2;
        for (i2 = 0; i2 < primitive->wpsConfig.secondaryDeviceTypeCount; i2++)
        {
            bufferSize += 8; /* CsrUint8 primitive->wpsConfig.secondaryDeviceType[i2].deviceDetails[8] */
        }
    }
    bufferSize += 2;         /* CsrWifiSmeWpsConfigTypeMask primitive->wpsConfig.configMethods */
    bufferSize += 1;         /* CsrUint8 primitive->wpsConfig.rfBands */
    bufferSize += 4;         /* CsrUint8 primitive->wpsConfig.osVersion[4] */
    return bufferSize;
}


CsrUint8* CsrWifiNmeWpsConfigSetReqSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeWpsConfigSetReq *primitive = (CsrWifiNmeWpsConfigSetReq *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->wpsConfig.wpsVersion);
    CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.uuid, ((CsrUint16) (16)));
    CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.deviceName, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->wpsConfig.deviceNameLength);
    CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.manufacturer, ((CsrUint16) (64)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->wpsConfig.manufacturerLength);
    CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.modelName, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->wpsConfig.modelNameLength);
    CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.modelNumber, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->wpsConfig.modelNumberLength);
    CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.serialNumber, ((CsrUint16) (32)));
    CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.primDeviceType.deviceDetails, ((CsrUint16) (8)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->wpsConfig.secondaryDeviceTypeCount);
    {
        CsrUint16 i2;
        for (i2 = 0; i2 < primitive->wpsConfig.secondaryDeviceTypeCount; i2++)
        {
            CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.secondaryDeviceType[i2].deviceDetails, ((CsrUint16) (8)));
        }
    }
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->wpsConfig.configMethods);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->wpsConfig.rfBands);
    CsrMemCpySer(ptr, len, (const void *) primitive->wpsConfig.osVersion, ((CsrUint16) (4)));
    return(ptr);
}


void* CsrWifiNmeWpsConfigSetReqDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeWpsConfigSetReq *primitive = (CsrWifiNmeWpsConfigSetReq *) CsrPmemAlloc(sizeof(CsrWifiNmeWpsConfigSetReq));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->wpsConfig.wpsVersion, buffer, &offset);
    CsrMemCpyDes(primitive->wpsConfig.uuid, buffer, &offset, ((CsrUint16) (16)));
    CsrMemCpyDes(primitive->wpsConfig.deviceName, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->wpsConfig.deviceNameLength, buffer, &offset);
    CsrMemCpyDes(primitive->wpsConfig.manufacturer, buffer, &offset, ((CsrUint16) (64)));
    CsrUint8Des((CsrUint8 *) &primitive->wpsConfig.manufacturerLength, buffer, &offset);
    CsrMemCpyDes(primitive->wpsConfig.modelName, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->wpsConfig.modelNameLength, buffer, &offset);
    CsrMemCpyDes(primitive->wpsConfig.modelNumber, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->wpsConfig.modelNumberLength, buffer, &offset);
    CsrMemCpyDes(primitive->wpsConfig.serialNumber, buffer, &offset, ((CsrUint16) (32)));
    CsrMemCpyDes(primitive->wpsConfig.primDeviceType.deviceDetails, buffer, &offset, ((CsrUint16) (8)));
    CsrUint8Des((CsrUint8 *) &primitive->wpsConfig.secondaryDeviceTypeCount, buffer, &offset);
    primitive->wpsConfig.secondaryDeviceType = NULL;
    if (primitive->wpsConfig.secondaryDeviceTypeCount)
    {
        primitive->wpsConfig.secondaryDeviceType = (CsrWifiSmeWpsDeviceType *)CsrPmemAlloc(sizeof(CsrWifiSmeWpsDeviceType) * primitive->wpsConfig.secondaryDeviceTypeCount);
    }
    {
        CsrUint16 i2;
        for (i2 = 0; i2 < primitive->wpsConfig.secondaryDeviceTypeCount; i2++)
        {
            CsrMemCpyDes(primitive->wpsConfig.secondaryDeviceType[i2].deviceDetails, buffer, &offset, ((CsrUint16) (8)));
        }
    }
    CsrUint16Des((CsrUint16 *) &primitive->wpsConfig.configMethods, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->wpsConfig.rfBands, buffer, &offset);
    CsrMemCpyDes(primitive->wpsConfig.osVersion, buffer, &offset, ((CsrUint16) (4)));

    return primitive;
}


void CsrWifiNmeWpsConfigSetReqSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeWpsConfigSetReq *primitive = (CsrWifiNmeWpsConfigSetReq *) voidPrimitivePointer;
    CsrPmemFree(primitive->wpsConfig.secondaryDeviceType);
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeProfileOrderSetCfmSizeof(void *msg)
{
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 7) */
    bufferSize += 2; /* CsrUint16 primitive->interfaceTag */
    bufferSize += 2; /* CsrResult primitive->status */
    return bufferSize;
}


CsrUint8* CsrWifiNmeProfileOrderSetCfmSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeProfileOrderSetCfm *primitive = (CsrWifiNmeProfileOrderSetCfm *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->status);
    return(ptr);
}


void* CsrWifiNmeProfileOrderSetCfmDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeProfileOrderSetCfm *primitive = (CsrWifiNmeProfileOrderSetCfm *) CsrPmemAlloc(sizeof(CsrWifiNmeProfileOrderSetCfm));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->status, buffer, &offset);

    return primitive;
}


CsrSize CsrWifiNmeProfileConnectCfmSizeof(void *msg)
{
    CsrWifiNmeProfileConnectCfm *primitive = (CsrWifiNmeProfileConnectCfm *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 17) */
    bufferSize += 2; /* CsrUint16 primitive->interfaceTag */
    bufferSize += 2; /* CsrResult primitive->status */
    bufferSize += 1; /* CsrUint8 primitive->connectAttemptsCount */
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->connectAttemptsCount; i1++)
        {
            bufferSize += 6; /* CsrUint8 primitive->connectAttempts[i1].bssid.a[6] */
            bufferSize += 2; /* CsrResult primitive->connectAttempts[i1].status */
            bufferSize += 1; /* CsrWifiNmeSecError primitive->connectAttempts[i1].securityError */
        }
    }
    return bufferSize;
}


CsrUint8* CsrWifiNmeProfileConnectCfmSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeProfileConnectCfm *primitive = (CsrWifiNmeProfileConnectCfm *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->status);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->connectAttemptsCount);
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->connectAttemptsCount; i1++)
        {
            CsrMemCpySer(ptr, len, (const void *) primitive->connectAttempts[i1].bssid.a, ((CsrUint16) (6)));
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->connectAttempts[i1].status);
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->connectAttempts[i1].securityError);
        }
    }
    return(ptr);
}


void* CsrWifiNmeProfileConnectCfmDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeProfileConnectCfm *primitive = (CsrWifiNmeProfileConnectCfm *) CsrPmemAlloc(sizeof(CsrWifiNmeProfileConnectCfm));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->status, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->connectAttemptsCount, buffer, &offset);
    primitive->connectAttempts = NULL;
    if (primitive->connectAttemptsCount)
    {
        primitive->connectAttempts = (CsrWifiNmeConnectAttempt *)CsrPmemAlloc(sizeof(CsrWifiNmeConnectAttempt) * primitive->connectAttemptsCount);
    }
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->connectAttemptsCount; i1++)
        {
            CsrMemCpyDes(primitive->connectAttempts[i1].bssid.a, buffer, &offset, ((CsrUint16) (6)));
            CsrUint16Des((CsrUint16 *) &primitive->connectAttempts[i1].status, buffer, &offset);
            CsrUint8Des((CsrUint8 *) &primitive->connectAttempts[i1].securityError, buffer, &offset);
        }
    }

    return primitive;
}


void CsrWifiNmeProfileConnectCfmSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeProfileConnectCfm *primitive = (CsrWifiNmeProfileConnectCfm *) voidPrimitivePointer;
    CsrPmemFree(primitive->connectAttempts);
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeWpsCfmSizeof(void *msg)
{
    CsrWifiNmeWpsCfm *primitive = (CsrWifiNmeWpsCfm *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 108) */
    bufferSize += 2;  /* CsrUint16 primitive->interfaceTag */
    bufferSize += 2;  /* CsrResult primitive->status */
    bufferSize += 6;  /* CsrUint8 primitive->profile.profileIdentity.bssid.a[6] */
    bufferSize += 32; /* CsrUint8 primitive->profile.profileIdentity.ssid.ssid[32] */
    bufferSize += 1;  /* CsrUint8 primitive->profile.profileIdentity.ssid.length */
    bufferSize += 1;  /* CsrWifiNmeWmmQosInfoMask primitive->profile.wmmQosInfoMask */
    bufferSize += 1;  /* CsrWifiNmeBssType primitive->profile.bssType */
    bufferSize += 1;  /* CsrUint8 primitive->profile.channelNo */
    bufferSize += 1;  /* CsrUint8 primitive->profile.ccxOptionsMask */
    bufferSize += 1;  /* CsrBool primitive->profile.cloakedSsid */
    bufferSize += 2;  /* CsrWifiNmeCredentialType primitive->profile.credentials.credentialType */
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiNmeEapMethodMask primitive->profile.credentials.credential.eap.eapMethodMask */
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.eap.authMode */
            bufferSize += 2;                                                                                                                                                              /* CsrWifiNmeEncryptionMask primitive->profile.credentials.credential.eap.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.eap.userName?CsrStrLen(primitive->profile.credentials.credential.eap.userName) : 0) + 1;                             /* CsrCharString* primitive->profile.credentials.credential.eap.userName (0 byte len + 1 for NULL Term) */
            bufferSize += (primitive->profile.credentials.credential.eap.userPassword?CsrStrLen(primitive->profile.credentials.credential.eap.userPassword) : 0) + 1;                     /* CsrCharString* primitive->profile.credentials.credential.eap.userPassword (0 byte len + 1 for NULL Term) */
            bufferSize += (primitive->profile.credentials.credential.eap.authServerUserIdentity?CsrStrLen(primitive->profile.credentials.credential.eap.authServerUserIdentity) : 0) + 1; /* CsrCharString* primitive->profile.credentials.credential.eap.authServerUserIdentity (0 byte len + 1 for NULL Term) */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.clientCertificateLength */
            bufferSize += primitive->profile.credentials.credential.eap.clientCertificateLength;                                                                                          /* CsrUint8 primitive->profile.credentials.credential.eap.clientCertificate */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength */
            bufferSize += primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength;                                                                            /* CsrUint8 primitive->profile.credentials.credential.eap.certificateAuthorityCertificate */
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.eap.privateKeyLength */
            bufferSize += primitive->profile.credentials.credential.eap.privateKeyLength;                                                                                                 /* CsrUint8 primitive->profile.credentials.credential.eap.privateKey */
            bufferSize += (primitive->profile.credentials.credential.eap.privateKeyPassword?CsrStrLen(primitive->profile.credentials.credential.eap.privateKeyPassword) : 0) + 1;         /* CsrCharString* primitive->profile.credentials.credential.eap.privateKeyPassword (0 byte len + 1 for NULL Term) */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.sessionLength */
            bufferSize += primitive->profile.credentials.credential.eap.sessionLength;                                                                                                    /* CsrUint8 primitive->profile.credentials.credential.eap.session */
            bufferSize += 1;                                                                                                                                                              /* CsrBool primitive->profile.credentials.credential.eap.allowPacProvisioning */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.pacLength */
            bufferSize += primitive->profile.credentials.credential.eap.pacLength;                                                                                                        /* CsrUint8 primitive->profile.credentials.credential.eap.pac */
            bufferSize += (primitive->profile.credentials.credential.eap.pacPassword?CsrStrLen(primitive->profile.credentials.credential.eap.pacPassword) : 0) + 1;                       /* CsrCharString* primitive->profile.credentials.credential.eap.pacPassword (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapiPassphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wapiPassphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wapiPassphrase.passphrase) : 0) + 1;   /* CsrCharString* primitive->profile.credentials.credential.wapiPassphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wpa2Passphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wpa2Passphrase.passphrase) : 0) + 1;   /* CsrCharString* primitive->profile.credentials.credential.wpa2Passphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpa2Psk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wpa2Psk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapiPsk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wapiPsk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpaPassphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wpaPassphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wpaPassphrase.passphrase) : 0) + 1;     /* CsrCharString* primitive->profile.credentials.credential.wpaPassphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.wapi.certificateLength */
            bufferSize += primitive->profile.credentials.credential.wapi.certificateLength;                                                                                               /* CsrUint8 primitive->profile.credentials.credential.wapi.certificate */
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapi.privateKeyLength */
            bufferSize += primitive->profile.credentials.credential.wapi.privateKeyLength;                                                                                                /* CsrUint8 primitive->profile.credentials.credential.wapi.privateKey */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.wapi.caCertificateLength */
            bufferSize += primitive->profile.credentials.credential.wapi.caCertificateLength;                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wapi.caCertificate */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.wep128Key.wepAuthType */
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep128Key.selectedWepKey */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key1[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key2[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key3[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key4[13] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpaPsk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wpaPsk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.openSystem.empty */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.wep64Key.wepAuthType */
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.selectedWepKey */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key1[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key2[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key3[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key4[5] */
            break;
        default:
            break;
    }
    return bufferSize;
}


CsrUint8* CsrWifiNmeWpsCfmSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeWpsCfm *primitive = (CsrWifiNmeWpsCfm *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->status);
    CsrMemCpySer(ptr, len, (const void *) primitive->profile.profileIdentity.bssid.a, ((CsrUint16) (6)));
    CsrMemCpySer(ptr, len, (const void *) primitive->profile.profileIdentity.ssid.ssid, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.profileIdentity.ssid.length);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.wmmQosInfoMask);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.bssType);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.channelNo);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.ccxOptionsMask);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.cloakedSsid);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credentialType);
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.eapMethodMask);
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.authMode);
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.userName);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.userPassword);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.authServerUserIdentity);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.clientCertificateLength);
            if (primitive->profile.credentials.credential.eap.clientCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.clientCertificate, ((CsrUint16) (primitive->profile.credentials.credential.eap.clientCertificateLength)));
            }
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength);
            if (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.certificateAuthorityCertificate, ((CsrUint16) (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)));
            }
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.privateKeyLength);
            if (primitive->profile.credentials.credential.eap.privateKeyLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.privateKey, ((CsrUint16) (primitive->profile.credentials.credential.eap.privateKeyLength)));
            }
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.privateKeyPassword);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.sessionLength);
            if (primitive->profile.credentials.credential.eap.sessionLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.session, ((CsrUint16) (primitive->profile.credentials.credential.eap.sessionLength)));
            }
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.eap.allowPacProvisioning);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.pacLength);
            if (primitive->profile.credentials.credential.eap.pacLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.pac, ((CsrUint16) (primitive->profile.credentials.credential.eap.pacLength)));
            }
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.pacPassword);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapiPassphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wapiPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wpa2Passphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpa2Psk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wpa2Psk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapiPsk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapiPsk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpaPassphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wpaPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.wapi.certificateLength);
            if (primitive->profile.credentials.credential.wapi.certificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.certificate, ((CsrUint16) (primitive->profile.credentials.credential.wapi.certificateLength)));
            }
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapi.privateKeyLength);
            if (primitive->profile.credentials.credential.wapi.privateKeyLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.privateKey, ((CsrUint16) (primitive->profile.credentials.credential.wapi.privateKeyLength)));
            }
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.wapi.caCertificateLength);
            if (primitive->profile.credentials.credential.wapi.caCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.caCertificate, ((CsrUint16) (primitive->profile.credentials.credential.wapi.caCertificateLength)));
            }
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wep128Key.wepAuthType);
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.wep128Key.selectedWepKey);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key1, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key2, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key3, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key4, ((CsrUint16) (13)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpaPsk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wpaPsk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.openSystem.empty);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wep64Key.wepAuthType);
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.wep64Key.selectedWepKey);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key1, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key2, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key3, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key4, ((CsrUint16) (5)));
            break;
        default:
            break;
    }
    return(ptr);
}


void* CsrWifiNmeWpsCfmDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeWpsCfm *primitive = (CsrWifiNmeWpsCfm *) CsrPmemAlloc(sizeof(CsrWifiNmeWpsCfm));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->status, buffer, &offset);
    CsrMemCpyDes(primitive->profile.profileIdentity.bssid.a, buffer, &offset, ((CsrUint16) (6)));
    CsrMemCpyDes(primitive->profile.profileIdentity.ssid.ssid, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->profile.profileIdentity.ssid.length, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.wmmQosInfoMask, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.bssType, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.channelNo, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.ccxOptionsMask, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.cloakedSsid, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credentialType, buffer, &offset);
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.eapMethodMask, buffer, &offset);
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.authMode, buffer, &offset);
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.userName, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.userPassword, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.authServerUserIdentity, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.clientCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.clientCertificateLength)
            {
                primitive->profile.credentials.credential.eap.clientCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.clientCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.clientCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.clientCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.clientCertificate = NULL;
            }
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)
            {
                primitive->profile.credentials.credential.eap.certificateAuthorityCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.certificateAuthorityCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.certificateAuthorityCertificate = NULL;
            }
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.privateKeyLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.privateKeyLength)
            {
                primitive->profile.credentials.credential.eap.privateKey = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.privateKeyLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.privateKey, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.privateKeyLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.privateKey = NULL;
            }
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.privateKeyPassword, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.sessionLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.sessionLength)
            {
                primitive->profile.credentials.credential.eap.session = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.sessionLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.session, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.sessionLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.session = NULL;
            }
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.eap.allowPacProvisioning, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.pacLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.pacLength)
            {
                primitive->profile.credentials.credential.eap.pac = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.pacLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.pac, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.pacLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.pac = NULL;
            }
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.pacPassword, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapiPassphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wapiPassphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wpa2Passphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpa2Psk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wpa2Psk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapiPsk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wapiPsk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpaPassphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wpaPassphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.wapi.certificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.certificateLength)
            {
                primitive->profile.credentials.credential.wapi.certificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.certificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.certificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.certificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.certificate = NULL;
            }
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapi.privateKeyLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.privateKeyLength)
            {
                primitive->profile.credentials.credential.wapi.privateKey = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.privateKeyLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.privateKey, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.privateKeyLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.privateKey = NULL;
            }
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.wapi.caCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.caCertificateLength)
            {
                primitive->profile.credentials.credential.wapi.caCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.caCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.caCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.caCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.caCertificate = NULL;
            }
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wep128Key.wepAuthType, buffer, &offset);
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.wep128Key.selectedWepKey, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key1, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key2, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key3, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key4, buffer, &offset, ((CsrUint16) (13)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpaPsk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wpaPsk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.openSystem.empty, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wep64Key.wepAuthType, buffer, &offset);
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.wep64Key.selectedWepKey, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key1, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key2, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key3, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key4, buffer, &offset, ((CsrUint16) (5)));
            break;
        default:
            break;
    }

    return primitive;
}


void CsrWifiNmeWpsCfmSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeWpsCfm *primitive = (CsrWifiNmeWpsCfm *) voidPrimitivePointer;
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrPmemFree(primitive->profile.credentials.credential.eap.userName);
            CsrPmemFree(primitive->profile.credentials.credential.eap.userPassword);
            CsrPmemFree(primitive->profile.credentials.credential.eap.authServerUserIdentity);
            CsrPmemFree(primitive->profile.credentials.credential.eap.clientCertificate);
            CsrPmemFree(primitive->profile.credentials.credential.eap.certificateAuthorityCertificate);
            CsrPmemFree(primitive->profile.credentials.credential.eap.privateKey);
            CsrPmemFree(primitive->profile.credentials.credential.eap.privateKeyPassword);
            CsrPmemFree(primitive->profile.credentials.credential.eap.session);
            CsrPmemFree(primitive->profile.credentials.credential.eap.pac);
            CsrPmemFree(primitive->profile.credentials.credential.eap.pacPassword);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wapiPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wpa2Passphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wpaPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrPmemFree(primitive->profile.credentials.credential.wapi.certificate);
            CsrPmemFree(primitive->profile.credentials.credential.wapi.privateKey);
            CsrPmemFree(primitive->profile.credentials.credential.wapi.caCertificate);
            break;
        default:
            break;
    }
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeWpsCancelCfmSizeof(void *msg)
{
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 7) */
    bufferSize += 2; /* CsrUint16 primitive->interfaceTag */
    bufferSize += 2; /* CsrResult primitive->status */
    return bufferSize;
}


CsrUint8* CsrWifiNmeWpsCancelCfmSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeWpsCancelCfm *primitive = (CsrWifiNmeWpsCancelCfm *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->status);
    return(ptr);
}


void* CsrWifiNmeWpsCancelCfmDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeWpsCancelCfm *primitive = (CsrWifiNmeWpsCancelCfm *) CsrPmemAlloc(sizeof(CsrWifiNmeWpsCancelCfm));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->status, buffer, &offset);

    return primitive;
}


CsrSize CsrWifiNmeConnectionStatusGetCfmSizeof(void *msg)
{
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 8) */
    bufferSize += 2; /* CsrUint16 primitive->interfaceTag */
    bufferSize += 2; /* CsrResult primitive->status */
    bufferSize += 1; /* CsrWifiNmeConnectionStatus primitive->connectionStatus */
    return bufferSize;
}


CsrUint8* CsrWifiNmeConnectionStatusGetCfmSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeConnectionStatusGetCfm *primitive = (CsrWifiNmeConnectionStatusGetCfm *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->status);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->connectionStatus);
    return(ptr);
}


void* CsrWifiNmeConnectionStatusGetCfmDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeConnectionStatusGetCfm *primitive = (CsrWifiNmeConnectionStatusGetCfm *) CsrPmemAlloc(sizeof(CsrWifiNmeConnectionStatusGetCfm));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->status, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->connectionStatus, buffer, &offset);

    return primitive;
}


CsrSize CsrWifiNmeProfileUpdateIndSizeof(void *msg)
{
    CsrWifiNmeProfileUpdateInd *primitive = (CsrWifiNmeProfileUpdateInd *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 106) */
    bufferSize += 2;  /* CsrUint16 primitive->interfaceTag */
    bufferSize += 6;  /* CsrUint8 primitive->profile.profileIdentity.bssid.a[6] */
    bufferSize += 32; /* CsrUint8 primitive->profile.profileIdentity.ssid.ssid[32] */
    bufferSize += 1;  /* CsrUint8 primitive->profile.profileIdentity.ssid.length */
    bufferSize += 1;  /* CsrWifiNmeWmmQosInfoMask primitive->profile.wmmQosInfoMask */
    bufferSize += 1;  /* CsrWifiNmeBssType primitive->profile.bssType */
    bufferSize += 1;  /* CsrUint8 primitive->profile.channelNo */
    bufferSize += 1;  /* CsrUint8 primitive->profile.ccxOptionsMask */
    bufferSize += 1;  /* CsrBool primitive->profile.cloakedSsid */
    bufferSize += 2;  /* CsrWifiNmeCredentialType primitive->profile.credentials.credentialType */
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiNmeEapMethodMask primitive->profile.credentials.credential.eap.eapMethodMask */
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.eap.authMode */
            bufferSize += 2;                                                                                                                                                              /* CsrWifiNmeEncryptionMask primitive->profile.credentials.credential.eap.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.eap.userName?CsrStrLen(primitive->profile.credentials.credential.eap.userName) : 0) + 1;                             /* CsrCharString* primitive->profile.credentials.credential.eap.userName (0 byte len + 1 for NULL Term) */
            bufferSize += (primitive->profile.credentials.credential.eap.userPassword?CsrStrLen(primitive->profile.credentials.credential.eap.userPassword) : 0) + 1;                     /* CsrCharString* primitive->profile.credentials.credential.eap.userPassword (0 byte len + 1 for NULL Term) */
            bufferSize += (primitive->profile.credentials.credential.eap.authServerUserIdentity?CsrStrLen(primitive->profile.credentials.credential.eap.authServerUserIdentity) : 0) + 1; /* CsrCharString* primitive->profile.credentials.credential.eap.authServerUserIdentity (0 byte len + 1 for NULL Term) */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.clientCertificateLength */
            bufferSize += primitive->profile.credentials.credential.eap.clientCertificateLength;                                                                                          /* CsrUint8 primitive->profile.credentials.credential.eap.clientCertificate */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength */
            bufferSize += primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength;                                                                            /* CsrUint8 primitive->profile.credentials.credential.eap.certificateAuthorityCertificate */
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.eap.privateKeyLength */
            bufferSize += primitive->profile.credentials.credential.eap.privateKeyLength;                                                                                                 /* CsrUint8 primitive->profile.credentials.credential.eap.privateKey */
            bufferSize += (primitive->profile.credentials.credential.eap.privateKeyPassword?CsrStrLen(primitive->profile.credentials.credential.eap.privateKeyPassword) : 0) + 1;         /* CsrCharString* primitive->profile.credentials.credential.eap.privateKeyPassword (0 byte len + 1 for NULL Term) */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.sessionLength */
            bufferSize += primitive->profile.credentials.credential.eap.sessionLength;                                                                                                    /* CsrUint8 primitive->profile.credentials.credential.eap.session */
            bufferSize += 1;                                                                                                                                                              /* CsrBool primitive->profile.credentials.credential.eap.allowPacProvisioning */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.eap.pacLength */
            bufferSize += primitive->profile.credentials.credential.eap.pacLength;                                                                                                        /* CsrUint8 primitive->profile.credentials.credential.eap.pac */
            bufferSize += (primitive->profile.credentials.credential.eap.pacPassword?CsrStrLen(primitive->profile.credentials.credential.eap.pacPassword) : 0) + 1;                       /* CsrCharString* primitive->profile.credentials.credential.eap.pacPassword (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapiPassphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wapiPassphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wapiPassphrase.passphrase) : 0) + 1;   /* CsrCharString* primitive->profile.credentials.credential.wapiPassphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wpa2Passphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wpa2Passphrase.passphrase) : 0) + 1;   /* CsrCharString* primitive->profile.credentials.credential.wpa2Passphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpa2Psk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wpa2Psk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapiPsk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wapiPsk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpaPassphrase.encryptionMode */
            bufferSize += (primitive->profile.credentials.credential.wpaPassphrase.passphrase?CsrStrLen(primitive->profile.credentials.credential.wpaPassphrase.passphrase) : 0) + 1;     /* CsrCharString* primitive->profile.credentials.credential.wpaPassphrase.passphrase (0 byte len + 1 for NULL Term) */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.wapi.certificateLength */
            bufferSize += primitive->profile.credentials.credential.wapi.certificateLength;                                                                                               /* CsrUint8 primitive->profile.credentials.credential.wapi.certificate */
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wapi.privateKeyLength */
            bufferSize += primitive->profile.credentials.credential.wapi.privateKeyLength;                                                                                                /* CsrUint8 primitive->profile.credentials.credential.wapi.privateKey */
            bufferSize += 4;                                                                                                                                                              /* CsrUint32 primitive->profile.credentials.credential.wapi.caCertificateLength */
            bufferSize += primitive->profile.credentials.credential.wapi.caCertificateLength;                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wapi.caCertificate */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.wep128Key.wepAuthType */
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep128Key.selectedWepKey */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key1[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key2[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key3[13] */
            bufferSize += 13;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wep128Key.key4[13] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            bufferSize += 2;                                                                                                                                                              /* CsrUint16 primitive->profile.credentials.credential.wpaPsk.encryptionMode */
            bufferSize += 32;                                                                                                                                                             /* CsrUint8 primitive->profile.credentials.credential.wpaPsk.psk[32] */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.openSystem.empty */
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            bufferSize += 2;                                                                                                                                                              /* CsrWifiSmeAuthModeMask primitive->profile.credentials.credential.wep64Key.wepAuthType */
            bufferSize += 1;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.selectedWepKey */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key1[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key2[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key3[5] */
            bufferSize += 5;                                                                                                                                                              /* CsrUint8 primitive->profile.credentials.credential.wep64Key.key4[5] */
            break;
        default:
            break;
    }
    return bufferSize;
}


CsrUint8* CsrWifiNmeProfileUpdateIndSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeProfileUpdateInd *primitive = (CsrWifiNmeProfileUpdateInd *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrMemCpySer(ptr, len, (const void *) primitive->profile.profileIdentity.bssid.a, ((CsrUint16) (6)));
    CsrMemCpySer(ptr, len, (const void *) primitive->profile.profileIdentity.ssid.ssid, ((CsrUint16) (32)));
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.profileIdentity.ssid.length);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.wmmQosInfoMask);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.bssType);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.channelNo);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.ccxOptionsMask);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.cloakedSsid);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credentialType);
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.eapMethodMask);
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.authMode);
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.userName);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.userPassword);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.authServerUserIdentity);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.clientCertificateLength);
            if (primitive->profile.credentials.credential.eap.clientCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.clientCertificate, ((CsrUint16) (primitive->profile.credentials.credential.eap.clientCertificateLength)));
            }
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength);
            if (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.certificateAuthorityCertificate, ((CsrUint16) (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)));
            }
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.eap.privateKeyLength);
            if (primitive->profile.credentials.credential.eap.privateKeyLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.privateKey, ((CsrUint16) (primitive->profile.credentials.credential.eap.privateKeyLength)));
            }
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.privateKeyPassword);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.sessionLength);
            if (primitive->profile.credentials.credential.eap.sessionLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.session, ((CsrUint16) (primitive->profile.credentials.credential.eap.sessionLength)));
            }
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.eap.allowPacProvisioning);
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.eap.pacLength);
            if (primitive->profile.credentials.credential.eap.pacLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.eap.pac, ((CsrUint16) (primitive->profile.credentials.credential.eap.pacLength)));
            }
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.eap.pacPassword);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapiPassphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wapiPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wpa2Passphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpa2Psk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wpa2Psk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapiPsk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapiPsk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpaPassphrase.encryptionMode);
            CsrCharStringSer(ptr, len, primitive->profile.credentials.credential.wpaPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.wapi.certificateLength);
            if (primitive->profile.credentials.credential.wapi.certificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.certificate, ((CsrUint16) (primitive->profile.credentials.credential.wapi.certificateLength)));
            }
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wapi.privateKeyLength);
            if (primitive->profile.credentials.credential.wapi.privateKeyLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.privateKey, ((CsrUint16) (primitive->profile.credentials.credential.wapi.privateKeyLength)));
            }
            CsrUint32Ser(ptr, len, (CsrUint32) primitive->profile.credentials.credential.wapi.caCertificateLength);
            if (primitive->profile.credentials.credential.wapi.caCertificateLength)
            {
                CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wapi.caCertificate, ((CsrUint16) (primitive->profile.credentials.credential.wapi.caCertificateLength)));
            }
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wep128Key.wepAuthType);
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.wep128Key.selectedWepKey);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key1, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key2, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key3, ((CsrUint16) (13)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep128Key.key4, ((CsrUint16) (13)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wpaPsk.encryptionMode);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wpaPsk.psk, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.openSystem.empty);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->profile.credentials.credential.wep64Key.wepAuthType);
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->profile.credentials.credential.wep64Key.selectedWepKey);
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key1, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key2, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key3, ((CsrUint16) (5)));
            CsrMemCpySer(ptr, len, (const void *) primitive->profile.credentials.credential.wep64Key.key4, ((CsrUint16) (5)));
            break;
        default:
            break;
    }
    return(ptr);
}


void* CsrWifiNmeProfileUpdateIndDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeProfileUpdateInd *primitive = (CsrWifiNmeProfileUpdateInd *) CsrPmemAlloc(sizeof(CsrWifiNmeProfileUpdateInd));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrMemCpyDes(primitive->profile.profileIdentity.bssid.a, buffer, &offset, ((CsrUint16) (6)));
    CsrMemCpyDes(primitive->profile.profileIdentity.ssid.ssid, buffer, &offset, ((CsrUint16) (32)));
    CsrUint8Des((CsrUint8 *) &primitive->profile.profileIdentity.ssid.length, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.wmmQosInfoMask, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.bssType, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.channelNo, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.ccxOptionsMask, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->profile.cloakedSsid, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credentialType, buffer, &offset);
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.eapMethodMask, buffer, &offset);
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.authMode, buffer, &offset);
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.userName, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.userPassword, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.authServerUserIdentity, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.clientCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.clientCertificateLength)
            {
                primitive->profile.credentials.credential.eap.clientCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.clientCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.clientCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.clientCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.clientCertificate = NULL;
            }
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)
            {
                primitive->profile.credentials.credential.eap.certificateAuthorityCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.certificateAuthorityCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.certificateAuthorityCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.certificateAuthorityCertificate = NULL;
            }
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.eap.privateKeyLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.privateKeyLength)
            {
                primitive->profile.credentials.credential.eap.privateKey = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.privateKeyLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.privateKey, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.privateKeyLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.privateKey = NULL;
            }
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.privateKeyPassword, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.sessionLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.sessionLength)
            {
                primitive->profile.credentials.credential.eap.session = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.sessionLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.session, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.sessionLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.session = NULL;
            }
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.eap.allowPacProvisioning, buffer, &offset);
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.eap.pacLength, buffer, &offset);
            if (primitive->profile.credentials.credential.eap.pacLength)
            {
                primitive->profile.credentials.credential.eap.pac = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.eap.pacLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.eap.pac, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.eap.pacLength)));
            }
            else
            {
                primitive->profile.credentials.credential.eap.pac = NULL;
            }
            CsrCharStringDes(&primitive->profile.credentials.credential.eap.pacPassword, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapiPassphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wapiPassphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpa2Passphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wpa2Passphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpa2Psk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wpa2Psk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapiPsk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wapiPsk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpaPassphrase.encryptionMode, buffer, &offset);
            CsrCharStringDes(&primitive->profile.credentials.credential.wpaPassphrase.passphrase, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.wapi.certificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.certificateLength)
            {
                primitive->profile.credentials.credential.wapi.certificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.certificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.certificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.certificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.certificate = NULL;
            }
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wapi.privateKeyLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.privateKeyLength)
            {
                primitive->profile.credentials.credential.wapi.privateKey = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.privateKeyLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.privateKey, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.privateKeyLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.privateKey = NULL;
            }
            CsrUint32Des((CsrUint32 *) &primitive->profile.credentials.credential.wapi.caCertificateLength, buffer, &offset);
            if (primitive->profile.credentials.credential.wapi.caCertificateLength)
            {
                primitive->profile.credentials.credential.wapi.caCertificate = (CsrUint8 *)CsrPmemAlloc(primitive->profile.credentials.credential.wapi.caCertificateLength);
                CsrMemCpyDes(primitive->profile.credentials.credential.wapi.caCertificate, buffer, &offset, ((CsrUint16) (primitive->profile.credentials.credential.wapi.caCertificateLength)));
            }
            else
            {
                primitive->profile.credentials.credential.wapi.caCertificate = NULL;
            }
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP128:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wep128Key.wepAuthType, buffer, &offset);
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.wep128Key.selectedWepKey, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key1, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key2, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key3, buffer, &offset, ((CsrUint16) (13)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep128Key.key4, buffer, &offset, ((CsrUint16) (13)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PSK:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wpaPsk.encryptionMode, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wpaPsk.psk, buffer, &offset, ((CsrUint16) (32)));
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_OPEN_SYSTEM:
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.openSystem.empty, buffer, &offset);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WEP64:
            CsrUint16Des((CsrUint16 *) &primitive->profile.credentials.credential.wep64Key.wepAuthType, buffer, &offset);
            CsrUint8Des((CsrUint8 *) &primitive->profile.credentials.credential.wep64Key.selectedWepKey, buffer, &offset);
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key1, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key2, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key3, buffer, &offset, ((CsrUint16) (5)));
            CsrMemCpyDes(primitive->profile.credentials.credential.wep64Key.key4, buffer, &offset, ((CsrUint16) (5)));
            break;
        default:
            break;
    }

    return primitive;
}


void CsrWifiNmeProfileUpdateIndSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeProfileUpdateInd *primitive = (CsrWifiNmeProfileUpdateInd *) voidPrimitivePointer;
    switch (primitive->profile.credentials.credentialType)
    {
        case CSR_WIFI_NME_CREDENTIAL_TYPE_8021X:
            CsrPmemFree(primitive->profile.credentials.credential.eap.userName);
            CsrPmemFree(primitive->profile.credentials.credential.eap.userPassword);
            CsrPmemFree(primitive->profile.credentials.credential.eap.authServerUserIdentity);
            CsrPmemFree(primitive->profile.credentials.credential.eap.clientCertificate);
            CsrPmemFree(primitive->profile.credentials.credential.eap.certificateAuthorityCertificate);
            CsrPmemFree(primitive->profile.credentials.credential.eap.privateKey);
            CsrPmemFree(primitive->profile.credentials.credential.eap.privateKeyPassword);
            CsrPmemFree(primitive->profile.credentials.credential.eap.session);
            CsrPmemFree(primitive->profile.credentials.credential.eap.pac);
            CsrPmemFree(primitive->profile.credentials.credential.eap.pacPassword);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wapiPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA2_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wpa2Passphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WPA_PASSPHRASE:
            CsrPmemFree(primitive->profile.credentials.credential.wpaPassphrase.passphrase);
            break;
        case CSR_WIFI_NME_CREDENTIAL_TYPE_WAPI:
            CsrPmemFree(primitive->profile.credentials.credential.wapi.certificate);
            CsrPmemFree(primitive->profile.credentials.credential.wapi.privateKey);
            CsrPmemFree(primitive->profile.credentials.credential.wapi.caCertificate);
            break;
        default:
            break;
    }
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeProfileDisconnectIndSizeof(void *msg)
{
    CsrWifiNmeProfileDisconnectInd *primitive = (CsrWifiNmeProfileDisconnectInd *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 15) */
    bufferSize += 2; /* CsrUint16 primitive->interfaceTag */
    bufferSize += 1; /* CsrUint8 primitive->connectAttemptsCount */
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->connectAttemptsCount; i1++)
        {
            bufferSize += 6; /* CsrUint8 primitive->connectAttempts[i1].bssid.a[6] */
            bufferSize += 2; /* CsrResult primitive->connectAttempts[i1].status */
            bufferSize += 1; /* CsrWifiNmeSecError primitive->connectAttempts[i1].securityError */
        }
    }
    return bufferSize;
}


CsrUint8* CsrWifiNmeProfileDisconnectIndSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeProfileDisconnectInd *primitive = (CsrWifiNmeProfileDisconnectInd *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint16Ser(ptr, len, (CsrUint16) primitive->interfaceTag);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->connectAttemptsCount);
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->connectAttemptsCount; i1++)
        {
            CsrMemCpySer(ptr, len, (const void *) primitive->connectAttempts[i1].bssid.a, ((CsrUint16) (6)));
            CsrUint16Ser(ptr, len, (CsrUint16) primitive->connectAttempts[i1].status);
            CsrUint8Ser(ptr, len, (CsrUint8) primitive->connectAttempts[i1].securityError);
        }
    }
    return(ptr);
}


void* CsrWifiNmeProfileDisconnectIndDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeProfileDisconnectInd *primitive = (CsrWifiNmeProfileDisconnectInd *) CsrPmemAlloc(sizeof(CsrWifiNmeProfileDisconnectInd));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint16Des((CsrUint16 *) &primitive->interfaceTag, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->connectAttemptsCount, buffer, &offset);
    primitive->connectAttempts = NULL;
    if (primitive->connectAttemptsCount)
    {
        primitive->connectAttempts = (CsrWifiNmeConnectAttempt *)CsrPmemAlloc(sizeof(CsrWifiNmeConnectAttempt) * primitive->connectAttemptsCount);
    }
    {
        CsrUint16 i1;
        for (i1 = 0; i1 < primitive->connectAttemptsCount; i1++)
        {
            CsrMemCpyDes(primitive->connectAttempts[i1].bssid.a, buffer, &offset, ((CsrUint16) (6)));
            CsrUint16Des((CsrUint16 *) &primitive->connectAttempts[i1].status, buffer, &offset);
            CsrUint8Des((CsrUint8 *) &primitive->connectAttempts[i1].securityError, buffer, &offset);
        }
    }

    return primitive;
}


void CsrWifiNmeProfileDisconnectIndSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeProfileDisconnectInd *primitive = (CsrWifiNmeProfileDisconnectInd *) voidPrimitivePointer;
    CsrPmemFree(primitive->connectAttempts);
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeSimGsmAuthIndSizeof(void *msg)
{
    CsrWifiNmeSimGsmAuthInd *primitive = (CsrWifiNmeSimGsmAuthInd *) msg;
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 5) */
    bufferSize += 1;                      /* CsrUint8 primitive->randsLength */
    bufferSize += primitive->randsLength; /* CsrUint8 primitive->rands */
    return bufferSize;
}


CsrUint8* CsrWifiNmeSimGsmAuthIndSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeSimGsmAuthInd *primitive = (CsrWifiNmeSimGsmAuthInd *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrUint8Ser(ptr, len, (CsrUint8) primitive->randsLength);
    if (primitive->randsLength)
    {
        CsrMemCpySer(ptr, len, (const void *) primitive->rands, ((CsrUint16) (primitive->randsLength)));
    }
    return(ptr);
}


void* CsrWifiNmeSimGsmAuthIndDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeSimGsmAuthInd *primitive = (CsrWifiNmeSimGsmAuthInd *) CsrPmemAlloc(sizeof(CsrWifiNmeSimGsmAuthInd));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrUint8Des((CsrUint8 *) &primitive->randsLength, buffer, &offset);
    if (primitive->randsLength)
    {
        primitive->rands = (CsrUint8 *)CsrPmemAlloc(primitive->randsLength);
        CsrMemCpyDes(primitive->rands, buffer, &offset, ((CsrUint16) (primitive->randsLength)));
    }
    else
    {
        primitive->rands = NULL;
    }

    return primitive;
}


void CsrWifiNmeSimGsmAuthIndSerFree(void *voidPrimitivePointer)
{
    CsrWifiNmeSimGsmAuthInd *primitive = (CsrWifiNmeSimGsmAuthInd *) voidPrimitivePointer;
    CsrPmemFree(primitive->rands);
    CsrPmemFree(primitive);
}


CsrSize CsrWifiNmeSimUmtsAuthIndSizeof(void *msg)
{
    CsrSize bufferSize = 2;

    /* Calculate the Size of the Serialised Data. Could be more efficient (Try 35) */
    bufferSize += 16; /* CsrUint8 primitive->rand[16] */
    bufferSize += 16; /* CsrUint8 primitive->autn[16] */
    return bufferSize;
}


CsrUint8* CsrWifiNmeSimUmtsAuthIndSer(CsrUint8 *ptr, CsrSize *len, void *msg)
{
    CsrWifiNmeSimUmtsAuthInd *primitive = (CsrWifiNmeSimUmtsAuthInd *)msg;
    *len = 0;
    CsrUint16Ser(ptr, len, primitive->common.type);
    CsrMemCpySer(ptr, len, (const void *) primitive->rand, ((CsrUint16) (16)));
    CsrMemCpySer(ptr, len, (const void *) primitive->autn, ((CsrUint16) (16)));
    return(ptr);
}


void* CsrWifiNmeSimUmtsAuthIndDes(CsrUint8 *buffer, CsrSize length)
{
    CsrWifiNmeSimUmtsAuthInd *primitive = (CsrWifiNmeSimUmtsAuthInd *) CsrPmemAlloc(sizeof(CsrWifiNmeSimUmtsAuthInd));
    CsrSize offset;
    offset = 0;

    CsrUint16Des(&primitive->common.type, buffer, &offset);
    CsrMemCpyDes(primitive->rand, buffer, &offset, ((CsrUint16) (16)));
    CsrMemCpyDes(primitive->autn, buffer, &offset, ((CsrUint16) (16)));

    return primitive;
}


#endif /* CSR_WIFI_NME_ENABLE */
