#include <stdio.h>

int main (int argc, char *argv[])
{
	int i = 0;
	
	//go through each string in argv
	//why am I skipping argv[0]?
	for ( i = 1; i < argc; i++ ) {
		printf("arg %d: %s.\n", i, argv[i]);
	}
	
	//let's make our own array of strings.
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas",
		"Washington", NULL
	};
	
	int num_states = sizeof(states)/sizeof(states[0]);
	
	for ( i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i , states[i]);
	}
	
	// Extra Credit
	/*
	printf("extra credit 1:\n");
	for ( i = 0; i < num_states; 
	printf("before: %i.\n", i), 
	i++, 
	printf("after: %i.\n", i)) {
		printf("state %d: %s\n", i , states[i]);
	}*/
	
	printf("extra credit 2:\n");
	//go through each string in argv
	//why am I skipping argv[0]?
	argv[1] = states[0];
	printf("NEW arg 1: %s.\n", argv[1]);
	for ( i = 1; i < argc; i++ ) {
		printf("arg %d: %s.\n", i, argv[i]);
	}
	
	states[0] = argv[2];
	printf("NEW states 0: %s.\n", states[0]);
	for ( i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i , states[i]);
	}
	
	
	
	return 0;
}







