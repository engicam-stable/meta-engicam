Per buildare x11 è necessario crearsi un altro ambiente di build, in quanto quello di default
esclude automaticamente x11. Per creare però il nuovo ambiente è necessario non utilizzare lo 
script automatico ma il seguente comando:

	. fsl-setup-release.sh -b test_cv

Fatto questo editare il file conf/local.conf come segue (nell'esempio ci sono anche i file per 
le libcv)

*********************************************************************

BB_NUMBER_THREADS ?= "${@oe.utils.cpu_count()}"
PARALLEL_MAKE ?= "-j ${@oe.utils.cpu_count()}"
MACHINE ??= 'icorem6dual'
DISTRO ?= 'poky'
PACKAGE_CLASSES ?= "package_rpm"
EXTRA_IMAGE_FEATURES = "debug-tweaks"
USER_CLASSES ?= "buildstats image-mklibs image-prelink"
PATCHRESOLVE = "noop"
BB_DISKMON_DIRS = "\
    STOPTASKS,${TMPDIR},1G,100K \
    STOPTASKS,${DL_DIR},1G,100K \
    STOPTASKS,${SSTATE_DIR},1G,100K \
    ABORT,${TMPDIR},100M,1K \
    ABORT,${DL_DIR},100M,1K \
    ABORT,${SSTATE_DIR},100M,1K" 
PACKAGECONFIG_pn-qemu-native = "sdl"
PACKAGECONFIG_pn-nativesdk-qemu = "sdl"
ASSUME_PROVIDED += "libsdl-native"
CONF_VERSION = "1"

BB_NUMBER_THREADS = '8'
PARALLEL_MAKE = '-j 8'

UBOOT_CONFIG="sd"

DL_DIR ?= "${BSPDIR}/downloads/"
ACCEPT_FSL_EULA = "1"

LICENSE_FLAGS_WHITELIST = "commercial_libav commercial_x264"

CORE_IMAGE_EXTRA_INSTALL += "gpu-viv-bin-mx6q gpu-viv-bin-mx6q-dev"
CORE_IMAGE_EXTRA_INSTALL += "libopencv-core-dev libopencv-highgui-dev libopencv-imgproc-dev libopencv-objdetect-dev libopencv-ml-dev opencv-samples opencv libv4l"

**********************************************************************

Editare poi il file conf/bblayers.conf aggiungendo il layer engicam

**********************************************************************
LCONF_VERSION = "6"

BBPATH = "${TOPDIR}"
BSPDIR := "${@os.path.abspath(os.path.dirname(d.getVar('FILE', True)) + '/../..')}"

BBFILES ?= ""
BBLAYERS = " \
  ${BSPDIR}/sources/poky/meta \
  ${BSPDIR}/sources/poky/meta-yocto \
  \
  ${BSPDIR}/sources/meta-openembedded/meta-oe \
  \
  ${BSPDIR}/sources/meta-fsl-arm \
  ${BSPDIR}/sources/meta-fsl-arm-extra \
  ${BSPDIR}/sources/meta-fsl-demos \
  ${BSPDIR}/sources/meta-engicam \
  ${BSPDIR}/sources/meta-qt5 \
  ${BSPDIR}/sources/meta-openembedded/meta-ruby \
"
**********************************************************************

A questo punto è possibile generare l'immagine con il comando 

bitbake core-image-x11

--------------------

Per compilare l'eseguibile è poi necessario compilare la toolchain e installarla



BB_NUMBER_THREADS ?= "${@oe.utils.cpu_count()}"
PARALLEL_MAKE ?= "-j ${@oe.utils.cpu_count()}"
MACHINE ??= 'icorem6dual'
DISTRO ?= 'poky'
PACKAGE_CLASSES ?= "package_rpm"
EXTRA_IMAGE_FEATURES = "debug-tweaks"
USER_CLASSES ?= "buildstats image-mklibs image-prelink"
PATCHRESOLVE = "noop"
BB_DISKMON_DIRS = "\
    STOPTASKS,${TMPDIR},1G,100K \
    STOPTASKS,${DL_DIR},1G,100K \
    STOPTASKS,${SSTATE_DIR},1G,100K \
    ABORT,${TMPDIR},100M,1K \
    ABORT,${DL_DIR},100M,1K \
    ABORT,${SSTATE_DIR},100M,1K" 
PACKAGECONFIG_pn-qemu-native = "sdl"
PACKAGECONFIG_pn-nativesdk-qemu = "sdl"
ASSUME_PROVIDED += "libsdl-native"
CONF_VERSION = "1"

BB_NUMBER_THREADS = '8'
PARALLEL_MAKE = '-j 8'

UBOOT_CONFIG="sd"

DL_DIR ?= "${BSPDIR}/downloads/"
ACCEPT_FSL_EULA = "1"

LICENSE_FLAGS_WHITELIST = "commercial_libav commercial_x264"

CORE_IMAGE_EXTRA_INSTALL += "gpu-viv-bin-mx6q gpu-viv-bin-mx6q-dev gpu-viv-g2d fsl-gpu-sdk"
CORE_IMAGE_EXTRA_INSTALL += "libopencv-core-dev libopencv-highgui-dev libopencv-imgproc-dev libopencv-objdetect-dev libopencv-ml-dev opencv-samples opencv libv4l \ 
    kernel-dev \
    packagegroup-fsl-gstreamer \
    packagegroup-fsl-gstreamer-streamer \
    packagegroup-fsl-tools-testapps \
    packagegroup-fsl-tools-benchmark "



LCONF_VERSION = "6"

BBPATH = "${TOPDIR}"
BSPDIR := "${@os.path.abspath(os.path.dirname(d.getVar('FILE', True)) + '/../..')}"

BBFILES ?= ""
BBLAYERS = " \
  ${BSPDIR}/sources/poky/meta \
  ${BSPDIR}/sources/poky/meta-yocto \
  \
  ${BSPDIR}/sources/meta-openembedded/meta-oe \
  \
  ${BSPDIR}/sources/meta-fsl-arm \
  ${BSPDIR}/sources/meta-fsl-arm-extra \
  ${BSPDIR}/sources/meta-fsl-demos \
  ${BSPDIR}/sources/meta-engicam \
  ${BSPDIR}/sources/meta-qt5 \
  ${BSPDIR}/sources/meta-openembedded/meta-ruby \
"

