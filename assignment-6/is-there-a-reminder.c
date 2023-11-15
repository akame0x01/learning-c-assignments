#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>

#define OK 0
#define NO_INPUT 1
#define TOO_LONG 2
#define SMALL_BUFF 3

static int getLine(char *prompt,char *buff,size_t sz) {
	int ch,extra;

	if(sz < 2) {
		return SMALL_BUFF;
	}

	if(prompt != NULL) {
		printf("%s",prompt);
		fflush(stdout);
	}

	if(fgets(buff,sz,stdin) == NULL) {
		return NO_INPUT;
	}

	size_t len = strlen(buff);

	if(len < 2) {
		buff[len - 1] = '\0';
		return NO_INPUT;
	}

	if(buff[len - 1] != '\n') {
		extra = 0;
		while((ch = getchar()) != '\n' && (ch != EOF))
			extra = 1;
		return ( extra == 1) ? TOO_LONG : OK;
	}

	buff[len - 1] = '\0';
	return OK;
}

int convertToInt(char *string) {
	char *x;
	char *endp;
	int bet;
	
	for (x = string; *x != '\0'; x++) {
		if(!isdigit(*x)) 
			return 0L;
	}

	bet = strtoul(string,&endp,10);

	errno = 0;
	if(endp == string || errno) 
		return 0;
	
	return bet;
}

int main() {
	char numerator[11];
	char denominator[11];
	int rc1, rc2;
	int intNumerator, intDenominator;

	if( (rc1 = getLine("Enter a numerator here> ",numerator,sizeof(numerator))) > 0) {
		puts("Invalid number entered");
		return 0;
	} 

	if( (intNumerator = convertToInt(numerator)) == 0 ) {
		puts("Invalid number entered or a junk ocorred!");
		return 0;
	}

	if ( (rc2 = getLine("Enter a denominator here> ",denominator,sizeof(denominator))) > 0) {
		puts("Invalid number entered");
		return 0;
	}

	if ( (intDenominator = convertToInt(denominator)) == 0) {
		puts("Invalid number entered or a junk ocorred!");
		return 0;
	}

	if( intNumerator % intDenominator == 0) {
		puts("There isn't a remainder!");
		return 0;
	}

	puts("There is a remainder!");
	return 0;
}