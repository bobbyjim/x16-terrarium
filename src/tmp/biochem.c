#include <stdio.h>

#include "biochem.h"
#include "common.h"

const char* chemical_names[] = {
	"none", "alarm", "pain", "hunger", "tired", "comfort", "lonely", "adp", "atp", "starch", "glucose", "glycogen", "panacea"
};

const char* chemical_codes = "aphtcldusgyz";

#define BIOCHEM_RULES_COUNT		8
BiochemRule biochem_rules[] = {
//   Chemical 1   and   Chemical 2      => Chemical 3   and   Chemical 4
    {CHEM_STARCH,    1, 0, 0,              CHEM_GLUCOSE,   4, 0, 0},            // digest food to glucose
    {CHEM_GLUCOSE,   1, CHEM_ADP, 2,       CHEM_ATP,       2, 0, 0},            // glucose charges an expended ATP
    {CHEM_GLUCOSE,   12, 0, 0,             CHEM_GLYCOGEN,  2, 0, 0},            // store glucose as glycogen
    {CHEM_ATP,       2, 0, 0,              CHEM_ADP,       2, 0, 0},            // ATP is expended over time
    {CHEM_HUNGRY,    4, CHEM_COMFORT, 1,   0, 0,              0, 0},            // quench hunger
    {CHEM_GLYCOGEN,  1, 0, 0,              CHEM_GLUCOSE,   6, 0, 0},            // convert glycogen back to glucose
    {CHEM_GLYCOGEN,  0, 0, 0,              CHEM_HUNGRY,    1, 0, 0},            // no glycogen means we get hungry
    {CHEM_ALARM,     1, 0, 0,              0, 0,              0, 0}             // alarm decays over time
};

void biochem_init() {

}

void biochem_apply(Creature* creature) {
	unsigned char i;
	for(i=0; i<BIOCHEM_RULES_COUNT; ++i)
		biochem_apply_rule(creature, &biochem_rules[i]);
}

void biochem_apply_rule(Creature* creature, BiochemRule* rule) {
	// decrease inputs
	creature->chemicals[ rule->input1_type  ] -= rule->input1_amount;
	creature->chemicals[ rule->input2_type  ] -= rule->input2_amount;

	// increase outputs
	creature->chemicals[ rule->output1_type ] += rule->output1_amount;
	creature->chemicals[ rule->output2_type ] += rule->output2_amount;
}

void debug_chemicals(unsigned char* chemicals) {
	int i;
	for(i=1; i<=CHEM_MAX; ++i)
	   printf("%s: %d\n", chemical_names[i], chemicals[i]);
}