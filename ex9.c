#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int i = 0;
	
	while (i < argc) {
		printf("arg%d: %s\n", i, argv[i]);
		i++;
	}
	
	
	char* states[] = { "California", "Oregon", "Washington", "Texas"};
	unsigned long sizeOfStates = sizeof(states);
	int sizeOfState = sizeof(states[0]);
	i = 0;
	
	while (i < sizeOfStates/sizeOfState) {
		if (strncmp(states[i], "Oregon", 10) == 0) {
			i++;
			continue;
		}
		printf("state %i: %s\n", i, states[i]);
		
		if (strncmp(states[i], "Washington", 10) == 0) {
			break;
		}
		i++;
	}
	
	i = 25;
	
	while (i >= 0) {
		printf("number %i.\n", i);
		i--;
	}
	
	return 0;
}
