/*
 * ---------------------------------------------------------------------------
 *  FILE:     firmware.c
 *
 *  PURPOSE:
 *      Implements the f/w related HIP core lib API.
 *      It is part of the porting exercise in Linux.
 *
 *      Also, it contains example code for reading the loader and f/w files
 *      from the userspace and starting the SME in Linux.
 *
 * Copyright (C) 2005-2009 by Cambridge Silicon Radio Ltd.
 *
 * Refer to LICENSE.txt included with this source code for details on
 * the license terms.
 *
 * ---------------------------------------------------------------------------
 */
#include <linux/kmod.h>
#include <linux/vmalloc.h>
#include <linux/firmware.h>
#include <asm/uaccess.h>
#include "csr_wifi_hip_unifi.h"
#include "csr_wifi_hip_unifi_udi.h"
#include "unifiio.h"
#include "unifi_priv.h"

/*
 * ---------------------------------------------------------------------------
 *
 *      F/W download. Part of the HIP core API
 *
 * ---------------------------------------------------------------------------
 */


/*
 * ---------------------------------------------------------------------------
 *  unifi_fw_read_start
 *
 *      Returns a structure to be passed in unifi_fw_read().
 *      This structure is an OS specific description of the f/w file.
 *      In the linux implementation it is a buffer with the f/w and its' length.
 *      The HIP driver calls this functions to request for the loader or
 *      the firmware file.
 *      The structure pointer can be freed when unifi_fw_read_stop() is called.
 *
 *  Arguments:
 *      ospriv          Pointer to driver context.
 *      is_fw           Type of firmware to retrieve
 *      info            Versions information. Can be used to determine
 *                      the appropriate f/w file to load.
 *
 *  Returns:
 *      O on success, non-zero otherwise.
 *
 * ---------------------------------------------------------------------------
 */
void* unifi_fw_read_start(void *ospriv, CsrInt8 is_fw, const card_info_t *info)
{
    unifi_priv_t *priv = (unifi_priv_t *)ospriv;
    CSR_UNUSED(info);

    func_enter();

    if (is_fw == UNIFI_FW_STA)
    {
        /* F/w may have been released after a previous successful download. */
        if (priv->fw_sta.dl_data == NULL)
        {
            unifi_trace(priv, UDBG2, "Attempt reload of sta f/w\n");
            uf_request_firmware_files(priv, UNIFI_FW_STA);
        }
        /* Set up callback struct for readfunc() */
        if (priv->fw_sta.dl_data != NULL)
        {
            func_exit();
            return &priv->fw_sta;
        }
    }
    else
    {
        unifi_error(priv, "downloading firmware... unknown request: %d\n", is_fw);
    }

    func_exit();
    return NULL;
} /* unifi_fw_read_start() */


/*
 * ---------------------------------------------------------------------------
 *  unifi_fw_read_stop
 *
 *      Called when the HIP driver has finished using the loader or
 *      the firmware file.
 *      The firmware buffer may be released now.
 *
 *  Arguments:
 *      ospriv          Pointer to driver context.
 *      dlpriv          The pointer returned by unifi_fw_read_start()
 *
 * ---------------------------------------------------------------------------
 */
void unifi_fw_read_stop(void *ospriv, void *dlpriv)
{
    unifi_priv_t *priv = (unifi_priv_t *)ospriv;
    struct dlpriv *dl_struct = (struct dlpriv *)dlpriv;
    func_enter();

    if (dl_struct != NULL)
    {
        if (dl_struct->dl_data != NULL)
        {
            unifi_trace(priv, UDBG2, "Release f/w buffer %p, %d bytes\n",
                        dl_struct->dl_data, dl_struct->dl_len);
        }
        uf_release_firmware(priv, dl_struct);
    }

    func_exit();
} /* unifi_fw_read_stop() */


/*
 * ---------------------------------------------------------------------------
 *  unifi_fw_open_buffer
 *
 *  Returns a handle for a buffer dynamically allocated by the driver,
 *  e.g. into which a firmware file may have been converted from another format
 *  which is the case with some production test images.
 *
 *  The handle may then be used by unifi_fw_read() to access the contents of
 *  the buffer.
 *
 *  Arguments:
 *      ospriv          Pointer to driver context.
 *      fwbuf           Buffer containing firmware image
 *      len             Length of buffer in bytes
 *
 *  Returns
 *      Handle for buffer, or NULL on error
 * ---------------------------------------------------------------------------
 */
