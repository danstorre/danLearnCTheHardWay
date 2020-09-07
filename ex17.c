#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// API
void die(const char *message)



//Implementation
void die(const char *message) 
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	
	exit(1);
}


int main(int count, char *argv[])
{
	if (count < 3) {
		die("USAGE: ex17 <dbfile> <action> [action params]");
	}

}
