**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** Startekit

**SOM Type:**  icoremx6solox

--------------------------------------------------------------------------------------------------------

**U-BOOT**

**Version:**
Engicam Yocto U-Boot 3.00 based on U-Boot 2016.07+fslc
**Tests**

| Status  |  Test |
|---------|-------|
| OK    |Nand Enviroment saving   |
| OK    |Sdcard  Enviroment saving |
| N/A   |Emmc  Enviroment saving |
| OK    |Ethernet  |
| OK    |Boot from nand   |
| OK    |Boot from sdcard  |
| N/A   |Boot from emmc  |
| OK    |Nand flash Programming from ethernet   |
| N/A   |U-boot logo   |


**Tests NOTE:**

**Nand Enviroment saving  **

boot from nand:

```
setenv serverip 192.168.2.69
saveenv
reset board
printenv  serverip
```
**Sdcard  Enviroment saving **

boot from sd:

```
setenv serverip 192.168.2.69
saveenv
reset board
printenv  serverip
```
**Ethernet **

Nand flash programming done.
See below.

**Boot from nand **

Open JM3 and power on board.

**Boot from sdcard **

Close JM3 and power on board.

**Nand flash Programming from ethernet**

Used script:

```
setenv mtdids 'nand0=gpmi-nand'
saveenv

#uImage
tftp sx/uImage
nand erase 0x00400000 0x00800000
nand write 0x80800000 0x00400000 0x00800000
#DTB:
tftp sx/uImage.dtb
nand erase 0x00c00000 0x00100000
nand write 0x80800000 0x00c00000 0x00100000
#FS:
nand erase.part rootfs
tftp sx/rootfs.ubifs
ubi part rootfs
ubi create rootfs
ubi write 0x80800000 rootfs ${filesize}
ubifsmount ubi0:rootfs
ubifsls

reset
```

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
| OK  |Display|
| OK  |Second Ethernet|
| TBT |CMOS Input|
| OK |UART 232|
| OK |UART 485|
| OK |Linux Console|
| OK |CANBUS1|
| OK |CANBUS2|
| N/A |HDMI|
| OK |Touchscreen|
| OK |Audio|
| TBD |USB  OTG|
| N/A |SATA|
| N/A |PCI Express|
| TBD |LVDS 0|
| N/A |LVDS 1|
| OK |Backlight Control|
| OK |Kobs-ng for u-boot programmnig|
| N/A |Test VPU|
| OK  |Test GPU|
| TBT |WF111|

**Tests NOTE:**

**Ethernet**

Ping test ad some file transfer

```
ping 192.168.2.254
```

**MAC Address**

With ifconfig same of ethaddr on uboot

**USB**

Mount USB Stick, then write and read file.

```
mount /dev/sda1 /mnt
dd if=/dev/zero of=/mnt/bigfile bs=1024 count=102400
dd if=/dev/zero of=/mnt/bigfile2 bs=1024 count=102400
cmp /mnt/bigfile /mnt/bigfile2
rm /mnt/bigfile /mnt/bigfile2  
umount /mnt/
```

**MMC Card**

Mount Sd card , then write and read file.

```
mount /dev/mmcblk0p2 /mnt/
dd if=/dev/zero of=/mnt/bigfile bs=1024 count=1024
dd if=/dev/zero of=/mnt/bigfile2 bs=1024 count=1024
cmp /mnt/bigfile /mnt/bigfile2
rm /mnt/bigfile /mnt/bigfile2  
umount /mnt/
```

**Second Ethernet**

Tested by ping to local server

```
ifconfig eth1 192.168.2.63 up
ping -I eth1 192.168.2.60
```

**UART 232**

Connect a serial adapter to J30 with a terminal emulator

```
stty -F /dev/ttymxc1 speed 115200
echo "lupo" > /dev/ttymxc1
```

Read on terminal:

```
cat /dev/ttymxc1
```

write some text on terminal and check on


**UART 485**
Test with 2 starter kit test_serial2

```
test_serial2 -d /dev/ttymxc2 -b 115200
```

**CANBUS1**

Test with 2 starter kit with cantest on J31


```
 Configure the bit rate on target:
/ # ip link set can0 type can bitrate 125000
 Enable the interface on target:
/ # ifconfig can0 up
 To send a frame:
/ # cantest can0 5A1#11.2233.44556677.88
 To receive a frame:
/ # cantest can0
```

**CANBUS2**

test with 2 starter kit with cantest on J3

```
 Configure the bit rate on target:
/ # ip link set can1 type can bitrate 125000
 Enable the interface on target:
/ # ifconfig can1 up
 To send a frame:
/ # cantest can1 5A1#11.2233.44556677.88
 To receive a frame:
/ # cantest can1
```

**Touchscreen**

With tslib

**Audio**
Test with audio script test files

```
playring.sh
playleftright.sh
```

**Kobs-ng for u-boot programming**

Tested with script: prboot.sh


**Test GPU**

With engicam-demo-qt image


**Backlight Control**

Change backlight value

```
echo 5 >  /sys/class/backlight/backlight/brightness
echo 1 >  /sys/class/backlight/backlight/brightness          
echo 2 >  /sys/class/backlight/backlight/brightness
echo 7 >  /sys/class/backlight/backlight/brightness
```
