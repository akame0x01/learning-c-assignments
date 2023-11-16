#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

	if(argc != 3) {
		puts("Usage: ./binary Firstname Lastname");
		return 0;
	}

	char firstName[30],lastName[30];

	strncpy(firstName,argv[1],30);
	strncpy(lastName,argv[2],30);

	printf("Hi, %s %s \\o/! \n",firstName,lastName);

	return 0;
}