#!/bin/sh
# Copyright (C) 2000-2013 by Bluegiga Technologies
# 
#  A script checks the WF111 driver is properly installed
#

echo ""
echo "WF111 driver check script version 4"

echo ""
echo "--------------------------------------------"
echo "Linux version:"
echo "--------------------------------------------"
echo "Check the Linux kernel version is 2.6 to 3.2"
echo "--------------------------------------------"
uname -a

echo ""
echo "--------------------------------------------"
echo "Linux kernel options:"
echo "--------------------------------------------"
echo "Check that the following options are enabled:"
echo "CONFIG_WIRELESS_EXT, CONFIG_MODULES,"
echo "CONFIG_FW_LOADER and CONFIG_MMC"
echo "--------------------------------------------"
grep "CONFIG_WIRELESS_EXT=" /boot/config-$(uname -r)
grep "CONFIG_MODULES=" /boot/config-$(uname -r)
grep "CONFIG_FW_LOADER=" /boot/config-$(uname -r)
grep "CONFIG_MMC=" /boot/config-$(uname -r)

echo ""
echo "------------------------------------------------------------"
echo "Linux firmware loading support:"
echo "------------------------------------------------------------"
echo "Checking option ENABLE_FEATURE_MDEV_LOAD_FIRMWARE is enabled"
echo "Note: Valid for a busybox enabled system only and firmware"
echo "loading can be handled by UDEV as well."
echo "------------------------------------------------------------"
grep "ENABLE_FEATURE_MDEV_LOAD_FIRMWARE=" /boot/config-$(uname -r)

echo ""
echo "----------------------------------------------------------------------------"
echo "Linux wireless options:"
echo "----------------------------------------------------------------------------"
echo "Checking wireless tools and WPA_supplicant versions"
echo "wireless tools must be version 28 or newer and wpa supplicant 0.7.3 or newer"
echo "----------------------------------------------------------------------------"
iwconfig -v
wpa_supplicant -v

echo ""
echo "----------------------"
echo "UDEVD version:"
echo "----------------------"
echo "Checking UDEVD version"
echo "----------------------"
udevd --version

echo ""
echo "------------------"
echo "WF111 device files"
echo "------------------"
ls -l /dev/unifi*

echo ""
echo "------------------------------------------------"
echo "WF111 firmware files"
echo "------------------------------------------------"
echo "Check the firmware files are copied correctly to"
echo "/lib/firmware/unifi-sdio/ folder"
echo "------------------------------------------------"
ls -la /lib/firmware/unifi-sdio/

echo ""
echo "------------------------------------------------------------------"
echo "WF111 user space binaries"
echo "------------------------------------------------------------------"
echo "Check the firmware files are copied correctly to /usr/sbin/ folder"
echo "------------------------------------------------------------------"
ls -la /usr/sbin/unifi*

echo ""
echo "------------------------------"
echo "MD5 hashes of the driver files"
echo "------------------------------"
md5sum /lib/firmware/unifi-sdio/* /usr/sbin/unifi*

echo ""
echo "--------------------------------------------------------------"
echo "Cheking kernel modules"
echo "--------------------------------------------------------------"
echo "Check the WF111 kernel module is properly installed and loaded"
echo "--------------------------------------------------------------"
modprobe -ls | grep unifi
lsmod | grep unifi

echo ""
echo "------------------------------------------"
echo "Busybox version and all enabled applets"
echo "------------------------------------------"
echo "Check the busybox version is 1.11 or newer"
echo "------------------------------------------"
busybox

echo ""
echo "--------------------------------------------------------------"
echo "Trying to run unifi_helper application"
echo "--------------------------------------------------------------"
/usr/sbin/unifi_helper --help

echo
echo "-------------------------"
echo "All loaded kernel modules"
echo "-------------------------"
lsmod

echo ""
echo "------------------"
echo "System information"
echo "------------------"
cat /proc/cpuinfo

echo ""
echo "----------------------"
echo "Kernel hotplug handler"
echo "----------------------"
cat /proc/sys/kernel/hotplug

echo ""
echo "-------------"
echo "Process list"
echo "-------------"
ps axu 2>/dev/null || ps

echo ""
echo "-----------------------------"
echo "Output of /proc/driver/unifi*"
echo "-----------------------------"
cat /proc/driver/unifi*

echo ""
echo "------------------"
echo "Kernel buffer ring"
echo "------------------"
dmesg

echo ""
echo "-------------"
echo "Syslog output"
echo "-------------"
cat /var/log/messages /var/log/syslog

echo ""
echo "------------------------"
echo "Output of wireless tools"
echo "------------------------"
iwconfig
iwlist wlan0 scan
