CFLAGS=-I.

test_serial: test_serial.c serial_lib.c test_gps.c
	$(CC) -g -c -Wall test_gps.c -o test_gps.o
	$(CC) -g -c -Wall test_serial.c -o test_serial.o
	$(CC) -g -c -Wall serial_lib.c -o serial_lib.o
	$(CC) serial_lib.o test_serial.o -o test_serial
	$(CC) serial_lib.o test_gps.o -o test_gps

clean:
	rm *.o test_serial
	rm *.o test_gps

