/*

	This file isolates hardware-specific graphics code, in order to allow
	runtime debugging on a non-CX16 platform.

*/
#include <stdio.h>
#include "creature.h"

void graphics_ack() {
	printf(".");
}

#ifdef __CX16__
#include <conio.h>
#else
//#define clrscr()
//#define gotoxy(x,y)
//#define textcolor(c)
//#define cputc(c)			printf("%c",c)
//#define kbhit()				0
#endif

void print_creature(Creature* creature) {
	printf("id: %u, (%d,%d) action: %u\n", 
		creature->runtime_id,
		creature->x,
		creature->y,
		creature->action);
}