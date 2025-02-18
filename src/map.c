#include <cx16.h>
#include <conio.h>

#include "map.h"
#include "common.h"
#include "system.h"
#include "creature.h"

extern Creature creatures[];

//struct __vera_layer0 {
//	int map_height   :2;
//	int map_width    :2;
//	int text256color :1;
//	int bitmapmode   :1;
//	int color_depth  :2;
//
//	unsigned char mapbase;
//	
//	int tilebase     :6;
//	int tile_height  :1;
//	int tile_width   :1;
//};

/*
void map_init_tilemap() {
	//                           HHWWtBCC
	VERA.layer0.config       = 0b10011000;    
	//                           | | | |
	//            128 pix high = 10| | |
	//             64 pix wide   = 01| |
	//  text, 256 color foreground = 1 |
	//         mode 0 (tile mode)   = 0|
	//  color depth 0 (text)         = 00
	//
	VERA.layer0.mapbase   = 0x4000  / 512; // my map at $4000
	VERA.layer0.tilebase  = 0x1f000 / 512; // PETSCII at $1f000
	VERA.display.video   |= 0b00010000;     // enable layer 0
}
*/

void map_show_cell(unsigned char row, unsigned char col) {
	unsigned int  index = col + row * MAP_WIDTH;
    unsigned char value = ((char*)(0x8000))[index];

	RAM_BANK = RAM_BANK_MAP;

	gotoxy(col, row+1);

	if (value > 8) value = 9;

	switch(value) {
		case 9: textcolor(COLOR_GRAY3); break;
		case 8:
		case 7:
		case 5: textcolor(COLOR_GRAY2); break;
		case 4:
		case 3:
		case 2:
		case 1: textcolor(COLOR_GRAY1); break;
		case 0: textcolor(COLOR_BROWN); break;
	}
	cputc('.');
}

void map_show() {
	unsigned char col, row;
	//unsigned int  index;
	//char value;

	RAM_BANK = RAM_BANK_MAP;

    clrscr();
	textcolor(COLOR_RED);
	cputsxy(65,0,"x16 terrarium");
    for(row=0; row<MAP_HEIGHT; ++row)	
	{
	   for(col=0; col<MAP_WIDTH; ++col)
	   {
		  map_show_cell(row, col);
	   }
	}
}