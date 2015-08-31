# This script automatically build the kernel for dual/quad modules and copy and rename the uImage
# file and related .dtb file in the tftpboot folder, ready to be used from the programming
# nand script
#
# Copy this script in your kernel developping folder. Remind to replace the copy with your proper .dtb
# file instead the default imx6dl-icore.dtb

export ARCH=arm
export CROSS_COMPILE=$TARGET_PREFIX
unset  LDFLAGS
export LOADADDR=0x10008000

make -j 8 uImage
make dtbs
cp arch/arm/boot/uImage /tftpboot
cp arch/arm/boot/dts/imx6q-icore.dtb /tftpboot/uImage.dtb
