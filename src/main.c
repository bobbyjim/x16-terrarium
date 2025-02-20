/*


*/
#include <6502.h>
#include <stdlib.h>

#include "common.h"
#include "timer.h"
#include "creature.h"
#include "system.h"
#include "test.h"
#include "map.h"

void setPETFont()
{
   // set PET font
   struct regs fontregs;
   fontregs.a = 4; // PET-like
   fontregs.pc = 0xff62;
   _sys(&fontregs);
}

void init() {
	// initialization code goes here
	setPETFont();
	_randomize();

	creature_memwipe();
	creature_init( 1 ); // activate one
//	creature_dump( i );
}

void main() {
	init();
	map_show();

	for(;;) {
		byte i = rand() % 255; // monte carlo
		Creature* creature = creature_extract(i);
		if (creature->active) {
			map_show_cell(creature->y, creature->x);
			creature_go(i);
			creature_show(i);
		}
	}
}
