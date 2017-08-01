// WARNING: Example only. Lacks error checking!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "serial_lib.h"  
            
// this is the mainline thingee
int main(int argc, char *argv[]) 
{ 
	char sCmd[1024];
	char sResult[1024];
	if (argc < 2 || argc > 2 || strncmp(argv[1], "tty", 3))
	{
		printf("serial_test needs 1 parameter for the serial port\n");
		printf("  use:\n");
		printf("  serial_test ttymxc1   		for MX6 serial\n");
		printf("  serial_test ttyUSB0   	for serials on USB converter\n");
		printf("  serial_test ttyACM0   	for serials on a modem\n");
		return 0;
	} // end if
	printf("Type q to quit.\n\n");
	if (OpenAdrPort(argv[1]) < 0) return 0;
	while (1)
	{
//		printf("?:\n");

//		scanf("%s",sCmd);

//		if (sCmd[0] == 'q' || sCmd[0] == 'Q') return 0;

//		if (WriteAdrPort(sCmd) < 0) return 0;
		sleep(1);
		if (ReadAdrPort(sResult,1024) > 0)
		{
			printf("%s\n", sResult);
		} // end if
	} // end while
	
	CloseAdrPort();

} // end main
    
