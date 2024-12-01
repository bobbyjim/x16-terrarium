#ifndef _PLANT_H_
#define _PLANT_H_

#include "common.h"

#define	MAX_PLANTS	1600
#define PLANT_POOL_BANK 1
#define PLANT_POOL_SIZE (MAX_PLANTS * sizeof(Plant))

// Define a pointer to the plant pool in high RAM (bank 1)
#define PLANT_POOL ((Plant*) 0xA000)

typedef struct {
	int 	size				:5;	// growth/spread
	int 	reproduction_rate	:5;	// seeds per cycle
	int 	lifespan			:5;	// cycles alive
	int		u1					:1; // unused
} PlantDNA;

typedef struct {
	PlantDNA dna;
	int		x 	  :7;
	int		alive :1;
	int		y 	  :7;
	int     u1    :1;	// unused
	int     size  :8;
} Plant;

void plant_update(Plant *plant);
void plant_create_random();

#endif