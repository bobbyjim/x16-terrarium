#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "common.h"
#include "creature.h"

unsigned char runtime_high_id = 0;

void creature_init(Creature* creature) {

	creature->runtime_id = ++runtime_high_id;
	creature->x = 5 + rand() % (MAP_WIDTH-10);
	creature->y = 5 + rand() % (MAP_HEIGHT-10);
	creature->action = 0;
}

void creature_show(Creature* creature) {
	if (creature->runtime_id > 0) {
		gotoxy(creature->x, creature->y+1);
		textcolor(COLOR_WHITE);
		cputc('c');
	}
}

void creature_randomWalk(Creature* creature) {
    int dx = rand() % 2;
    int dy = rand() % 2;
    if ( (rand() % 2) && creature->x > 1 ) creature->x += dx;
    if ( (rand() % 2) && creature->x < MAP_WIDTH-1) creature->x -= dx;
    if ( (rand() % 2) && creature->y > 1 ) creature->y += dy;
    if ( (rand() % 2) && creature->y < MAP_HEIGHT-1) creature->y -= dy;
}

#ifdef _TESTMODE_
void test_creature_init() {
    Creature test_creature;
    creature_init(&test_creature);

    // Assert conditions
    assert(test_creature.runtime_id == 0);  // Assuming it's the first ID
    assert(test_creature.x >= 0 && test_creature.x < GRID_WIDTH);
    assert(test_creature.y >= 0 && test_creature.y < GRID_HEIGHT);
}
#endif

