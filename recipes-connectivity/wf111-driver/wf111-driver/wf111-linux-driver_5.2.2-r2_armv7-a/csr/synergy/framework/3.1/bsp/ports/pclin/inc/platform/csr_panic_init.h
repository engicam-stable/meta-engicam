#ifndef CSR_PANIC_INIT_H__
#define CSR_PANIC_INIT_H__
/*****************************************************************************

            (c) Cambridge Silicon Radio Limited 2010
            All rights reserved and confidential information of CSR

            Refer to LICENSE.txt included with this source for details
            on the license terms.

*****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef void (*CsrPanicHandler)(CsrUint8 tech, CsrUint16 reason, const char *p);

/* Initial registration of external panic handler */
void CsrPanicInit(CsrPanicHandler cb);

#ifdef __cplusplus
}
#endif

#endif /* CSR_PANIC_INIT_H__ */