void* unifi_fw_open_buffer(void *ospriv, void *fwbuf, CsrUint32 len)
{
    unifi_priv_t *priv = (unifi_priv_t *)ospriv;
    func_enter();

    if (fwbuf == NULL)
    {
        func_exit();
        return NULL;
    }
    priv->fw_conv.dl_data = fwbuf;
    priv->fw_conv.dl_len = len;
    priv->fw_conv.fw_desc = NULL;   /* No OS f/w resource is associated */

    func_exit();
    return &priv->fw_conv;
}


/*
 * ---------------------------------------------------------------------------
 *  unifi_fw_close_buffer
 *
 *  Releases any handle for a buffer dynamically allocated by the driver,
 *  e.g. into which a firmware file may have been converted from another format
 *  which is the case with some production test images.
 *
 *
 *  Arguments:
 *      ospriv          Pointer to driver context.
 *      fwbuf           Buffer containing firmware image
 *
 *  Returns
 *      Handle for buffer, or NULL on error
 * ---------------------------------------------------------------------------
 */
void unifi_fw_close_buffer(void *ospriv, void *fwbuf)
{
}


/*
 * ---------------------------------------------------------------------------
 *  unifi_fw_read
 *
 *      The HIP driver calls this function to ask for a part of the loader or
 *      the firmware file.
 *
 *  Arguments:
 *      ospriv          Pointer to driver context.
 *      arg             The pointer returned by unifi_fw_read_start().
 *      offset          The offset in the file to return from.
 *      buf             A buffer to store the requested data.
 *      len             The size of the buf and the size of the requested data.
 *
 *  Returns
 *      The number of bytes read from the firmware image, or -ve on error
 * ---------------------------------------------------------------------------
 */
CsrInt32 unifi_fw_read(void *ospriv, void *arg, CsrUint32 offset, void *buf, CsrUint32 len)
{
    const struct dlpriv *dlpriv = arg;

    if (offset >= dlpriv->dl_len)
    {
        /* at end of file */
        return 0;
    }

    if ((offset + len) > dlpriv->dl_len)
    {
        /* attempt to read past end of file */
        return -1;
    }

    memcpy(buf, dlpriv->dl_data + offset, len);

    return len;
} /* unifi_fw_read() */


#define UNIFIHELPER_INIT_MODE_SMEEMB    0
#define UNIFIHELPER_INIT_MODE_SMEUSER   2
#define UNIFIHELPER_INIT_MODE_NATIVE    1

/*
 * ---------------------------------------------------------------------------
 *  uf_run_unifihelper_cleanup
 *
 *      Function used to deallocate argv in the sp_info structure.
 *
 *  Arguments:
 *      sp_info         Pointer to structure allocated by call_usermodehelper_setup().
 *
 *  Returns:
 *      None.
 * ---------------------------------------------------------------------------
 */
#if (LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 34) || defined(CSR_WIFI_DRIVER_COMPAT_OLD_USERMODEHELPER_API)) && !defined(CSR_WIFI_DRIVER_COMPAT_NEW_USERMODEHELPER_API)
static void uf_run_unifihelper_cleanup(char **argv, char **envp)
{
    if (!argv)
    {
        printk(KERN_ERR "unifi: uf_run_unifihelper_cleanup: argv is null");
        return;
    }

    printk(KERN_INFO "unifi: uf_run_unifihelper_cleanup");
    argv_free(argv);
}


#elif LINUX_VERSION_CODE < KERNEL_VERSION(3, 10, 0)
static void uf_run_unifihelper_cleanup(struct subprocess_info *sp_info)
{
    if (!sp_info)
    {
        printk(KERN_ERR "unifi: uf_run_unifihelper_cleanup: sp_info is null");
        return;
    }
    if (!sp_info->argv)
    {
        printk(KERN_ERR "unifi: uf_run_unifihelper_cleanup: argv is null");
        return;
    }

    printk(KERN_INFO "unifi: uf_run_unifihelper_cleanup");
    argv_free(sp_info->argv);
}


#endif

