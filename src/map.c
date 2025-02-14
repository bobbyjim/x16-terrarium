#include "map.h"
#include "common.h"
#include "system.h"
#include "creature.h"

#include <conio.h>

extern Creature creatures[];

void map_show() {
	unsigned char col, row;
	unsigned int  index;
	char value;

	RAM_BANK = RAM_BANK_MAP;

    clrscr();
	textcolor(COLOR_RED);
	cputsxy(65,0,"x16 terrarium");
    gotoxy(0,1);
    for(row=0; row<MAP_HEIGHT; ++row)	
	{
	   for(col=0; col<MAP_WIDTH; ++col)
	   {
		  index = col + row * MAP_WIDTH;
          value = ((char*)(0x8000))[index];
		  if (value > 15) {
			textcolor(COLOR_GRAY3);
			cputc('.');
		  }
		  else if (value > 5) {
			textcolor(COLOR_GRAY2);
			cputc('.');
		  }
		  else if (value > 0) {
			textcolor(COLOR_GRAY1);
			cputc('.');
		  }
		  else {
			textcolor(COLOR_BROWN);
			cputc('.');
		  }
	   }
	}

	for(index=0; index<CREATURE_COUNT; ++index) {
		if (creatures[index].runtime_id > 0) {
			gotoxy(creatures[index].x, creatures[index].y);
			textcolor(COLOR_WHITE);
			cputc('c');
		}
	}
}