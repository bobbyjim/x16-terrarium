#ifndef _BIOCHEM_H_
#define _BIOCHEM_H_

#include "creature.h"
#include "common.h"

typedef struct BiochemRule {

	byte input1_type, input1_amount;
	byte input2_type, input2_amount;
	byte output1_type, output1_amount;
	byte output2_type, output2_amount;
		
} BiochemRule;

typedef struct StateRule {

	byte chem_compare_type;
	byte chem_target_type;
	byte less_than_threshold;		// then target+1
	byte greater_than_threshold;	// then target-1

} StateRule;

void biochem_init(Creature* creature);
byte biochem_apply(Creature* creature);
byte biochem_consume_energy(Creature* creature, byte amount);

#endif