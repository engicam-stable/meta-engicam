DESCRIPTION = "Engicam image with QT5 demo image for Frame Buffer"

LICENSE = "MIT"

inherit core-image
inherit distro_features_check
inherit populate_sdk 
inherit populate_sdk_${@base_contains('MACHINE', 'geam6ul', 'qt5_geam6ul', 'qt5_icore', d)}

EXTRA_IMAGE_FEATURES = " debug-tweaks ssh-server-openssh tools-debug \			
			"

###############RECIPES iMX6##########################

SOC_IMAGE_INSTALL_mx6 = "packagegroup-fsl-tools-gpu kernel-module-imx-gpu-viv"

IMAGE_INSTALL_append_mx6 = " \
  	firmware-imx \
"

#PACKAGES QT
IMAGE_INSTALL_append_mx6 = " \
    	qtbase-dev \
	qtbase-fonts \
	qtbase-mkspecs \
	qtbase-plugins \
	qtbase-staticdev \
	qtconnectivity-dev \
	qtconnectivity-mkspecs \
	qtconnectivity-qmlplugins \
	qtdeclarative-dev \
	qtdeclarative-mkspecs \
	qtdeclarative-plugins \
	qtdeclarative-qmlplugins \
	qtdeclarative-staticdev \
	qtgraphicaleffects-qmlplugins \
	qtimageformats-dev \
	qtimageformats-plugins \
	qtscript-dev \
	qtscript-mkspecs \
	qtsvg-dev \
	qtsvg-mkspecs \
	qtsvg-plugins \
	qtxmlpatterns-dev \
	qtxmlpatterns-mkspecs \
	packagegroup-qt5-qtcreator-debug \
	engicam-emmc-script \
	${@base_contains('STARTUPDEMO', 'resistive', ' democard engicam-startup-demo-resistive', '', d)} \
	${@base_contains('STARTUPDEMO', 'capacitive', ' democard engicam-startup-demo-capacitive', '', d)} \
"   

############################################

###############RECIPES GEAM6UL##############

#PACKAGES QT
IMAGE_INSTALL_append_mx6ul = " \
	packagegroup-qt5-qtcreator-debug \      
	qtbase-dev \
	qtbase-fonts \
	qtbase-mkspecs \
	qtbase-plugins \
	qtbase-staticdev \
	qtdeclarative-dev \
	qtdeclarative-mkspecs \
	qtdeclarative-plugins \
	qtdeclarative-qmlplugins \
	qtdeclarative-staticdev \
	qtimageformats-dev \
	qtimageformats-plugins \
	qtsvg-dev \
	qtsvg-mkspecs \
	qtsvg-plugins \	
        qtquick1 \
	${@base_contains('STARTUPDEMO', 'capacitive', ' demogeam6ul engicam-startup-demogeam6ul-cap', '', d)} \	
	${@base_contains('STARTUPDEMO', 'resistive', ' demogeam6ul engicam-startup-demogeam6ul', '', d)} \
    "

#################################################

#PACKAGE DEBUG
IMAGE_INSTALL_append += " \
	binutils \
	psplash \
        engicam-mtd-script \        
        mtd-utils imx-kobs mtd-utils-ubifs \
"

#PACKAGE TSLIB+EVTEST
IMAGE_INSTALL_append += " \
	tslib \
	evtest \
	tslib-conf \
	tslib-tests \
	tslib-calibrate \
"

IMAGE_INSTALL_remove ="qt3d nativesdk-qt3d qt3d-native ruby-native"

export IMAGE_BASENAME = "engicam-demo-qt"
