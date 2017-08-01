# Copiare questo script nella directory del kernel prima di di fare il git commit locale
# cosi fa tutte le copie in automatico

export ARCH=arm
export CROSS_COMPILE=$TARGET_PREFIX
unset  LDFLAGS
export LOADADDR=0x10008000

make -j 8 uImage
make dtbs
cp arch/arm/boot/uImage /tftpboot
cp arch/arm/boot/dts/imx6dl-icore.dtb /tftpboot/uImage.dtb
