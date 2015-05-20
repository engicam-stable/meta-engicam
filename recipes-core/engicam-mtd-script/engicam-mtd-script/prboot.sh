dd if=u-boot.imx of=/mnt/u-boot_my.imx bs=512 seek=2 
fw_printenv > parametri.txt
cat parametri.txt | sed -e 's/=/ /' > convertito.txt
flash_erase /dev/mtd0 0 0
kobs-ng init -v /mnt/u-boot_my.imx
fw_setenv -s convertito.txt
rm /mnt/u-boot_my.imx
rm parametri.txt
rm convertito.txt
