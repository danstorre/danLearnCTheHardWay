#include <stdio.h>
#include <stdint.h>


void pointerToArrayOfInts(int (*p)[]);
void betterPointerToArrayOfInts(int *p);
void arrayToPointers(int ages[]);

int main(int argc, char *argv[]) 
{
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
	int count = sizeof(ages) / sizeof (int);
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


//receiving the array by reference. not copoying the whole array. part II
void pointerToArrayOfInts(int (*p)[])
{
    (*p)[2] = 10;
}

//receiving the array by reference. not copoying the whole array.
void betterPointerToArrayOfInts(int *p) {
	p[2] = 2;
}

void arrayToPointers(int ages[]) {
	//pointer to array of ints.
	int *p = ages;
	
	p[0] = 32;
	
	printf("1value at 0 of ages: %i.\n", ages[0]);	
}











