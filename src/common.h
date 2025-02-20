#ifndef _COMMON_H_
#define _COMMON_H_

#define	byte	unsigned char
#define OID_CREATURE    unsigned char

#define	RAM_BANK_MAP	1

// A constants file helps remove circular dependencies.

#define	CREATURE_COUNT	10

// Environment 
#define	MAP_WIDTH		80
#define MAP_HEIGHT		58

// Biochem
#define	CHEM_MAX      12
#define CHEM_ALARM     1	// Drive
#define CHEM_PAIN      2	// Drive
#define CHEM_HUNGRY    3	// Drive
#define CHEM_TIRED     4	// Drive
#define CHEM_COMFORT   5	// Drive
#define CHEM_LONELY    6	// Drive
#define CHEM_ADP       7 	// Resource
#define CHEM_ATP       8 	// Resource
#define CHEM_STARCH    9 	// Resource
#define CHEM_GLUCOSE   10	// Resource
#define CHEM_GLYCOGEN  11	// Resource
#define CHEM_PANACEA   12	// Resource

// Instincts
#define INSTINCT_MAX		3
#define	INSTINCT_HUNGRY		1
#define INSTINCT_TIRED		2
#define INSTINCT_LONELY		3

// Stimuli
#define STIM_MAX		4
#define	STIM_HIT		1
#define STIM_EAT		2
#define STIM_FEAR		3
#define STIM_COMFORT	4

// Decisions
#define DECISION_MAX               7
#define DECISION_RUMINATE          1
#define DECISION_SLEEP             2
#define DECISION_SPEAK             3
#define DECISION_EAT_IT            4
#define DECISION_APPROACH_IT       5
#define DECISION_RETREAT_FROM_IT   6
#define DECISION_FOLLOW_IT         7



#endif
