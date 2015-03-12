##### Nand size autodetect for fw_printenv and fw_setenv

ERASESIZE=$(cat /proc/mtd | grep mtd0 | cut -f 3 -d " ")
echo "# configuration file for fw_(printenv/saveenv) utility." > /tmp/fw_env.config
echo "# Up to two entries are valid, in this case the redundand" >> /tmp/fw_env.config
echo "# environment sector is assumed present." >> /tmp/fw_env.config
echo "# MTD device name Device offset Env. size Flash sector size" >> /tmp/fw_env.config
echo "/dev/mtd0 0x1c0000 0x20000 0x$ERASESIZE" >> /tmp/fw_env.config
mv /tmp/fw_env.config /etc
