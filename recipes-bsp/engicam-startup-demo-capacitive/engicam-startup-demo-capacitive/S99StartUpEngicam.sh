echo "Engicam custom startup"

#####disable framebuffer blank timeout
echo 0 > /sys/class/graphics/fbcon/cursor_blink
echo -e '\033[9;0]' > /dev/tty1  

/usr/share/engicam-qtdemo-1.0/QtDemo -platform eglfs &
