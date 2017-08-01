/*
 *
 * Copyright (C) 2012 by Cambridge Silicon Radio Ltd.
 *
 * Refer to LICENSE.txt included with this source code for details on
 * the license terms.
 *
 */

#include "csr_pmem.h"
#include "csr_wifi_lib.h"

CsrWifiFsmEvent* CsrWifiEvent_struct(CsrUint16 primtype, CsrUint16 msgtype, CsrSchedQid dst, CsrSchedQid src)
{
    CsrWifiFsmEvent *prim = (CsrWifiFsmEvent *) CsrPmemAlloc(sizeof(CsrWifiFsmEvent));
    CsrWifiFsmEventInit(prim, primtype, msgtype, dst, src);
    return prim;
}


CsrWifiEventCsrUint8* CsrWifiEventCsrUint8_struct(CsrUint16 primtype, CsrUint16 msgtype, CsrSchedQid dst, CsrSchedQid src, CsrUint8 value)
{
    CsrWifiEventCsrUint8 *prim = (CsrWifiEventCsrUint8 *) CsrPmemAlloc(sizeof(CsrWifiEventCsrUint8));
    CsrWifiFsmEventInit(&prim->common, primtype, msgtype, dst, src);
    prim->value = value;
    return prim;
}


CsrWifiEventCsrUint16* CsrWifiEventCsrUint16_struct(CsrUint16 primtype, CsrUint16 msgtype, CsrSchedQid dst, CsrSchedQid src, CsrUint16 value)
{
    CsrWifiEventCsrUint16 *prim = (CsrWifiEventCsrUint16 *) CsrPmemAlloc(sizeof(CsrWifiEventCsrUint16));
    CsrWifiFsmEventInit(&prim->common, primtype, msgtype, dst, src);
    prim->value = value;
    return prim;
}


CsrWifiEventCsrUint32* CsrWifiEventCsrUint32_struct(CsrUint16 primtype, CsrUint16 msgtype, CsrSchedQid dst, CsrSchedQid src, CsrUint32 value)
{
    CsrWifiEventCsrUint32 *prim = (CsrWifiEventCsrUint32 *) CsrPmemAlloc(sizeof(CsrWifiEventCsrUint32));
    CsrWifiFsmEventInit(&prim->common, primtype, msgtype, dst, src);
    prim->value = value;
    return prim;
}


CsrWifiEventCsrUint16CsrUint8* CsrWifiEventCsrUint16CsrUint8_struct(CsrUint16 primtype, CsrUint16 msgtype, CsrSchedQid dst, CsrSchedQid src, CsrUint16 value16, CsrUint8 value8)
{
    CsrWifiEventCsrUint16CsrUint8 *prim = (CsrWifiEventCsrUint16CsrUint8 *) CsrPmemAlloc(sizeof(CsrWifiEventCsrUint16CsrUint8));
    CsrWifiFsmEventInit(&prim->common, primtype, msgtype, dst, src);
    prim->value16 = value16;
    prim->value8 = value8;
    return prim;
}


