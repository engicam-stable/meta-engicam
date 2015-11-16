PER IL TARGET:

Aggiungere nel conf/local.conf l'accettazione della licenza con la seguente riga. Ricordarsi poi di
commentarla per la compilaizione delle altre ricette. Ad esempio su gstreamer-1.0 crea dei problemi

	LICENSE_FLAGS_WHITELIST =  "commercial"

	bitbake engicam-image-opencv

******************************
******************************
******************************
******************************

	SU UBUNTU x86

Per installare opencv usare il seguente link

git clone https://github.com/jayrambhia/Install-OpenCV/

E lanciare lo script per installare l'ultima versione

In codeblock includere le direcotry degli include opencv

	/usr/include/opencv
	/usr/include/opencv2
	
Impostare poi i seguenti flag per il linker

-lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect

******************************
******************************
******************************
******************************

	BUILD E INSTALLAZIONE TOOLCHIAN

Ricompilare la toolchain

	bitbake meta-toolchain 
        bitbake engicam-image-opencv -c populate_sdk

Installazione toolchain, dare conferma della sovrascrizione e del path in cui installarla

	./tmp/deploy/sdk/poky-eglibc-x86_64-engicam-image-opencv-cortexa9hf-vfp-neon-toolchain-1.6.1.sh 

******************************
******************************
******************************
******************************

	BUILD APPLICAZIONE

Scaricare ad esempio la seguente applicazione:

	git clone https://github.com/andreluizeng/opencv-camera-test---i.MX6-Yocto.git

Entrare nella cartella e inizializzare la toolchain

	. /opt/poky/1.6.1/environment-setup-cortexa9hf-vfp-neon-poky-linux-gnueabi
	
