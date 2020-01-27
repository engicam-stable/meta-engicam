**Test sheet**

**Version:** 1.0


**Preliminary**

Creation of engicam-test-hw image for sdcard booting and same image for nand programming.

--------------------------------------------------------------------------------------------------------

**Board Type:** Microdev

**SOM Type:**  Microgea

--------------------------------------------------------------------------------------------------------

**U-BOOT**

U-Boot 2016.07+fslc+g987d8ab

**Version:**

Engicam Yocto U-Boot 3.00

**Tests**

| Status  |  Test |
|---------|-------|
| OK   |Nand Enviroment saving   |
| OK   |Sdcard  Enviroment saving |
| OK   |Ethernet  |
| OK   |Boot from nand   |
| OK   |Boot from sdcard  |
| OK   |Nand flash Programming from ethernet   |


**Tests NOTE:**

**Nand Enviroment saving  **

setenv serverip 192.168.2.93

saveenv

reset board

printenv  serverip

**Sdcard  Enviroment saving **

Close the connector JM2

setenv serverip 192.168.2.93

saveenv

reset board

printenv  serverip

**Ethernet **

ping 192.168.2.254

Using FEC0 device

host 192.168.2.254 is alive

**Boot from nand **

saveenv

Saving Environment to NAND...

Erasing NAND...

Erasing at 0x1c0000 -- 100% complete.

Writing to NAND... OK

**Boot from sdcard **

Close the connector JM2

saveenv

Saving Environment to MMC...

Writing to MMC(0)... done

**Nand flash Programming from ethernet**

tftp ker_dtb_fs.scr

so

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
|OK  |UART 232|
|OK  |UART 485|
|OK  |Linux Console|
|OK  |Kobs-ng for u-boot programmnig|
|OK  |wifi|
|OK  |BLUETOOTH|
|OK  |UMTS|
|OK  |RTC|



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

**UART 232**

Connect TX/RX PIN connector J31

Open minicom and set the port /dev/ttymxc4

Write and Read the characters from the keyboard

**UART 485**

Connector J32

Tested with two Microdev

test_serial2 -d /dev/ttymxc1 -b 115200

Device = /dev/ttymxc1, Baudrate = 115200

Open Port
sent: [Test PACKETs 0#]
received: [Test PACKETs 0#]
sent: [Test PACKETs 1#]
received: [Test PACKETs 1#]
sent: [Test PACKETs 2#]
received: [Test PACKETs 2#]
sent: [Test PACKETs 3#]
received: [Test PACKETs 3#]
sent: [Test PACKETs 4#]

**Linux Console**

View Output From Linux console

**Test WIFI**

ifconfig eth0 down

ifconfig wlan0 up

iw dev wlan0 scan | grep SSID

wpa_passphrase SSID PASSWORD > /etc/wpa_supplicant.conf

wpa_supplicant -iwlan0 -Dnl80211 -c/etc/wpa_supplicant.conf -B

udhcpc -iwlan0

ping -Iwlan0 www.google.com

**Bluetooth**

hciconfig hci0 up

hcitool scan

sdptool browse "MAC"

obexftp -b "MAC" -B 12 -U NONE -p file.txt

**MODEM**

Open minicom and set the port /dev/ttyACM0

AT+CGMI --> Quectel

With SIM inserted:

AT+CIMI --> 222992312689823

AT+CPIN? --> OK:READY


**RTC**

date -s "2018-04-17 18:13:00"

hwclock -w

power off board

date
