#include "map.h"
#include "common.h"
#include "system.h"

#include <conio.h>

void map_show() {
	unsigned char col, row;
	unsigned int  index;
	char value;

	RAM_BANK = RAM_BANK_MAP;

    clrscr();
	textcolor(COLOR_LIGHTGREEN);
	cputsxy(0,0,"x16 terrarium");
    gotoxy(0,1);
    for(row=0; row<MAP_HEIGHT; ++row)	
	{
	   for(col=0; col<MAP_WIDTH; ++col)
	   {
		  index = col + row * MAP_WIDTH;
          value = ((char*)(0x8000))[index];
		  if (value > 0) {
			textcolor(COLOR_BROWN);
			cputc('x');
		  }
		  else {
			textcolor(COLOR_BLUE);
			cputc('.');
		  }
	   }
//	   cprintf("\n");
	}
}