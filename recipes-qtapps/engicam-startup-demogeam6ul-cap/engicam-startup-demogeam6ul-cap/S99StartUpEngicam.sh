echo "Engicam custom startup"

#####disable framebuffer blank timeout
echo 0 > /sys/class/graphics/fbcon/cursor_blink
echo -e '\033[9;0]' > /dev/tty1  

# Fix d-bus problem
if [ ! -e /var/lib/dbus/machine-id ];
then
	dbus-uuidgen --ensure
fi

/usr/bin/demo6ul -platform linuxfb -plugin evdevtouch:/dev/input/event0 &


