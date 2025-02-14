#include "stimuli.h"
#include "common.h"

void stimuli_process(unsigned char stimulus, unsigned char* chemicals) {
    switch (stimulus) {
        case STIM_HIT:
            chemicals[CHEM_PAIN] += 10;
            chemicals[CHEM_ALARM] += 5;
            break;
        case STIM_EAT:
            chemicals[CHEM_HUNGER] -= 10;
            chemicals[CHEM_COMFORT] += 5;
            break;
        case STIM_ALARM:
            chemicals[CHEM_ALARM] += 10;
            break;
        // Add other stimuli as necessary
	}
}
