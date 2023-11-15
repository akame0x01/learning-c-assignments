#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define OK 0
#define ERR 1

static int getLineAndConvertToInt(char *prompt,char *buff,size_t sz) {
	int ch,extra;

	if(sz < 2) 
		return ERR;

	if(prompt != NULL) {
		printf("%s",prompt);
		fflush(stdout);
	}

	if( fgets(buff,sz,stdin) == NULL) 
		return ERR;

	size_t len = strlen(buff);

	if(len < 2) {
		buff[len - 1] = '\0';
		return ERR;
	}

	if(buff[len -1] != '\n') {
		extra = 0;
		while((ch = getchar()) != '\n' && (ch != EOF))
			extra = 1;
		
		if(extra == 1) 
			return ERR;
	}

	buff[len -1] = '\0';

	//converting 

	char *endp;
	int bet;

	bet = strtoul(buff,&endp,10);
	errno = 0;
	if(endp == buff || errno)
		return ERR;
	
	return bet;		 
}

int main() {

	int value;
	char string[] = "Hi, give me a number between 1 and 500 and i gonna tell you their range> ";
	char buff[11];

	if((value = getLineAndConvertToInt(string,buff,sizeof(buff))) == 1) {
		puts("You enter a invalid number,check your input!");
		return 0;
	}

	if(value < 0 || value > 500) {
		puts("Your input is out of range \\o/");
		return 0;
	}

		if(value > 0 && value <= 100)
			puts("Your input is between 0 and 101");

		if(value > 100 && value <= 200) 
			puts("Your input is between 100 and 201");
			
		if(value > 200 && value <= 300) 
			puts("Your input is between 200 and 301");
			
		if(value > 300 && value <= 400) 
			puts("Your input is between 300 and 401");
			
		if(value > 400 && value <= 500) 
			puts("Your input is between 400 and 501");

	return 0;
}