/*
 * ---------------------------------------------------------------------------
 *  uf_run_unifihelper
 *
 *      Ask userspace to send us firmware for download by running
 *      '/usr/sbin/unififw'.
 *      The same script starts the SME userspace application.
 *      Derived from net_run_sbin_hotplug().
 *
 *  Arguments:
 *      priv            Pointer to OS private struct.
 *
 *  Returns:
 *      None.
 * ---------------------------------------------------------------------------
 */
int uf_run_unifihelper(unifi_priv_t *priv)
{
#if (defined CONFIG_HOTPLUG) || (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 11, 0))
#ifdef ANDROID_BUILD
    char *prog = "/system/bin/unififw";
    return 0;
#else
    char *prog = "/usr/sbin/unififw";
#endif /* ANDROID_BUILD */

    static char *envp[] = { "HOME=/", "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
    const int exec_string_buffer_len = 64;
    char **argv, argv_str[exec_string_buffer_len];
    const int exec_string_args = 3;
    int argc, r, len;

#if (defined CSR_SME_USERSPACE)
    int user = UNIFIHELPER_INIT_MODE_SMEUSER;
#else
    int user = UNIFIHELPER_INIT_MODE_NATIVE;
#endif /* CSR_SME_USERSPACE */

#if (defined CSR_SME_USERSPACE) && (!defined CSR_SUPPORT_WEXT)
    unifi_trace(priv, UDBG1, "SME userspace build: run unifi_helper manually\n");
    return 0;
#endif

    unifi_trace(priv, UDBG1, "starting %s\n", prog);

    len = snprintf(argv_str, exec_string_buffer_len, "%s %d %d", prog, priv->instance, user);

    if (len >= exec_string_buffer_len)
    {
        /* snprintf() returns a value of buffer size of greater if it had to truncate the format string. */
        unifi_trace(priv, UDBG0, "unifi%d: exec string buffer insufficient (buffer size=%d, actual string=%d)\n",
                    priv->instance, exec_string_buffer_len, len);
        return -1;
    }

    /* Kernel library function argv_split() will allocate memory for argv. */
    argc = 0;
    argv = argv_split(GFP_ATOMIC, argv_str, &argc);
    if (!argv)
    {
        unifi_trace(priv, UDBG0, "unifi%d: failed to allocate argv for userspace helper\n", priv->instance);
        return -1;
    }
    unifi_trace(priv, UDBG1, "unifi: argv allocated 0x%p\n", argv);

    if (argc != exec_string_args)
    {
        unifi_trace(priv, UDBG1, "unifi%d: exec string has the wrong number of arguments (has %d, should be %d)\n",
                    priv->instance, argc, exec_string_args);
        argv_free(argv);
        return -1;
    }

    unifi_trace(priv, UDBG1, "unifi%d: running %s %s %s\n", priv?priv->instance : 0,  argv[0], argv[1], argv[2]);

    #if LINUX_VERSION_CODE < KERNEL_VERSION(3, 5, 0)
    {
        struct subprocess_info *sp_info;

        /* Allocate sp_info and initialise pointers to argv and envp. */
        sp_info = call_usermodehelper_setup(argv[0], argv, envp, GFP_KERNEL);
        if (!sp_info)
        {
            unifi_error(priv, "unifi%d: call_usermodehelper_setup() failed\n", priv->instance);
            argv_free(argv);
            return -1;
        }
        /*
        * Set the cleanup function for the memory allocated for argv. This function
        * is called according to the UMH flag passed to call_usermodehelper_exec().
        * Note: The USE_OLD_USERMODEHELPER_API allows the configuration system to force
        * the driver to use the old api - this only appears to be necessary for patched
        * versions of 2.6.34 where the KERNEL_VERSION is not enough information to make
        * a decision.
        */
        #if (LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 34) || defined(CSR_WIFI_DRIVER_COMPAT_OLD_USERMODEHELPER_API)) && !defined(CSR_WIFI_DRIVER_COMPAT_NEW_USERMODEHELPER_API)
        call_usermodehelper_setcleanup(sp_info, uf_run_unifihelper_cleanup);
        #else
        call_usermodehelper_setfns(sp_info, NULL, uf_run_unifihelper_cleanup, NULL);
        #endif

        /*
        * Put sp_info into work queue for processing by khelper.
        * Beware that UMH_WAIT_EXEC means that the calling context
        * for this function will be blocked until the khelper thread
        * has successfully created a new thread for the execution
        * of the user space process. It does not mean that the calling
        * thread will be blocked until the user space process has actually
        * been executed.
        */
        r = call_usermodehelper_exec(sp_info, UMH_WAIT_EXEC);
        if (r != 0)
        {
            /*
            * call_usermodehelper_exec() will free sp_info and call any cleanup function
            * whether it succeeds or fails, so do not free argv.
            */
            unifi_error(priv, "unifi%d: call_usermodehelper() failed with %d\n", priv->instance, r);
        }
    }
    #elif LINUX_VERSION_CODE < KERNEL_VERSION(3, 10, 0)
    r = call_usermodehelper_fns(argv[0], argv, envp, UMH_WAIT_EXEC, NULL, uf_run_unifihelper_cleanup, NULL);
    #else
    r = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
    #endif

    return r;
#else
    unifi_trace(priv, UDBG1, "Can't automatically download firmware because kernel does not have HOTPLUG\n");
    return -1;
#endif
} /* uf_run_unifihelper() */


/*
 * ---------------------------------------------------------------------------
 *  uf_request_firmware_files
 *
 *      Get the firmware files from userspace.
 *
 *  Arguments:
 *      priv            Pointer to OS private struct.
 *      is_fw           type of firmware to load (UNIFI_FW_STA/LOADER)
 *
 *  Returns:
 *      None.
 * ---------------------------------------------------------------------------
 */
int uf_request_firmware_files(unifi_priv_t *priv, int is_fw)
{
    /* uses the default method to get the firmware */
    const struct firmware *fw_entry;
    int postfix;
#define UNIFI_MAX_FW_PATH_LEN       32
    char fw_name[UNIFI_MAX_FW_PATH_LEN];
    int r;

#if (defined CSR_SUPPORT_SME) && (defined CSR_SUPPORT_WEXT)
    if (priv->mib_data.length)
    {
        vfree(priv->mib_data.data);
        priv->mib_data.data = NULL;
        priv->mib_data.length = 0;
    }
#endif /* CSR_SUPPORT_SME && CSR_SUPPORT_WEXT*/

    postfix = priv->instance;

    if (is_fw == UNIFI_FW_STA)
    {
        /* Free kernel buffer and reload */
        uf_release_firmware(priv, &priv->fw_sta);
#ifdef CSR_WIFI_SPLIT_PATCH
        scnprintf(fw_name, UNIFI_MAX_FW_PATH_LEN, "unifi-sdio/%s",
                  (priv->interfacePriv[0]->patchMode)?"ap.xbv" : "staonly.xbv");
#else
        scnprintf(fw_name, UNIFI_MAX_FW_PATH_LEN, "unifi-sdio/%s",
                  "sta.xbv");
#endif
        r = request_firmware(&fw_entry, fw_name, priv->unifi_device);
        if (r == 0)
        {
            priv->fw_sta.dl_data = fw_entry->data;
            priv->fw_sta.dl_len = fw_entry->size;
            priv->fw_sta.fw_desc = (void *)fw_entry;
        }
        else
        {
            unifi_trace(priv, UDBG2, "Firmware file not available\n");
        }
    }

    return 0;
} /* uf_request_firmware_files() */


/*
 * ---------------------------------------------------------------------------
 *  uf_release_firmware_files
 *
 *      Release all buffers used to store firmware files
 *
 *  Arguments:
 *      priv            Pointer to OS private struct.
 *
 *  Returns:
 *      None.
 * ---------------------------------------------------------------------------
 */
int uf_release_firmware_files(unifi_priv_t *priv)
{
    uf_release_firmware(priv, &priv->fw_sta);

    return 0;
}


/*
 * ---------------------------------------------------------------------------
 *  uf_release_firmware
 *
 *      Release specific buffer used to store firmware
 *
 *  Arguments:
 *      priv            Pointer to OS private struct.
 *      to_free         Pointer to specific buffer to release
 *
 *  Returns:
 *      None.
 * ---------------------------------------------------------------------------
 */
int uf_release_firmware(unifi_priv_t *priv, struct dlpriv *to_free)
{
    if (to_free != NULL)
    {
        if (to_free->fw_desc != NULL)
        {
            release_firmware((const struct firmware *)to_free->fw_desc);
        }
        to_free->fw_desc = NULL;
        to_free->dl_data = NULL;
        to_free->dl_len = 0;
    }
    return 0;
}


