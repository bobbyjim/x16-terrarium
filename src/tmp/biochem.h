#ifndef _BIOCHEM_H_
#define _BIOCHEM_H_

#include "creature.h"

typedef struct BiochemRule {

	char input1_type, input1_amount;
	char input2_type, input2_amount;
	char output1_type, output1_amount;
	char output2_type, output2_amount;
		
} BiochemRule;

void biochem_init();
void biochem_apply(Creature* creature);
void biochem_apply_rule(Creature* creature, BiochemRule* rule);

#endif