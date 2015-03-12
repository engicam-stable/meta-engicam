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

if [ -f /usr/share/qtsmarthome-1.0/smarthome ]; then
	echo "Start qt demo..."
	cd /usr/share/qtsmarthome-1.0
	
	if cat /proc/cmdline | grep -q CAP ; then 
		echo "capacitive touch"
		/usr/share/qtsmarthome-1.0/smarthome -platform eglfs -plugin EvdevTouch:/dev/input/event0 &
	else 
		echo "resistive touch"
		/usr/share/qtsmarthome-1.0/smarthome -platform eglfs -plugin tslib &
	fi
	
	cd -
fi

