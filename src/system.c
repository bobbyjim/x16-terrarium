/*

	This file isolates hardware-specific graphics code, in order to allow
	runtime debugging on a non-CX16 platform.

*/
#include <stdio.h>
#include "creature.h"

void system_ack() {
	printf(".");
}

//
//  When running on something else.
//
#ifndef __CX16__
#define clrscr()
#define gotoxy(x,y)
#define textcolor(c)
#define cputc(c)			printf("%c",c)
#define kbhit()				0
#endif
