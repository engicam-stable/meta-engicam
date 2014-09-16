#kernel programming:
flash_erase /dev/mtd1 0 0
nandwrite /dev/mtd1 -p uImage

#kernel device tree programming:
flash_erase /dev/mtd2 0 0
nandwrite /dev/mtd2 -p  /uImage.dtb
