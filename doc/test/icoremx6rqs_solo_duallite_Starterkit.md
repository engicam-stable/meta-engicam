**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** Startekit
**SOM Type:** icoremx6solo/duallite rqs

--------------------------------------------------------------------------------------------------------

**U-BOOT**

U-Boot 2016.07

**Version:** Engicam Yocto U-Boot 3.00

**Tests**

| Status  |  Test |
|---------|-------|
| OK |Emmc  Enviroment saving |
| OK |Sdcard  Enviroment saving |
| OK |Ethernet  |
| OK |Boot from emmc   |
| OK |Boot from sdcard  |
| NO |U-boot logo   |


**Tests NOTE:**

**Emmc Enviroment saving**

setenv serverip 192.168.2.93
saveenv
reset board
printenv serverip

**Sdcard  Enviroment saving**

setenv serverip 192.168.2.69
saveenv
Saving
reset board
printenv  serverip

**Ethernet**

ping 192.168.2.254

**Boot from emmc**

Non inserire il jumper su JM2
saveenv
Saving Environment to MMC...
Writing to MMC(0)... done

**Boot from sdcard**

Inserire il jumper su JM2
saveenv
Environment to MMC...
Writing to MMC(1)... done

**U-boot logo**

no logo showed

--------------------------------------------------------------------------------------------------------
**Kernel Linux**

| Status  |  Test |
|---------|-------|
| OK |Ethernet|
| OK |MAC Address|
| OK |USB|
| OK |MMC card|
| OK |Display|
| NOT PRESENT |Second Ethernet|
| NOT PRESENT |CMOS Input|
| NOT PRESENT |UART 232|
| NOT PRESENT |UART 485|
| OK |Linux Console|
| OK |CANBUS1|
| NOT PRESENT |CANBUS2|
| OK |HDMI|
| NOT PRESENT |Touchscreen|
| OK |Audio|
| OK |USB  OTG|
| NOT PRESENT |SATA|
| TO BE Tested |PCI Express|
| TO BE Tested |LVDS 0|
| TO BE Tested |LVDS 1|
| OK |Backlight Control|
| NOT PRESENT |Kobs-ng for u-boot programmnig|
| OK |Test VPU|
| OK BE Tested |Test GPU|
| OK |Test WIFI|

**Tests NOTE:**

**Ethernet**

ping 192.168.2.254

**MAC Address**

UBOOT: setenv ethaddr "MAC"
Power Down
LINUX: ifconfig
HWaddr "MAC"

**USB**

mount /dev/sda1 /mnt
dd if=/dev/zero of=/mnt/bigfile bs=1024 count=102400
dd if=/dev/zero of=/mnt/bigfile2 bs=1024 count=102400
cmp /mnt/bigfile /mnt/bigfile2

**MMC Card**

mount /dev/mmcblk0p2 /mnt/
dd if=/dev/zero of=/mnt/bigfile bs=1024 count=1024
dd if=/dev/zero of=/mnt/bigfile2 bs=1024 count=1024
cmp /mnt/bigfile /mnt/bigfile2

**Display**

set the following variables in u-boot:
setenv video_type 'mxcfb0:dev=ldb'
setenv lcd_panel 'Amp-WD'
saveenv
launch the system and view display

**Second Ethernet**

NOT PRESENT

**CMOS Input**

NOT PRESENT

**UART 232**

NOT PRESENT

**UART 485**

NOT PRESENT

**LINUX CONSOLE**

Connect with putty and open serial port
Check the console output

**CANBUS1**

Connect cable in connector J31
test with 2 starter kit with cantest
 Configure the bit rate on target:
/ # ip link set can0 type can bitrate 125000
 Enable the interface on target:
/ # ifconfig can0 up
 To send a frame:
/ # cantest can0 5A1#11.2233.44556677.88
 To receive a frame:
/ # cantest can0

**CANBUS2**

NOT PRESENT

**Touchscreen**

NOT PRESENT

**Audio**

playring.sh
playleftright.sh

**USB OTG**

enter the following modules:
configfs.ko
libcomposite.ko
usb_f_mass_storage.ko
insmod g_mass_storage.ko file=/dev/mmcblk0p1

**PCI Express**

TO BE Tested

**LVDS 0**

TO BE Tested

**LVDS 1**

TO BE Tested

**Backlight Control**

echo 0 > /sys/class/backlight/backlight/brightness
echo 1 > /sys/class/backlight/backlight/brightness
echo 2 > /sys/class/backlight/backlight/brightness
echo 3 > /sys/class/backlight/backlight/brightness
echo 4 > /sys/class/backlight/backlight/brightness
echo 5 > /sys/class/backlight/backlight/brightness
echo 6 > /sys/class/backlight/backlight/brightness
echo 7 > /sys/class/backlight/backlight/brightness

**Kobs-ng for u-boot programming**

NOT PRESENT

**Test VPU**

cma=128M
gst-launch-1.0 filesrc location="big_buck_bunny_1080p_h264.mov" ! qtdemux ! queue ! h264parse ! imxvpudec  ! imxg2dvideosink sync=false

**Test GPU**

Launch of demo-qt-application

**Test WIFI**

ifconfig wlan0 up
iwlist scan
