# This script could be used for automatically build all u-boot for different module
# target. The script create a new directory bootbuild and fill it with all bootaloader
# compiled version for all different target.
#
# Copy thisn script in the uboot developping direcotory


rm -rf ../bootbuild
mkdir ../bootbuild
make clean

make mx6s_icore_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-solo.imx
rm u-boot.imx
make clean

make mx6d_icore_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-dual.imx
rm u-boot.imx
make clean

make mx6s_icore_512MB_sd_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-sd-solo512.imx
rm u-boot.imx
make clean

make mx6q_icore_sd_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-sd-quad.imx
rm u-boot.imx
make clean

make mx6d_icore_rqs_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-rqs-dual.imx
rm u-boot.imx
make clean

make mx6s_icore_512MB_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-solo512.imx
rm u-boot.imx
make clean

make mx6q_icore_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-quad.imx
rm u-boot.imx
make clean

make mx6dl_icore_sd_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-sd-dullite.imx
rm u-boot.imx
make clean

make mx6s_icore_rqs_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-rqs-solo.imx
rm u-boot.imx
make clean

make mx6q_icore_rqs_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-rqs-quad.imx
rm u-boot.imx
make clean

make mx6dl_icore_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-duallite.imx
rm u-boot.imx
make clean

make mx6s_icore_sd_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-sd-solo.imx
rm u-boot.imx
make clean

make mx6d_icore_sd_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-sd-dual.imx
rm u-boot.imx
make clean

make mx6dl_icore_rqs_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-rqs-duallite.imx
rm u-boot.imx
make clean

make mx6dl1g_icore_sd_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-sd-duallite1G.imx
rm u-boot.imx
make clean

make mx6dl1g_icore_config
make -j 8
cp u-boot.imx ../bootbuild/uboot-duallite1G.imx
rm u-boot.imx
make clean

 
