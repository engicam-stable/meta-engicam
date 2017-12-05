echo "Engicam epd startup"

#####disable framebuffer blank timeout
echo 0 > /sys/class/graphics/fbcon/cursor_blink
echo -e '\033[9;0]' > /dev/tty1  

if [ ! -e /mnt/ramdisk ];
then                                         
	mkdir /mnt/ramdisk
fi  

#mount -t tmpfs -o size=36m tmpfs /mnt/ramdisk               

/home/root/launch.sh &
