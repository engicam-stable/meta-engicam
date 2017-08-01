**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** Startekit
**SOM Type:** icoremx6solo/duallite

--------------------------------------------------------------------------------------------------------

**U-BOOT**

U-Boot 2016.07

**Version:** Engicam Yocto U-Boot 3.00

**Tests**

| Status  |  Test |
|---------|-------|
| OK |Nand Enviroment saving   |
| OK |Sdcard  Enviroment saving |
| OK |Ethernet  |
| OK |Boot from nand   |
| OK |Boot from sdcard  |
| OK |Nand flash Programming from ethernet   |
| NO |U-boot logo   |


**Tests NOTE:**

**Nand Enviroment saving**

setenv serverip 192.168.2.93
saveenv
reset board
printenv serverip

**Sdcard  Enviroment saving**

setenv serverip 192.168.2.69
saveenv
reset board
printenv  serverip

**Ethernet**

ping 192.168.2.254

**Boot from nand**

Non inserire il jumper su JM3
saveenv
Saving Environment to NAND...

**Boot from sdcard**

Inserire il jumper su JM3
saveenv
Saving Environment to MMC...

**Nand flash Programming from ethernet**

tftp ker_dtb_fs.scr
so

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
| OK |CMOS Input|
| OK |UART 232|
| OK |UART 485|
| OK |Linux Console|
| OK |CANBUS1|
| OK |CANBUS2|
| OK |HDMI|
| OK |Touchscreen|
| OK |Audio|
| OK |USB  OTG|
| NOT PRESENT |SATA|
| TO BE Tested |PCI Express|
| TO BE Tested |LVDS 0|
| TO BE Tested |LVDS 1|
| OK |Backlight Control|
| OK |Kobs-ng for u-boot programmnig|
| OK |Test VPU|
| OK |Test GPU|
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
setenv video_type 'mxcfb0:dev=lcd'
setenv lcd_panel 'Amp-WD'
saveenv
launch the system and view display

**Second Ethernet**

NOT PRESENT

**CMOS Input**

added in local.conf this features :
LICENSE_FLAGS_WHITELIST = "commercial"

set cma=128M in bootargs_base
##shell##
gst-launch-1.0 imxv4l2src ! imxv4l2sink
########

**UART 232**

Connect a serial adapter to J30 with a terminal emulator
stty -F /dev/ttymxc1 speed 115200
echo "lupo" > /dev/ttymxc1
read on terminal
cat /dev/ttymxc1
write some text on terminal

**UART 485**

Connect cable to connector J32 and launch the program test_serial2
test with 2 starter kit with rs485
test_serial2 -d /dev/ttymxc2 -b 115200

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

Connect cable in connector J3
test with 2 starter kit with cantest
 Configure the bit rate on target:
/ # ip link set can1 type can bitrate 125000
 Enable the interface on target:
/ # ifconfig can1 up
 To send a frame:
/ # cantest can1 5A1#11.2233.44556677.88
 To receive a frame:
/ # cantest can1

**Touchscreen**

ts_calibrate

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

Tested with script: prboot.sh

**Test VPU**

cma=128M
gst-launch-1.0 filesrc location="big_buck_bunny_1080p_h264.mov" ! qtdemux ! queue ! h264parse ! imxvpudec  ! imxg2dvideosink sync=false

**Test GPU**

Launch of demo-qt-application

**Test WIFI**

ifconfig wlan0 up
iwlist scan
