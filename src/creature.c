#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

#include "common.h"
#include "creature.h"

//
//  NOT FOR PUBLIC USE!
//
//  RAM banking shenanigans means this pointer can be corrupted easily!
//  Therefore, only use this at Point Of Sale!
//
Creature* creature_get(OID_CREATURE index) {
    byte bank_index;
    Creature* creature;

    if (index < 64) {
        RAM_BANK = 2 + index/16;        // 0-63 are 512 bytes, in banks 2 thru 5.
        bank_index   = index%16;        // 16 creatures per bank
        creature = (Creature*)(0xA000 + bank_index * 512);
        creature->memory_footprint = CREATURE_TYPE_PLANT; // clubs/"tree"
        creature->bank = 2 + index/16;
    }
    else if (index < 192) {
        RAM_BANK   = index/8 - 2;       // 64-191 are 1,024 bytes, in banks 6 thru 21.
        bank_index = index%8;           // 8 creatures per bank
        creature = (Creature*)(0xA000 + bank_index * 1024);
        creature->memory_footprint = CREATURE_TYPE_ANIMAL; 
        creature->bank = index/8 - 2;
    }
    else {
        RAM_BANK   = index/4 - 26;      // 192-255 are 2,048 bytes, in banks 22 thru 37.
        bank_index = index%4;           // 4 creatures per bank
        creature = (Creature*)(0xA000 + bank_index * 2048);
        creature->memory_footprint = CREATURE_TYPE_ADVANCED; 
        creature->bank = index/4 - 26;
    }
    return creature;
}

Creature* creature_extract(OID_CREATURE index) {
    Creature* creature = creature_get(index);
    return creature;
}

void creature_dump(OID_CREATURE index) {
    Creature* creature = creature_get(index);
	printf("id: %3d, bank: %u, address: %x, x: %2d, y: %2d\n", index, creature->bank, creature, creature->x, creature->y );
}

void creature_init(OID_CREATURE index) {
    Creature* creature = creature_get(index);
    creature->active  = 1;
	creature->x = 5 + rand() % (MAP_WIDTH-10);
	creature->y = 5 + rand() % (MAP_HEIGHT-10);
	creature->action = 0;
}

void creature_show(OID_CREATURE index) {
    Creature* creature = creature_get(index);
	if (creature->active) {
		gotoxy(creature->x, creature->y+1);
		textcolor(COLOR_WHITE);
		cputc(creature->memory_footprint); // 'c'); // 33 + index);
	}
}

void creature_randomWalk(OID_CREATURE index) {
    Creature* creature = creature_get(index);

    if (creature->memory_footprint == CREATURE_TYPE_PLANT) return;
    else switch(rand() % 8) {
        case 0: if ( creature->x > 1 )           creature->x--; break;
        case 1: if ( creature->x < MAP_WIDTH-1)  creature->x++; break;
        case 2: if ( creature->y > 1 )           creature->y--; break;
        case 3: if ( creature->y < MAP_HEIGHT-1) creature->y++; break;
        default: break;
    }
}
