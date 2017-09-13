**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** Startekit

**SOM Type:**  gealmx6ul

--------------------------------------------------------------------------------------------------------

**U-BOOT**

**Version:**

**Tests**

| Status  |  Test |
|---------|-------|
| OK  |Nand Enviroment saving   |
| OK  |Sdcard  Enviroment saving |
| N/A  |Emmc  Enviroment saving |
| OK  |Ethernet  |
| OK  |Boot from nand   |
| OK  |Boot from sdcard  |
| N/A  |Boot from emmc  |
| OK  |Nand flash Programming from ethernet   |
| N/A  |U-boot logo   |


**Tests NOTE:**

**Nand Enviroment saving  **

setenv serverip 192.168.2.69
saveenv
reset board
printenv  serverip

**Sdcard  Enviroment saving **

setenv serverip 192.168.2.69
saveenv
reset board
printenv  serverip

**Ethernet **

Nand flash programming done

**Boot from nand **

**Boot from sdcard **

**Nand flash Programming from ethernet**

ftp geam6ul/ker_dtb_fs.scr

**U-boot logo**
no logo showed

--------------------------------------------------------------------------------------------------------
**Kernel Linux**

| Status  |  Test |
|---------|-------|
|OK  |Ethernet|
|OK  |MAC Address|
|OK  |USB|
|OK  |MMC card|
|N/A |Display|
|N/A |Second Ethernet|
|N/A |CMOS Input|
|TBT |UART 232|
|TBT |UART 485|
|OK  |Linux Console|
|TBT |CANBUS1|
|TBT |CANBUS2|
|N/A |HDMI|
|N/A |Touchscreen|
|OK  |Audio|
|TBT |USB  OTG|
|N/A |SATA|
|N/A |PCI Express|
|N/A |LVDS 0|
|N/A |LVDS 1|
|N/A |Backlight Control|
|TBT |Kobs-ng for u-boot programmnig|
|N/A |Test VPU|
|N/A |Test GPU|
|N/A |WF111|

**Tests NOTE:**

**Ethernet**

ping 192.168.2.254

**MAC Address**

With ifconfig same of ethaddr on uboot

**USB**

mount /dev/sda1 /mnt

dd if=/dev/zero of=/mnt/bigfile bs=1024 count=102400

dd if=/dev/zero of=/mnt/bigfile2 bs=1024 count=102400

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

With tslib or evtest

**Audio**

playring.sh

playleftright.sh

**Kobs-ng for u-boot programming**

Tested with script: prboot.sh

**Test VPU**
gplay of big buck bunny

**Test GPU**
Launch of demo-qt-application

**Test WF111**
iwlist wlan0 scanning
