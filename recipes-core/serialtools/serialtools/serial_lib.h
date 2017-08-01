#ifndef __SERIAL_LIB__
#define __SERIAL_LIB__
int OpenAdrPort (char* sPortNumber);
int WriteAdrPort(char* psOutput);
int ReadAdrPort(char* psResponse, int iMax);
void CloseAdrPort();
#endif    


