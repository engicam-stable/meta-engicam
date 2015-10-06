. /opt/poky/1.6.2/environment-setup-cortexa9hf-vfp-neon-poky-linux-gnueabi
export ARCH=arm
export CROSS_COMPILE=$TARGET_PREFIX
unset LDFLAGS
export LOADADDR=0x80008000
make icore_mx6sx_config
make -j 8