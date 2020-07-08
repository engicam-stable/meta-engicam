echo "***Engicam Startup***"

#####disable framebuffer blank timeout
echo 0 > /sys/class/graphics/fbcon/cursor_blink
echo -e '\033[9;0]' > /dev/tty1

brcm_patchram_plus --patchram /lib/firmware/brcm/BCM4343A1_001.002.009.0038.0000_Generic_UART_37_4MHz_wlbga_ref_OTP.hcd --enable_hci --no2bytes --tosleep 50000 --baudrate 3000000 --use_baudrate_for_download /dev/ttymxc7 &

sleep 1
echo 1 > /sys/class/gpio/UMTS_ON/value
sleep 1
echo 0 > /sys/class/gpio/UMTS_ON/value
