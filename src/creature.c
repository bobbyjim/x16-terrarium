#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

#include "common.h"
#include "creature.h"

#define     GROUP_1_START_BANK          2
#define     GROUP_1_COUNT               128
#define     GROUP_1_CREATURE_SIZE       512
#define     GROUP_1_CREATURES_PER_BANK  (8192/GROUP_1_CREATURE_SIZE)
#define     GROUP_1_BANKS               GROUP_1_COUNT/GROUP_1_CREATURES_PER_BANK

#define     GROUP_2_START_BANK          (GROUP_1_START_BANK+GROUP_1_BANKS)
#define     GROUP_2_COUNT               64
#define     GROUP_2_CREATURE_SIZE       1024
#define     GROUP_2_CREATURES_PER_BANK  (8192/GROUP_2_CREATURE_SIZE)
#define     GROUP_2_BANKS               GROUP_2_COUNT/GROUP_2_CREATURES_PER_BANK

#define     GROUP_3_START_BANK          (GROUP_2_START_BANK+GROUP_2_BANKS)
#define     GROUP_3_COUNT               64
#define     GROUP_3_CREATURE_SIZE       2048
#define     GROUP_3_CREATURES_PER_BANK  (8192/GROUP_3_CREATURE_SIZE)
#define     GROUP_3_BANKS               GROUP_3_COUNT/GROUP_3_CREATURES_PER_BANK
//
//  NOT FOR PUBLIC USE!
//
//  RAM banking shenanigans means this pointer can be corrupted easily!
//  Therefore, only use this at Point Of Sale!
//
Creature* creature_get(OID_CREATURE index) {
    byte bank_index;
    Creature* creature;

    if (index < GROUP_1_COUNT) {
        RAM_BANK    = GROUP_1_START_BANK + index/GROUP_1_CREATURES_PER_BANK;
        bank_index  = index%GROUP_1_CREATURES_PER_BANK;        
        creature    = (Creature*)(0xA000 + bank_index * GROUP_1_CREATURE_SIZE);
        creature->memory_footprint = CREATURE_TYPE_PLANT; 
    }
    else 
    {
        index -= GROUP_1_COUNT;
        if (index < GROUP_2_COUNT) {
            RAM_BANK   = GROUP_2_START_BANK + index/GROUP_2_CREATURES_PER_BANK;
            bank_index = index%GROUP_2_CREATURES_PER_BANK;    
            creature = (Creature*)(0xA000 + bank_index * GROUP_2_CREATURE_SIZE);
            creature->memory_footprint = CREATURE_TYPE_ANIMAL; 
        }
        else {
            index -= GROUP_2_COUNT;
            RAM_BANK   = GROUP_3_START_BANK + index/GROUP_3_CREATURES_PER_BANK;
            bank_index = index%GROUP_3_CREATURES_PER_BANK;     
            creature = (Creature*)(0xA000 + bank_index * GROUP_3_CREATURE_SIZE);
            creature->memory_footprint = CREATURE_TYPE_ADVANCED; 
        }
    }
    creature->bank = RAM_BANK;
    return creature;
}

void creature_memwipe() {
    byte i;
    for(i=GROUP_1_START_BANK; i<GROUP_3_START_BANK+GROUP_3_BANKS; ++i)
    {
        RAM_BANK = i;
        memset( ((void*)0xa000), 0, 8192);
    }
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
		textcolor(COLOR_GREEN);
		cputc(creature->memory_footprint);
	}
}

void creature_go(OID_CREATURE index) {
    Creature* creature = creature_get(index);

    if (creature->memory_footprint == CREATURE_TYPE_PLANT) {
        // do something plantlike?
    }
    else switch(rand() % 8) {
        case 0: if ( creature->x > 1 )           creature->x--; break;
        case 1: if ( creature->x < MAP_WIDTH-1)  creature->x++; break;
        case 2: if ( creature->y > 1 )           creature->y--; break;
        case 3: if ( creature->y < MAP_HEIGHT-1) creature->y++; break;
        default: break;
    }
}

byte findEmptySlot() {
    byte i;
    for(i=0; i<256; ++i) {
        Creature* creature = creature_get(i);
        if (creature->active == 0)
            return i;
    }
    return 0; // so 0 is never active?
}
