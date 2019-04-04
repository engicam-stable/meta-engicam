**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:**  
Open Frame 2.0

**SOM Type:**  
icoremx6solo/duallite/dual/quad

--------------------------------------------------------------------------------------------------------

**U-BOOT**  
**Version:**  
U-Boot 2016.07+fslc+g8c29aab

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

**Nand Enviroment saving**  
setenv serverip 192.168.2.69  
saveenv  
reset board  
printenv  serverip

**Sdcard  Enviroment saving**  
setenv serverip 192.168.2.69  
saveenv  
reset board  
printenv serverip

**Ethernet**  
Nand flash programming done

**Boot from nand**  
Do not insert the jumper on JM3  
saveenv  
Saving Environment to NAND...

**Boot from sdcard**  
Insert the jumper on JM3  
saveenv  
Saving Environment to MMC... Writing to MMC(0)... done

**Nand flash Programming from ethernet**  
ftp icoremx6/ker_dtb_fs.scr

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
|OK  |Display|
|N/A |Second Ethernet|
|TBT |CMOS Input|
|OK  |UART 232|
|OK  |UART 485|
|OK  |Linux Console|
|N/A  |CANBUS1|
|OK  |CANBUS2|
|N/A |HDMI|
|OK  |Touchscreen|
|OK  |Audio|
|OK  |RTC|
|TBT |USB  OTG|
|N/A |SATA|
|N/A |PCI Express|
|OK  |LVDS 0|
|N/S |LVDS 1|
|OK  |Backlight Control|
|OK  |Kobs-ng for u-boot programmnig|
|OK  |Test VPU| (da mettere cma a 128MB)
|OK  |Test GPU|
|OK  |WIFI|
|OK  |BLUETOOTH|

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
cmp /mnt/bigfile /mnt/bigfile2

**Display**  
set the following variables in u-boot:  
setenv video_type 'mxcfb0:dev=ldb'  
setenv lcd_panel 'Amp-WD'  
saveenv  
launch the system and view display 

**Second Ethernet**  
N/A

**CMOS Input**  
N/A

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

**Linux Console**  
Connect with putty and open serial port Check the console output

**CANBUS1**  
N/A

**CANBUS2**  
Test with 2 carrier board with cantest
Configure the bit rate on target:  
/ # ip link set can1 type can bitrate 125000  
Enable the interface on target:  
/ # ifconfig can1 up  
To send a frame:  
/ # cantest can1 5A1#11.2233.44556677.88  
To receive a frame:  
/ # cantest can1

**HDMI**  
N/A

**Touchscreen**  
evtest

**Audio**  
playring.sh  
playleftright.sh

**RTC**  
date -s "YYYY-MM-DD hh:mm:ss"  
hwclock -w  
power off  
power on
check the date


**USB OTG**  
enter the following modules:  
configfs.ko  
libcomposite.ko  
usb_f_mass_storage.ko  
insmod g_mass_storage.ko file=/dev/mmcblk0p1

**SATA**  
N/A  

**PCI Express**  
N/A  

**LVDS 0**  
view test **DISPLAY**

**LVDS 1**  
N/A

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
gplay of big buck bunny

**Test GPU**  
Launch of demo-qt-application

**WIFI**  
ifconfig wlan0 up  
iw dev wlan0 scan | grep SSID  
wpa_passphrase SSID PASSWORD > /etc/wpa_supplicant.conf  
wpa_supplicant -iwlan0 -Dnl80211 -c/etc/wpa_supplicant.conf -B  
udhcpc -iwlan0  
ping 192.168.X.XXX

**BLUETOOTH**  
hciconfig hci0 up  
hcitool scan  
sdptool browse "MAC"
obexftp --nopath --noconn --uuid none --bluetooth "MAC" --channel 9 --put pippo.txt
