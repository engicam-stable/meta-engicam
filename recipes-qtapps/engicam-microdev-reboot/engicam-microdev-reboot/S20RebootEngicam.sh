echo "***Engicam Reboot***"

#!/bin/bash

echo 1 > /sys/class/gpio/UMTS_RESET/value 
sleep 1

