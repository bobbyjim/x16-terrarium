#include "instinct.h"
#include "decision.h"
#include "biochem.h"
#include "common.h"

void instinct_process(unsigned char* instincts, unsigned char* decisions) {
    if (instincts[INSTINCT_HUNGRY] > 75) {
        decisions[DECISION_EAT_IT] = 1;
    }
    if (instincts[INSTINCT_TIRED] > 75) {
        decisions[DECISION_SLEEP] = 1;
    }
    if (instincts[INSTINCT_LONELY] > 75) {
        decisions[DECISION_APPROACH_IT] = 1;
    }
    // Additional instincts can be processed here
}
