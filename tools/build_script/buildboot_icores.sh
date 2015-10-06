# This script could be used for automatically build all u-boot for different module
# target. The script create a new directory bootbuild and fill it with all bootaloader
# compiled version for all different target.
#
# Copy thisn script in the uboot developping direcotory

export ARCH=arm
export CROSS_COMPILE=$TARGET_PREFIX
unset  LDFLAGS
export LOADADDR=0x10008000

make mx6s_icore_config
make -j 8
make clean
cp u-boot.imx /tftpboot
