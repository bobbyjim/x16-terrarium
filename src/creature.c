#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "creature.h"

unsigned char runtime_high_id = 0;

void creature_init(Creature* creature) {

	creature->runtime_id = runtime_high_id++;
	creature->x = rand() % MAP_WIDTH;
	creature->y = rand() % MAP_HEIGHT;
	creature->action = 0;
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

