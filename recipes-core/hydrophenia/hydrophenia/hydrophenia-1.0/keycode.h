#ifndef KEYCODE_H
#define KEYCODE_H

#define K_HOME 0
#define K_SERRA 1
#define K_VASCHE 2
#define K_SETTINGS 3

#define K_FRAGOLE 4
#define K_MIRTILLI 5
#define K_UVA 6
#define K_POMODORI 7

#define K_BACK 8

#define K_REALTIME 9

//#define X86

#ifdef X86
    #define SHOW (this->show())
#else
    #define SHOW (this->showFullScreen())
#endif


#endif // KEYCODE_H
