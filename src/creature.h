#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "common.h"

#define CREATURE_TYPE_PLANT			216
#define CREATURE_TYPE_ANIMAL		'c'
#define CREATURE_TYPE_ADVANCED		'a'

typedef struct {
	byte index;
	byte bank;
	unsigned int	x    	:8;
	unsigned int	y    	:7;
	unsigned int	active	:1;
	byte action;
	byte memory_footprint;
} Creature;

Creature* creature_extract(OID_CREATURE i);
void creature_dump(OID_CREATURE i);
void creature_show(OID_CREATURE i);
void creature_init(OID_CREATURE i);
void creature_randomWalk(OID_CREATURE i);

#endif
