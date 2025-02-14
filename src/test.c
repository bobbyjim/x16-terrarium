#include <stdio.h>

#include "test.h"

// include all the headers
#include "creature.h"

// call all the test functions from the other files
void test_all_the_things() {
#ifdef _TESTMODE_
	printf("*** test mode enabled! ***");
	test_creature_init();
#else
	printf("*** test mode not enabled ***");
#endif
}
