#ifndef _GENETIC_H
#define _GENETIC_H

typedef struct DNA {

	char header[16];
	char common[16];
	char type;
	char gene[223];

} DNA;

// mutates a based on b.  
// a is modified.
void mutate( DNA* a, DNA* b );

#endif
