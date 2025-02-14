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

Creature creatures[ CREATURE_COUNT ];

extern unsigned char runtime_high_id;

void setPETFont()
{
   // set PET font
   struct regs fontregs;
   fontregs.a = 4; // PET-like
   fontregs.pc = 0xff62;
   _sys(&fontregs);
}

void init() {
	unsigned char i = 0;

	// initialization code goes here
	setPETFont();
	_randomize();
}

void main() {
	unsigned char num_creatures = 3;
	unsigned char i;

	init();
	for(i=0; i<num_creatures; ++i)
		creature_init(&creatures[i]);
	map_show();

	for(;;) {
		map_show();
		pause_jiffies(100);
		for(i=0; i<num_creatures; ++i)
			creature_randomWalk(&creatures[i]);

	}
}
