#include <stdio.h>
#include <string.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 
  
int main(int argc, char *argv[])
{
    int numbers[] = {1, 2, 4, 5};
    char name[] = { 'a', 'b', 'd', '\0'};
    
    // first, print them out raw
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1], numbers[2], numbers[3]);
            
    printf("name each: %c %c %c %c\n",
            name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);

    // setup the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // setup the name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';

    // then print them out initialized
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1], numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1], name[2], name[3]);

    // print the name like a string
    printf("name: %s\n", name);

    // another way to use name
    char *another = "Zed";

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n",
            another[0], another[1], another[2], another[3]);
            
    int i = 0;
    printf("====printing name character by character.\n");
    
    for (i = 0; i < 4; i++) {
    	printf("char at %i: %c\n", i, name[i]);
    	int second = 0;
    	memcpy(&second, &name[i], 1);
    	printf("integer from char: %i\n", second);
    	printf("binary result of integer: "BYTE_TO_BINARY_PATTERN "\n" , BYTE_TO_BINARY(second));
    	printf("binary result of char: "BYTE_TO_BINARY_PATTERN "\n" , BYTE_TO_BINARY(name[i]));
    }

    int second = 0;
    
    memcpy(&second, name, 4);
	printf("result from function %i\n", second);

    return 0;
}

