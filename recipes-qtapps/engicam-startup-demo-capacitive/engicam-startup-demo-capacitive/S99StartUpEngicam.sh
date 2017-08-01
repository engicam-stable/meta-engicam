echo "Engicam custom startup"

#####disable framebuffer blank timeout
echo 0 > /sys/class/graphics/fbcon/cursor_blink
echo -e '\033[9;0]' > /dev/tty1  

export QT_EGLFS_IMX6_NO_FB_MULTI_BUFFER=1

/usr/bin/democard -platform eglfs &
