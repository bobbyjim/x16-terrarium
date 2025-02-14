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
	init();
	map_show();

	for(;;) {
		pause_jiffies(100);
	}
}
