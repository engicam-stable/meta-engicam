DESCRIPTION = "Example recipe generating SWU image"
SECTION = ""

LICENSE = "CLOSED"

# Add all local files to be added to the SWU
# sw-description must always be in the list.
# You can extend with scripts or wahtever you need
SRC_URI = " \
    file://sw-description \
    file://update.sh \
    "

# images to build before building swupdate image
IMAGE_DEPENDS = "engicam-swupdate virtual/kernel"

# images and files that will be included in the .swu image
SWUPDATE_IMAGES = "engicam-swupdate Image icore-imx8mm-ctouch2-amp10"

# a deployable image can have multiple format, choose one
SWUPDATE_IMAGES_FSTYPES[engicam-swupdate] = ".ext4.gz"
SWUPDATE_IMAGES_FSTYPES[Image] = ".bin"
SWUPDATE_IMAGES_FSTYPES[icore-imx8mm-ctouch2-amp10] = ".dtb"

inherit swupdate
