**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** MIPI STARTERKIT
**SOM Type:** icoremx6solo/duallite/dual/quad

--------------------------------------------------------------------------------------------------------

**U-BOOT**

U-Boot 2016.07

**Version:** Engicam Yocto U-Boot 3.00

**Tests**

| Status  |  Test |
|---------|-------|
| NOT PRESENT |Nand Enviroment saving   |
| OK |Emmc  Enviroment saving |
| OK |Sdcard  Enviroment saving |
| OK |Ethernet  |
| OK |Boot from emmc   |
| OK |Boot from sdcard  |
| NOT PRESENT |Nand flash Programming from ethernet   |
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

NOT PRESENT

**Boot from sdcard**

Inserire il jumper su JM1
saveenv
Saving Environment to MMC...

**Nand flash Programming from ethernet**

NOT PRESENT

**U-boot logo**

no logo showed

--------------------------------------------------------------------------------------------------------
**Kernel Linux**

| Status  |  Test |
|---------|-------|
| OK |Ethernet|
| OK |MAC Address|
| NOT PRESENT |USB|
| OK |MMC card|
| OK |Display|
| NOT PRESENT |Second Ethernet|
| OK |CMOS Input|
| NOT PRESENT |UART 232|
| NOT PRESENT |UART 485|
| OK |Linux Console|
| NOT PRESENT |CANBUS1|
| NOT PRESENT |CANBUS2|
| OK |HDMI|
| NOT PRESENT |Touchscreen|
| NOT PRESENT |Audio|
| NOT PRESENT |USB  OTG|
| NOT PRESENT |SATA|
| NOT PRESENT |PCI Express|
| NOT PRESENT |LVDS 0|
| NOT PRESENT |LVDS 1|
| NOT PRESENT |Backlight Control|
| NOT PRESENT |Kobs-ng for u-boot programmnig|
| OK |Test VPU|
| OK |Test GPU|
| NOT PRESENT |Test WIFI|
| OK |DIPSWICH|

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

NOT PRESENT

**Second Ethernet**

NOT PRESENT

**CMOS Input**

##icoremx6s/dl##
gst-launch-1.0 imxv4l2src device=/dev/video0 ! imxv4l2sink
########

##icoremx6d/q##
gst-launch-1.0 imxv4l2src device=/dev/video1 ! imxv4l2sink
########

**UART 232**

NOT PRESENT

**UART 485**

NOT PRESENT

**LINUX CONSOLE**

Connect with putty and open serial port
Check the console output

**CANBUS1**

NOT PRESENT

**CANBUS2**

NOT PRESENT

**HDMI**

set the following variables in u-boot:
setenv video_type 'mxcfb0:dev=hdmi'
setenv lcd_panel '1920x1080@60,if=RGB24'
saveenv
launch the system and view display

**Touchscreen**

NOT PRESENT

**Audio**

NOT PRESENT

**USB OTG**

NOT PRESENT

**SATA**

NOT PRESENT

**PCI Express**

NOT PRESENT

**LVDS 0**

NOT PRESENT

**LVDS 1**

NOT PRESENT

**Backlight Control**

NOT PRESENT

**Kobs-ng for u-boot programming**

NOT PRESENT

**Test VPU**

gst-launch-1.0 filesrc location="big_buck_bunny_1080p_h264.mov" ! qtdemux ! queue ! h264parse ! imxvpudec  ! imxg2dvideosink sync=false

**Test GPU**

Launch of demo-qt-application

**Test WIFI**

NOT PRESENT

**DIPSWICH**

cat /sys/class/gpio/DIPSWX/value
