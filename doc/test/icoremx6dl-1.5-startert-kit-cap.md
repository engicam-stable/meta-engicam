**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** Startekit Capacitive 1.0

**SOM Type:**  i.Core MX6DL 1.5

--------------------------------------------------------------------------------------------------------

**U-BOOT**

2019.04-4.19.35-1.1.0+g68f5cd8


**Tests**

| Status  |  Test |
|---------|-------|
| N/A   |Nand Enviroment saving   |
| OK    |Sdcard  Enviroment saving |
| TBT   |Emmc  Enviroment saving |
| OK    |Ethernet  |
| N/A   |Boot from nand   |
| OK    |Boot from sdcard  |
| OK   |Boot from emmc  |
| N/A   |Nand flash Programming from ethernet   |
| N/A   |U-boot logo   |


**Tests NOTE:**

**Sdcard  Enviroment saving **

setenv serverip 192.168.2.69
saveenv
reset board
printenv  serverip

**Emmc  Enviroment saving **


**Ethernet **

ping 192.168.1.2
Using FEC device
host 192.168.1.2 is alive

**Boot from sdcard **

OK

--------------------------------------------------------------------------------------------------------
**Kernel Linux**

| Status  |  Test |
|---------|-------|
|OK |Ethernet|
|OK |MAC Address|
|OK |USB|
|OK |SD card|
|OK |EMMC card|
|OK |Display|
|N/A |Second Ethernet|
|N/A  |CMOS Input|
|OK |UART 232|
|OK |UART 485|
|OK |Linux Console|
|OK |CANBUS1|
|OK |CANBUS2|
|TBT |HDMI|
|OK |Touchscreen|
|OK |Audio|
|OK |USB  OTG|
|N/A |SATA|
|TBT |PCI Express|
|TBT |LVDS 0|
|TBT |LVDS 1|
|OK |Backlight Control|
|N/A |Kobs-ng for u-boot programmnig|
|OK |Test VPU|
|OK |Test GPU|
|N/A |WF111|
|N/A |RTC|

**Tests NOTE:**

**Ethernet**

ping 192.168.2.254

**MAC Address**

With ifconfig same of ethaddr on uboot

**USB**

mount /dev/sda1 /mnt

dd if=/dev/zero of=/mnt/bigfile bs=1024 count=102

dd if=/dev/zero of=/mnt/bigfile2 bs=1024 count=102

cmp /mnt/bigfile /mnt/bigfile2

**MMC Card**

 mount /dev/mmcblk0p2 /mnt/
dd if=/dev/zero of=/mnt/bigfile bs=1024 count=1024

dd if=/dev/zero of=/mnt/bigfile2 bs=1024 count=1024

**Second Ethernet**

Ok tested by ping to local server
ping -I eth0 192.168.2.254

**UART 232**

Connect a serial adapter to J30 with a terminal emulator

stty -F /dev/ttymxc1 speed 115200
echo "lupo" > /dev/ttymxc1

read on terminal

cat /dev/ttymxc1

write some text on terminal

**UART 485**
test with 2 starter kit test_serial2

test_serial2 -d /dev/ttymxc2 -b 115200


**CANBUS1**

test with 2 stearter kit with cantest

 Configure the bit rate on target:
/ # ip link set can0 type can bitrate 125000
 Enable the interface on target:
/ # ifconfig can0 up
 To send a frame:
/ # cantest can0 5A1#11.2233.44556677.88
 To receive a frame:
/ # cantest can0

**CANBUS2**

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

With evtest

**Audio**

playring.sh

playleftright.sh

**Kobs-ng for u-boot programming**

Tested with script: prboot.sh

**Test VPU**

/unit_tests/VPU/autorun-vpu.sh

**Test GPU**

/unit_tests/GPU/gpu.sh

**USB OTG**

enter the following modules:
configfs.ko
libcomposite.ko
usb_f_mass_storage.ko
insmod g_mass_storage.ko file=/dev/mmcblk0p1


**Backlight Control**

echo 0 > /sys/class/backlight/backlight/brightness
echo 1 > /sys/class/backlight/backlight/brightness
echo 2 > /sys/class/backlight/backlight/brightness
echo 3 > /sys/class/backlight/backlight/brightness
echo 4 > /sys/class/backlight/backlight/brightness
echo 5 > /sys/class/backlight/backlight/brightness
echo 6 > /sys/class/backlight/backlight/brightness
echo 7 > /sys/class/backlight/backlight/brightness
