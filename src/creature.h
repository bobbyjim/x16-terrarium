#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "common.h"

typedef struct {
	unsigned char 	runtime_id;
	unsigned int 	x    :8;
	unsigned int 	y    :8;
	unsigned char 	action;
} Creature;

void creature_init(Creature* creature);
void creature_randomWalk(Creature* creature);

#endif
