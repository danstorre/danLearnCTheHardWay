#include <stdio.h>

// go to https://linux.die.net/man/3/printf

void crash() {
	char *test = NULL;
	
	printf("%c", test[0]);
}

int main()
{
	int age = 100;
	int height = 72;
	int height2 = 1;
	float fheight = 72;
	
	printf("I'm %d years old.\n", age);
	printf("I'm %#f inches tall. (# flag)\n", fheight);
	printf("I'm %010d inches tall. (0 flag)\n", height);
	printf("I'm %-10d inches tall. (- flag)\n", height);
	printf("I'm %''10d inches tall. ('' flag)\n", height);
	printf("I'm %+1d inches tall. (+ flag)\n", height);
	printf("I'm %''*d inches tall. ('' flag and * field width)\n", 10, height);
	printf("I'm %.*d inches tall. (only precision of 2)\n", 2, height2);
	
	crash();
	
	return 0;
}
