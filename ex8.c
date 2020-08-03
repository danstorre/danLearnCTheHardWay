#include <stdio.h>

int main(int argc, char* argv[]) {
	int count = (argc - 1);
	int i = 0;
	
	if (count == 0) {
		printf("You are good to go. continue.\n");
	} else if (count == 1) {
		printf("You only have one argument. You suck.\n");
	} else if (count > 1 && count < 4) {
		printf("Here's your arguments: \n");
		
		for (i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}
	
	return 0;
}
