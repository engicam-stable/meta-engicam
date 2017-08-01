**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** OPEN FRAME RESISTIVE
**SOM Type:** icoremx6solo/duallite/dual/quad

--------------------------------------------------------------------------------------------------------

**U-BOOT**

U-Boot 2016.07

**Version:** Engicam Yocto U-Boot 3.00

**Tests**

| Status  |  Test |
|---------|-------|
| OK |Nand Enviroment saving   |
| NOT SUPPORTED |Sdcard  Enviroment saving |
| OK |Ethernet  |
| OK |Boot from nand   |
| NOT SUPPORTED |Boot from sdcard  |
| OK |Nand flash Programming from ethernet   |
| NO |U-boot logo   |


**Tests NOTE:**

**Nand Enviroment saving**

setenv serverip 192.168.2.93
saveenv
reset board
printenv serverip

**Sdcard  Enviroment saving**

NOT SUPPORTED

**Ethernet**

ping 192.168.2.254

**Boot from nand**

saveenv
Saving Environment to NAND...

**Boot from sdcard**

NOT SUPPORTED

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
| NOT PRESENT |CMOS Input|
| OK |UART 232|
| OK |UART 485|
| OK |Linux Console|
| OK |CANBUS1|
| NOT PRESENT |CANBUS2|
| NOT PRESENT |HDMI|
| OK |Touchscreen|
| NOT PRESENT |Audio|
| NOT PRESENT |USB  OTG|
| NOT PRESENT |SATA|
| TO BE Tested |PCI Express|
| TO BE Tested |LVDS 0|
| NOT PRESENT |LVDS 1|
| OK |Backlight Control|
| OK |Kobs-ng for u-boot programmnig|
| OK |Test VPU|
| OK |Test GPU|
| NOT PRESENT |Test WIFI|

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

**OPENFRAME RESISTEVE 4.3:**
setenv video_type 'mxcfb0:dev=lcd'
setenv lcd_panel 'URT-8484MD'
saveenv

**OPENFRAME RESISTEVE 5.7:**
setenv video_type 'mxcfb0:dev=lcd'
setenv lcd_panel 'URT-VGA'
saveenv

**OPENFRAME RESISTEVE 7:**
setenv video_type 'mxcfb0:dev=lcd'
setenv lcd_panel 'URT-LVDS'
saveenv

**OPENFRAME RESISTEVE 10.4:**
setenv video_type 'mxcfb0:dev=lcd'
setenv lcd_panel 'HIT-LVDS'
saveenv

launch the system and view display

**Second Ethernet**

NOT PRESENT

**CMOS Input**

NOT PRESENT

**UART 232**

Connect a serial adapter to J17 with a terminal emulator
stty -F /dev/ttymxc1 speed 115200
echo "lupo" > /dev/ttymxc1
read on terminal
cat /dev/ttymxc1
write some text on terminal

**UART 485**

Connect cable to connector J16 and launch the program test_serial2
test with 2 starter kit with rs485
test_serial2 -d /dev/ttymxc2 -b 115200

**LINUX CONSOLE**

Connect with putty and open serial port
Check the console output

**CANBUS1**

Connect cable in connector J18
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

ts_calibrate

**Audio**

NOT PRESENT

**USB OTG**

NOT PRESENT

**PCI Express**

TO BE Tested

**LVDS 0**

TO BE Tested

**LVDS 1**

NOT PRESENT

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

NOT PRESENT
