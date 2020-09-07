#include <stdio.h>
#include <stdint.h>


void pointerToArrayOfInts(int (*p)[]);
void betterPointerToArrayOfInts(int *p);
void arrayToPointers(int ages[]);
void processCommandLineArgumenst(int argc, char *argv[]);
void playWithValues();
void printOutAnArgumentWithIndex(char **cur_arg, int i);
void printUsingWhileLoopBackwards(char **cur_name, int *cur_age, int count);

int main(int argc, char *argv[]) 
{

	processCommandLineArgumenst(argc, argv);
	playWithValues();
	
	//create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2};
	
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};
	
	arrayToPointers(ages);
	printf("2value at 0 of ages: %i.\n", ages[0]);
	
	//arrays as pointers classic useless way.
	pointerToArrayOfInts(&ages);
 	printf("value at 2: %i.\n", ages[2]);
 	
 	//arrays as pointers normal way.
 	betterPointerToArrayOfInts(ages);
 	printf("value at 2: %i.\n", ages[2]);
 	
	//safely get the size of ages.
	int count = sizeof(names) / sizeof (char *);
	printf("count at names array: %i.\n", count);
	int i = 0;
	
	// first way using indexing.
	for ( i = 0; i < count; i++) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}
	
	printf("---\n");
	
	// setup the pointers to the end of the arrays.
	int *cur_age = &ages[count-1];
	char **cur_name = &names[count-1];
	
	// second way using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n", *(cur_name - i), *(cur_age - i));
	}
	
	printf("---\n");
	
	printUsingWhileLoopBackwards(cur_name, cur_age, count);
	
	//third way, pointers are just arrays
	for (i = 0; i < count; i++) {
		int backwardsIndex = -(i);
		printf("%s is %d years old.\n", 
		cur_name[backwardsIndex],
		cur_age[backwardsIndex]);
	}
	
	
	printf("---\n");
	
	//fourth way with pointers in a stupid complex way.
	for (cur_name = &names[count-1], cur_age = &ages[count-1];
		(cur_age - ages) >= 0; cur_name--, cur_age--) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
	
	
	long long avaar = 10;
	printf("long long pesa: %lu. \n", sizeof(long long));
	return 0;
}

void printUsingWhileLoopBackwards(char **cur_name, int *cur_age, int count){
	int i=0;
	
	printf("\n===printing with while loops====\n");
	do {
		int deltaBackwardsIndex = -(i);
		printf("%s is %d years old.\n", 
			cur_name[deltaBackwardsIndex],
			cur_age[deltaBackwardsIndex]);
		i++;
	} while (i < count);
	printf("\n===end printing with while loops====\n");
}


//receiving the array by reference. not copoying the whole array. part II
void pointerToArrayOfInts(int (*p)[])
{
    (*p)[2] = 10;
    printf("pointerToArrayOfInts size of p pointer to array: %lu. \n", sizeof(p));
}

//receiving the array by reference. not copoying the whole array.
void betterPointerToArrayOfInts(int *p) {
	p[2] = 2;
	printf("betterPointerToArrayOfInts size of p pointer to array: %lu. \n", sizeof(p));
}

void arrayToPointers(int ages[]) {
	//pointer to array of ints.
	int *p = ages;
	
	p[0] = 32;
	
	printf("value at 0 of ages: %i.\n", ages[0]);	
}

void processCommandLineArgumenst(int argc, char *argv[]) {
	printf("\nstarting ==== \n");
	
	char **cur_arg = argv;
	
	int i = 0;
	
	for (i=1;i < argc;i++) {
		//printf("arg at %i: %s with address %p.\n", i, *(cur_arg+i), cur_arg+i);
		printOutAnArgumentWithIndex(cur_arg, i);
	}

}

void printOutAnArgumentWithIndex(char **cur_arg, int i) {
	printf("arg at %i: %s with address %p.\n", i, *(cur_arg+i), cur_arg+i);
}

void playWithValues() {
	printf("\n====== playing with values ======\n");
	int myAge = 30;
	double myAccount = 1000000;
	float myWill = 1000;
	char mychar = 'D';
	char *myname = "Daniel";
	
	
	int *cur_age = &myAge;
	printf("my current age is: %i and address %p.\n", *cur_age, &myAge);
	
	double *cur_myaccount = &myAccount;
	printf("my current account balance is: %.2f.\n", *cur_myaccount);
	
	char **cur_myname = &myname;
	printf("my nane is: %s.\n", *cur_myname);
	
	char *cur_mychar = &mychar;
	printf("my char is: %c.\n", *cur_mychar);
	
	printf("\n====== ======= ======\n");
}










