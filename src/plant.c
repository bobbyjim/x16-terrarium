#include <stdlib.h>

#include "map.h"
#include "plant.h"

void plant_reproduce(Plant* plant) {
	--plant->size;
}

void plant_grow(Plant* plant) {
	++plant->size;
}

void plant_update(Plant *plant) {
	PlantDNA *dna = &plant->dna;

    byte growth_factor 			= dna->size - dna->lifespan;				// larger plants die young
    byte reproduction_factor	= dna->reproduction_rate - dna->size;		// prolific plants are smaller
    byte death_factor			= dna->lifespan - dna->reproduction_rate;	// longer lifespan reproduce slower

    // Apply the calculated probabilities to growth, reproduction, and death
    if (rand() % 256 < growth_factor) {
        plant_grow(plant);
    }
    if (rand() % 256 < reproduction_factor) {
        // Reproduction logic
        plant_reproduce(plant);
    }
    if (rand() % 256 < death_factor) {
        // Death logic (the plant dies earlier based on its attributes)
        plant->alive = 0;
    }
}

void plant_create_random(int index) {
	Plant* plant;

    SET_MAP_BANK(PLANT_POOL_BANK);  // Set to bank 1
    plant = &PLANT_POOL[index];
    plant->alive = 1;
    plant->x = 1 + rand() % (MAP_COLS-1);
    plant->y = 1 + rand() % (MAP_ROWS-1);
    plant->size = rand() % 32;  // Example size (0-31)
    plant->dna.size = rand() % 32;
    plant->dna.reproduction_rate = rand() % 32;
    plant->dna.lifespan = rand() % 32;
}
