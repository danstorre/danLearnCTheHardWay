#include <stdio.h>

int main(int argc, char* argv[]) {
	int i = 0;
	
	if (argc == 1) {
		printf("ERROR: you need at least one argument.\n");
		return 1;
	}
	
	for (i=1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

    char letter = 'a';
    
    printf("the letter from 'a' is now: %1$c with number: %2$i that is a, and %1$i that is A.\n", letter-32,letter);
    
   	int j = 0;
   	
   	for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch (letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;

            case 'y':
            case 'Y':
                // why i > 2? is this a bug?
                if (i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                    break;
                }

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }
    
    //===== extra credit
   	
   	for (j = 1; j < argc; j++ ) {
   		printf("processing arg at: %i.\n", j);
    	
    	for (i = 0, letter = argv[j][i]; 
    		argv[j][i] != '\0'; 
    		i++, letter = argv[j][i]) {
    	
    	//if the letter is uppercased the lowercase it.
    	if (letter >= 65 && letter < 97) {
    		letter += 32;
    	}
    	
    	if (letter == 'a') {
    		printf("%d: 'a'\n", i);
    	} else 
    	
    	if (letter == 'e') {
    		printf("%d: 'e'\n", i);
    	} else
    	
    	if (letter == 'i') {
    		printf("%d: 'i'\n", i);
    	} else
    	
    	if (letter == 'o') {
    		printf("%d: 'o'\n", i);
    	} else
    	
    	if (letter == 'u') {
    		printf("%d: 'u'\n", i);
    	} else {
    		printf("%d: '%c' is not a vowel\n", i, letter);
    	}
    	
    	}
   	}
    
	
	return 0;
}
