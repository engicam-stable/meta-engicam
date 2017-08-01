**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** Open Frame Loco 4.3
**SOM Type:**  Geamx6ul

--------------------------------------------------------------------------------------------------------

**U-BOOT**

U-Boot 2016.07

**Version:**

Engicam Yocto U-Boot 3.00

**Tests**

| Status  |  Test |
|---------|-------|
| OK |Nand Enviroment saving   |
| NOT SUPPORTED |Sdcard  Enviroment saving |
| NOT SUPPORTED |Emmc  Enviroment saving |
| OK |Ethernet  |
| OK |Boot from nand   |
| NOT SUPPORTED |Boot from sdcard  |
| NOT SUPPORTED |Boot from emmc  |
| OK |Nand flash Programming from ethernet   |
| NO |U-boot logo |


**Tests NOTE:**

**Nand Enviroment saving**

setenv serverip 192.168.2.69
saveenv
reset board
printenv  serverip

**Sdcard  Enviroment saving**

NOT SUPPORTED

**Emmc  Enviroment saving**

NOT SUPPORTED

**Ethernet**

ping 192.168.2.254

**Boot from nand**

saveenv
Saving Environment to NAND...

**Boot from sdcard**

NOT SUPPORTED

**Boot from emmc**

NOT SUPPORTED

**Nand flash Programming from ethernet**

tftp ker_dtb_fs.scr

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
| NOT PRESENT |CANBUS1|
| NOT PRESENT |CANBUS2|
| NOT PRESENT |HDMI|
| OK |Touchscreen|
| NOT PRESENT |Audio|
| NOT PRESENT |USB  OTG|
| NOT PRESENT |SATA|
| NOT PRESENT |PCI Express|
| NOT PRESENT |LVDS 0|
| NOT PRESENT |LVDS 1|
| OK |Backlight Control|
| OK |Kobs-ng for u-boot programmnig|

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
test_serial2 -d /dev/ttymxc7 -b 115200

**LINUX CONSOLE**

Connect with putty and open serial port
Check the console output

**CANBUS1**

NOT PRESENT

**CANBUS2**

NOT PRESENT

**Touchscreen**

ts_calibrate

**Audio**

NOT PRESENT

**USB OTG**

NOT PRESENT

**Backlight Control**

echo 0 > /sys/class/backlight/backlight/brightness
echo 10 > /sys/class/backlight/backlight/brightness
echo 20 > /sys/class/backlight/backlight/brightness
echo 30 > /sys/class/backlight/backlight/brightness
echo 40 > /sys/class/backlight/backlight/brightness
echo 50 > /sys/class/backlight/backlight/brightness
echo 60 > /sys/class/backlight/backlight/brightness
echo 70 > /sys/class/backlight/backlight/brightness
echo 80 > /sys/class/backlight/backlight/brightness
echo 90 > /sys/class/backlight/backlight/brightness
echo 100 > /sys/class/backlight/backlight/brightness


**Kobs-ng for u-boot programming**

Tested with script: prboot.sh
