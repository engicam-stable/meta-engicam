echo "Engicam custom startup"

#####disable framebuffer blank timeout
echo 0 > /sys/class/graphics/fbcon/cursor_blink
echo -e '\033[9;0]' > /dev/tty1  

#####calibrate touch if needed
export TSLIB_TSDEVICE="/dev/input/touchscreen0"

if ! cat /proc/cmdline | grep -q CAP ; then
	
	if [ ! -f /etc/pointercal ]; then
		echo "Start calibration sequence..."
		ts_calibrate
	else
		echo "Calibration file present..."
	fi
else
	echo "Capacitive touch requested..."
fi

if [ -f /usr/share/engicam-qtdemo-1.0/QtDemo ]; then
	echo "Start qt demo..."
	if cat /proc/cmdline | grep -q CAP ; then 
		echo "capacitive touch"
		/usr/share/engicam-qtdemo-1.0/QtDemo -platform eglfs -plugin EvdevTouch:/dev/input/event0 &
	else 
		echo "resistive touch"
		/usr/share/engicam-qtdemo-1.0/QtDemo -platform eglfs -plugin tslib &
	fi
fi

