#include "decision.h"
#include "common.h"

void decision_init() {

}

void decide(unsigned char* chemicals, unsigned char* decisions) {
    if (chemicals[CHEM_HUNGRY] > 50) {
        decisions[DECISION_EAT_IT] = 1;
    }
    if (chemicals[CHEM_TIRED] > 50) {
        decisions[DECISION_SLEEP] = 1;
    }
    if (chemicals[CHEM_LONELY] > 50) {
        decisions[DECISION_APPROACH_IT] = 1;
    }
    // More conditions can be added here based on biochemistry and instincts
}
