# Provides the iCore6 common settings

include conf/machine/include/iCore.inc

MKUBIFS_ARGS ?= "-m 4096 -e 253952 -c 1996"
UBINIZE_ARGS ?= "-m 4096 -p 262144 -s 4096"

IMAGE_FSTYPES += " ubifs "
