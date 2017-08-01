#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <errno.h>     
#include <time.h>   
#include <asm-generic/ioctls.h> /* TIOCGRS485 + TIOCSRS485 ioctl definitions */
#include <linux/ioctl.h>
#include <linux/serial.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>

static speed_t baudrate;
static char *device;

// Set the serial in raw mode
void cfmakeraw (struct termios *termios_p)
{
	termios_p->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
	termios_p->c_oflag &= ~OPOST;
	termios_p->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	termios_p->c_cflag &= ~(CSIZE | PARENB);
	termios_p->c_cflag |= CS8;
}

// opens the serial port
// return code:
//   > 0 = fd for the port
//   -1 = open failed
int OpenAdrPort()
{    
struct serial_rs485 rs485conf;
int fd;

	fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
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
		cfsetispeed(&options, baudrate);
		cfsetospeed(&options, baudrate);

		options.c_cflag |= (CLOCAL | CREAD);
	
		//set 8n1
		options.c_cflag &= ~PARENB; /* Enable parity bit */
		options.c_cflag &= ~CSTOPB; /* 	2 stop bits (1 otherwise) */
		options.c_cflag &= ~CSIZE; /* Mask the character size bits */
		options.c_cflag |= CS8; /* Select 8 data bits */
		//options.c_cflag &= ~CRTSCTS;
		cfmakeraw(&options);/* RAW MODE */

		//set raw input
		options.c_lflag &= ~(ICANON | /* Enable canonical input (else raw) */
					ECHO | /*Enable echoing of input characters	*/
					ECHOE | /*Echo erase character as BS-SP-BS*/
					ISIG); /*Enable SIGINTR, SIGSUSP, SIGDSUSP, and SIGQUIT signals*/

		tcsetattr(fd, TCSANOW, &options); /*Make changes now without waiting for data to complete*/

		/* Don't forget to read first the current state of the RS-485 options with ioctl.
			If You don't do this, You will destroy the rs485conf.delay_rts_last_char_tx
			parameter which is automatically calculated by the driver when You opens the
			port device. */
		if (ioctl (fd, TIOCGRS485, &rs485conf) < 0) 
		{
			printf("Error: TIOCGRS485 ioctl not supported.\n");
		}

		/* Enable RS-485 mode: */
		rs485conf.flags |= SER_RS485_ENABLED;

		if (ioctl (fd, TIOCSRS485, &rs485conf) < 0) 
		{
			printf("Error: TIOCSRS485 ioctl not supported.\n");
		}

	} 
	
	return fd;
} 


void closePort(int fd)
{
	close(fd);
}

typedef enum
{
	eInit=0,
	eSend,
	eWaitReceive,
	ePrinteResult,
	eClose,
} eStatus;


void print_usage() 
{
	printf("\nserialport [OPTIONS]: send/receive packages on serial device\n");
	puts("  -d <device>");
	puts("  -b <baudrate>    from 9600 to 115200");
	puts("  -h               show this help\n");
	
	exit(0);
}

/* MAIN */
int main(int argc, char *argv[])
{
int comport;
char packet[50];
eStatus m_status= eInit;
int counter;
char buffer[50];  /* Input buffer */
char bufptr;      /* Current char in buffer */
int nbytes;
int countbyte;
time_t start_t, end_t;
double diff_t;
int c;
int setbaud;
int i;

	opterr = 0;
	baudrate = -1;
  while ((c = getopt (argc, argv, "hd:b:")) != -1)
	{
		switch (c)
		{
			case 'h':
				print_usage();
				
			case 'd':
				device = optarg;
				break;
				
			case 'b':
				setbaud = atoi(optarg);
				if (setbaud == 4800)
				{
					baudrate = B4800;
				}
				else if (setbaud == 9600)
				{
					baudrate = B9600;
				}
				else if (setbaud == 19200)
				{
					baudrate = B19200;
				}
				else if (setbaud == 38400)
				{
					baudrate = B38400;
				}
				else if (setbaud == 57600)
				{
					baudrate = B57600;
				}
				else if (setbaud == 115200)
				{
					baudrate = B115200;
				}
				break;
				
			case '?':
				if (optopt == 'c')
				{
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				}
				else if (isprint (optopt))
				{
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				}
				else
				{
					fprintf (stderr, "Unknown option character `\\x%x'.\n", 	optopt);
				}
				
				return 0;
				
			default:
				break;
		}
	}
	
	if (baudrate == -1 || !device)
	{
		print_usage();
	}
	
  for (i = optind; i < argc; i++)
	{
		printf ("WARN: Non-option argument %s\n", argv[i]);
	}
		
	printf ("Device = %s, Baudrate = %d\n",  device, setbaud);

	while (1)
	{
		switch (m_status)
		{

			case eInit:
				
				printf("Open Port\n");		
				comport = OpenAdrPort();
			
				if (comport < 0)
				{
					perror("Error on open\n");
				}
				else
				{
					counter = 0;
					m_status = eSend;
				}
				break;

			case eSend:
				sprintf(packet,"Test PACKETs %d#",counter++);
				
				if (write(comport, packet, strlen(packet)) < (int)strlen(packet))
				{
					perror("Error on write");
					m_status = eClose;
					sleep(5);
				}
				else
				{
					memset(buffer, 0, sizeof(buffer));
					m_status = eWaitReceive;	
					countbyte = 0;
					printf("sent: [%s]\n",packet);
					time(&start_t);	
				}
				
				break;

			case eWaitReceive:
		
				time(&end_t);
				diff_t = difftime(end_t, start_t);
				if (diff_t > 1.0)
				{
					printf("Timeout\n");
					m_status = eClose;
					sleep(1);	      
				}
	
				if ((nbytes = read(comport, &bufptr, 1)) > 0)
				{   	  
					buffer[countbyte] = bufptr;
					countbyte += nbytes;

					if (countbyte > sizeof(buffer))
					{	
						buffer[sizeof(buffer)-1] = 0;
						printf("Too many char!! [%s]\n",buffer);
					}
					else
					{
						if (bufptr == '#')
						{
							m_status = ePrinteResult;
						}                
					}
				}

				break;


			case ePrinteResult:
				
					printf("received: [%s]\n",buffer);
					m_status = eSend;
					usleep(1000);
					
					break;

			case eClose:
				
					printf("Close Port\n");
					closePort(comport);
					m_status = eInit;
					
					break;
		}
	}
}
