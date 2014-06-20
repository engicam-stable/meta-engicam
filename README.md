meta-engicam
============

yocto engicam meta layer

for icoreM6solo starterkit:

set mmcargs 'setenv bootargs console=${console},${baudrate} ${smp} root=${mmcroot} cma=96MB gpumem=16MB video=mxcfb0:dev=lcd,Amp-WD'

for icoreM6duallite/icorem6dual/icorem6duad starterkit:

set mmcargs 'setenv bootargs console=${console},${baudrate} ${smp} root=${mmcroot} video=mxcfb0:dev=lcd,Amp-WD'




Engicam machines:

icorem6dual 
icorem6duallite 
icorem6quad
icorem6solo
icorem6solo512


Engicam images:

engicam-image-minimal-mtdutils <tested>
engicam-image-minimal-nand     <to be tested>

		


