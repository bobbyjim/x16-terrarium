#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "common.h"

typedef struct {
	unsigned char runtime_id;
	int x    :8;
	int y    :8;
	unsigned char action;
} Creature;

void creature_init(Creature* creature);

#endif