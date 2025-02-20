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
}

void main() {
	byte num_creatures = 255;
	byte i;
	Creature* creature;

	init();
	for(i=0; i<num_creatures; ++i) {
		creature_init( i );
		creature_dump( i );
	}

	map_show();

	for(;;) {
		for(i=0; i<num_creatures; ++i) {
			creature = creature_extract(i);
			map_show_cell(creature->y, creature->x);
			creature_randomWalk(i);
			//creature_dump(i);
			creature_show(i);
			//pause_jiffies(1);
		}
	}
}
