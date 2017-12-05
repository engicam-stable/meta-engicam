# Provides the iCore6 common settings

require conf/machine/include/tune-cortexa9.inc
include conf/machine/include/iCore.inc

MKUBIFS_ARGS ?= "${@base_contains('NANDREV', '2', '-m 2048 -e 126976 -c 3992', '-m 4096 -e 253952 -c 1996', d)}"
UBINIZE_ARGS ?= "${@base_contains('NANDREV', '2', '-m 2048 -p 131072 -s 2048', '-m 4096 -p 262144 -s 4096', d)}"

IMAGE_FSTYPES += " ubifs "
