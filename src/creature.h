#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "common.h"

#define CREATURE_TYPE_PLANT			216
#define CREATURE_TYPE_ANIMAL		'c'
#define CREATURE_TYPE_ADVANCED		'a'

typedef struct {
	byte index;							// 4
	byte bank;							// 
	byte memory_footprint;				// 
	unsigned int	x    	:8;			// 
	unsigned int	y    	:7;
	unsigned int	active	:1;			// 5
	byte action;						// 
	byte current_age;					// 
	byte size;							// 
	byte energy;						// 

	byte habitat_min_soil_quality;		// 7
	byte habitat_max_soil_quality;		// 
	byte growth_speed;					// 
	byte size_for_reproduction;			// 
	byte offspring_count;				// 
	byte offspring_spread_radius;		// 
	byte lifespan;						// 

	byte chemicals	[ CHEM_MAX 	   ]; 	// 13
	byte stimuli	[ STIM_MAX	   ]; 	// 5
	byte decisions	[ DECISION_MAX ]; 	// 8

} Creature; 							// 42 bytes total

void creature_memwipe();
Creature* creature_extract(OID_CREATURE i);
void creature_dump(OID_CREATURE i);
void creature_show(OID_CREATURE i);
void creature_init(OID_CREATURE i);
void creature_go(OID_CREATURE i);
int  findEmptySlot();
void creature_debug(OID_CREATURE index);

#endif
