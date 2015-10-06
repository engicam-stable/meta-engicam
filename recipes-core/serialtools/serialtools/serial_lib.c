#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>
#include "serial_lib.h"
static int fd = 0;

// Set the serial in raw mode
void cfmakeraw (struct termios *termios_p)
{
  termios_p->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
                | INLCR | IGNCR | ICRNL | IXON);
  termios_p->c_oflag &= ~OPOST;
  termios_p->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
  termios_p->c_cflag &= ~(CSIZE | PARENB);
  termios_p->c_cflag |= CS8;
}

// opens the serial port
// return code:
//   > 0 = fd for the port
//   -1 = open failed
int OpenAdrPort(char* sPortNumber)
{
    char sPortName[64];
    sprintf(sPortName, "/dev/%s", sPortNumber);
    printf("Device name: %s\n", sPortName);

    // make sure port is closed
    CloseAdrPort(fd);

    fd = open(sPortName, O_RDWR | 
			O_NOCTTY | /* tells UNIX that this program doesn't want to be the "controlling terminal" for that port*/
			O_NDELAY); /* tells UNIX that this program doesn't care what state the DCD signal line is in */

    if (fd < 0)
    {
        printf("open error %d %s\n", errno, strerror(errno));
	return -1;
    }
    else
    {
	struct termios options;

	/* The FNDELAY option causes the read function to return 0 if no 
	  characters are available on the port. To restore normal (blocking) behavior, 
	  call fcntl() without the FNDELAY option: */

//	fcntl(fd, F_SETFL, 0); //<---- bloccante

	fcntl(fd, F_SETFL, FNDELAY); //<---- NON bloccante

       	tcgetattr(fd, &options);

	//set port speed
	cfsetispeed(&options, B9600);
	cfsetospeed(&options, B9600);

	options.c_cflag |= (CLOCAL | CREAD);

	//set 8n1
	options.c_cflag &= ~PARENB; /* Enable parity bit */
	options.c_cflag &= ~CSTOPB; /* 	2 stop bits (1 otherwise) */
	options.c_cflag &= ~CSIZE; /* Mask the character size bits */
	options.c_cflag |= CS8; /* Select 8 data bits */
	cfmakeraw(&options);/* RAW MODE */

	//set raw input
	options.c_lflag &= ~(ICANON | /* Enable canonical input (else raw) */
				ECHO | /*Enable echoing of input characters	*/
				ECHOE | /*Echo erase character as BS-SP-BS*/
				ISIG); /*Enable SIGINTR, SIGSUSP, SIGDSUSP, and SIGQUIT signals*/

	tcsetattr(fd, TCSANOW, &options); /*Make changes now without waiting for data to complete*/

   } // end if
    return fd;
} // end OpenAdrPort

// writes zero terminated string to the serial port
// return code:
//   >= 0 = number of characters written
//   -1 = write failed
int WriteAdrPort(char* psOutput)
{
    int iOut;
    if (fd < 1)
    {
        printf(" port is not open\n");
        return -1;
    } // end if
 
    iOut = write(fd, psOutput, strlen(psOutput));
    if (iOut < 0)
    {
        printf("write error %d %s\n", errno, strerror(errno));
    }
    else
    {
    	printf("wrote %d chars: %s\n", iOut, psOutput);
    } // end if
    return iOut;
} // end WriteAdrPort

// read string from the serial port
// return code:
//   >= 0 = number of characters read
//   -1 = read failed
int ReadAdrPort(char* psResponse, int iMax)
{
    int iIn;

    if (fd < 1)
    {
        printf(" port is not open\n");
        return -1;
    } // end if

    iIn = read(fd, psResponse, iMax-1);

    if (iIn < 0)
    {
    	if (errno == EAGAIN)
    	{
		return 0; // assume that command generated no response
	}
	else
	{
		printf("read error %d %s\n", errno, strerror(errno));
	} // end if
    }
    else
    {
    	psResponse[iIn<iMax?iIn:iMax] = '\0';
	printf("read %d chars: %s\n", iIn, psResponse);
    } // end if
	
    return iIn;
} // end ReadAdrPort

// closes the serial port
void CloseAdrPort()
{
	// you may want to restore the saved port attributes
    if (fd > 0)
    {
        close(fd);
    } // end if
} // end CloseAdrPort


    
