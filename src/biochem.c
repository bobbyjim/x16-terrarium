#include <stdio.h>
#include <stdlib.h>

#include "biochem.h"
#include "common.h"
#include "creature.h"

const char* chemical_names[] = {
	"none", 	"alarm", 	"pain", 	"hunger", 
	"tired", 	"comfort", 	"lonely", 	"adp", 
	"atp", 		"starch", 	"glucose", 	"glycogen", "panacea"
};

const char* chemical_codes = " aphtcldusgyz";

#define STATE_RULES_COUNT		1
StateRule state_rules[] = {
	// 	Compare Chemical	Target Chem 	+ if less than:		-1 if greater than:
	{ 	CHEM_GLUCOSE, 		CHEM_HUNGRY, 	1, 					10 }
};

#define BIOCHEM_RULES_COUNT		6
BiochemRule biochem_rules[] = {
//   Chemical 1   and   Chemical 2      => Chemical 3   and   Chemical 4 
    {CHEM_STARCH,    1, 0, 0,              CHEM_GLUCOSE,   4, 0, 0},            // digest food to glucose
    {CHEM_GLUCOSE,   2, CHEM_ADP, 4,       CHEM_ATP,       4, 0, 0},            // glucose charges an expended ATP
    {CHEM_GLUCOSE,   12, 0, 0,             CHEM_GLYCOGEN,  2, 0, 0},            // store glucose as glycogen
    {CHEM_ATP,       1, 0, 0,              CHEM_ADP,       1, 0, 0},  			// ATP is expended over time
    {CHEM_GLYCOGEN,  1, 0, 0,              CHEM_GLUCOSE,   6, 0, 0},  			// convert glycogen back to glucose
    {CHEM_ALARM,     1, 0, 0,              0, 0,              0, 0}             // alarm decays over time
	// Can non-mobile creatures have a rule that adds starch based on the soil quality?
};

void biochem_init(Creature* creature) {
	byte i;
	
	for(i=0; i<CHEM_MAX; ++i)
		creature->chemicals[i] = 0;

	creature->chemicals[CHEM_ADP] 		= 20;
	creature->chemicals[CHEM_ATP] 		= 4;
	creature->chemicals[CHEM_STARCH] 	= 20;
	creature->chemicals[CHEM_GLUCOSE] 	= 20;
	creature->chemicals[CHEM_GLYCOGEN] 	= 20;
	creature->chemicals[CHEM_PANACEA]	= 20;
}

//
// private biochem_apply_rule()
//
void biochem_apply_rule(Creature* creature, BiochemRule* rule) {
	if (creature->chemicals[ rule->input1_type  ] >= rule->input1_amount
	 && creature->chemicals[ rule->input2_type  ] >= rule->input2_amount
	 && creature->chemicals[ rule->output1_type ] + rule->output1_amount < 255
	 && creature->chemicals[ rule->output2_type ] + rule->output2_amount < 255) {
		// decrease inputs
		creature->chemicals[ rule->input1_type  ] -= rule->input1_amount;
		creature->chemicals[ rule->input2_type  ] -= rule->input2_amount;

		// increase outputs
		creature->chemicals[ rule->output1_type ] += rule->output1_amount;
		creature->chemicals[ rule->output2_type ] += rule->output2_amount;
	}
}

BiochemRule expend_energy = {
	CHEM_ATP,       1, 0, 0,              CHEM_ADP,       1, 0, 0
};

byte biochem_consume_energy(Creature* creature, byte amount) {

	if (creature->chemicals[CHEM_ATP] <= amount) return 255; // error
	expend_energy.input1_amount = amount;
	expend_energy.output1_amount = amount;
	biochem_apply_rule(creature, &expend_energy);
	return 0;												 // success
}

byte biochem_apply(Creature* creature) {
	unsigned char i = rand() % BIOCHEM_RULES_COUNT; // monte carlo
//	for(i=0; i<BIOCHEM_RULES_COUNT; ++i)
	biochem_apply_rule(creature, &biochem_rules[i]);

	if (creature->chemicals[CHEM_GLUCOSE] == 0 
	 && creature->chemicals[CHEM_GLYCOGEN] == 0)
       return 0;
	
	return 1; // alive
}

void debug_chemicals(unsigned char* chemicals) {
	int i;
	for(i=1; i<CHEM_MAX; ++i)
	   printf("%s: %d\n", chemical_names[i], chemicals[i]);
}

