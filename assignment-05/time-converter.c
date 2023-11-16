/*
Prompt the user for a number of seconds. Take the user's input and convert the number of seconds into its duration in Hours, Minutes, and remaining Seconds.

Extra Credit: Make sure the Hours, Minutes, and Seconds print with no decimal places. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define OK 0
#define TOO_SMALL 1
#define TOO_LONG 2
#define NO_INPUT 3

static int getLine(char *prompt,char *buff,size_t sz) {
	int ch,extra;

	if(sz < 2) {
		return TOO_SMALL;
	}

	if(prompt != NULL) {
		printf("%s",prompt);
		fflush(stdout);
	}

	if( !fgets(buff,sz,stdin)) {
		return NO_INPUT;
	}

	size_t len = strlen(buff);

	if(len < 2) {
		buff[len -1] = '\0';
		return NO_INPUT;
	}

	if (buff[len -1] != '\n') {
		extra = 0;
		while( (ch = getchar() != '\n') && (ch != EOF)) 
			extra = 1;
		if (extra == 1 ) {
			return TOO_LONG;
		}
		return OK;
	}

	buff[len - 1] = '\0';
	return OK;
}

//this function is used to convert the input from seconds to unsigned int.
unsigned int convert(char *string) {
	char *x;
	char *endp;
	unsigned long bet;

	//makes the char point to beggining of the string.
	//checks if is a null character
	// if isnt, go to next character using x++

	for (x = string ; *x != '\0' ; x++) {

	  	if (!isdigit(*x))
	    	return 0L;
	}

	bet = strtoul(string, &endp, 10);

	errno = 0;
	if(endp == string || errno) {
		puts("Invalid number entered or a junk ocorred!");
		return 0;
	}

	return bet;
}

void timeConverter(unsigned long time) {
	int convertedTimeInHour;
	int convertedTimeInMinutes;
	int convertedTimeinSeconds;

	convertedTimeInHour = time / 3600;
	convertedTimeInMinutes = (time%3600 )/60;
	convertedTimeinSeconds = time%60;

	printf("%lu seconds is equal to %d hours, %d minutes and %d seconds\n",time,convertedTimeInHour,convertedTimeInMinutes,convertedTimeinSeconds);

}

int getTime(unsigned long *seconds) {

	int confSeconds;
	char secondsbuff[11];
	unsigned long convertedSeconds;

	confSeconds = getLine("Enter the amount of seconds> ",secondsbuff,sizeof(secondsbuff));

	if( (confSeconds == 1) || (confSeconds == 2) || (confSeconds == 3) ) {
		printf("You can't enter characters to me like this: \"%s\".",secondsbuff);
		
		return 0;
	} 

	convertedSeconds = convert(secondsbuff);

	if(convertedSeconds != 0) {
		*seconds = convertedSeconds;
		return 1;
	} 
	return 0;
}

int main(void) {

	unsigned long seconds;
	unsigned long *secondsPointer = &seconds;
	int checkTime;
	double convertedTime;

	checkTime = getTime(secondsPointer);

	if(checkTime == 0 ){
		puts("An error occurred check your input and try again");
	}

	timeConverter(seconds);

	return 0;
}