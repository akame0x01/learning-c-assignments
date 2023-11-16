//Easy Mode: Allocate an arbitrary amount of indices to your char array and pray to the gods that the user input fits.
//Extra Credit: Dynamically allocate the array size of your char variable based on the length of the user's input.

#include <stdio.h>
#include <string.h>

#define OK 0
#define NO_INPUT 1
#define TOO_LONG 2
#define SMALL_BUFF 3

static int getLine(char *prompt,char *buff,size_t sz) {
	/* 
	char *prompt -> this function receives a char sequence called by prompt, this is an string that will be show in terminal;
	char *buff -> receives a pointer to an variable
	char size_t -> size_t to allocate the memory properly
	*/

	int ch,extra;

	//check if the size is less than 2bytes, if it is i don't even try and return the function because i need memory to 
	if (sz < 2 ) {
		return SMALL_BUFF;
	}

	// print the message in terminal if it is not null and clean the buffer after this
	if (prompt != NULL) {
		printf("%s\n", prompt);
		fflush (stdout);
	} 

	// fgets to var buff, max size is sz and the input comes from stdin; after check if its NULL and return if its
	if ( fgets(buff,sz,stdin) == NULL) {
		return NO_INPUT;
	}

	//after get the input, store the size in len size_t var
	size_t len = strlen(buff);

	if(len < 2) {
		buff[len -1] = '\0';
		return NO_INPUT;
	}

	
	if(buff[len - 1 ] != '\n') {
		extra = 0;
		//discarting extras characters and returns TOO_LONG if extras charactes exists
		while(((ch = getchar()) != '\n') && (ch != EOF))
			extra = 1;
		return ( extra == 1 ) ? TOO_LONG : OK;
	}

	buff[len - 1 ] = '\0';
	return OK;

}


int main(int argc, char *argv[]) {
	printf("Hi bro, give me your first and last name please?\n");
	
	int rc;
	int rc2;
	char firstName[20];
	char lastName[20];

	rc = getLine("Enter your first name> ",firstName,sizeof(firstName));
	rc2 = getLine ("Enter your last name> ",lastName,sizeof(lastName));

	if(rc == NO_INPUT || rc2 == NO_INPUT) {
		printf("I didn't receive any name from you\n");
		return 1;
	}

	if (rc == TOO_LONG || rc2 == TOO_LONG) {
		printf("I can't handle your name is too long wtf\n");
		return 1;
	}

	printf ("thank you [%s %s]\n",firstName, lastName);

	return 0;

}