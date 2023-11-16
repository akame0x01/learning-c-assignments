/* 
Prompt the user to input the length of a radius and then print the area of the user's circle to the terminal.

Extra credit: Use the #define feature of C to assign the value 3.14 to PIE.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 0
#define SMALL_BUFF 1
#define TOO_LONG 2
#define NO_INPUT 3

static int getLine(char *prompt,char *buff,size_t sz) {

	int ch,extra;

	if (sz < 2) {
		return SMALL_BUFF;
	}

	if(prompt != NULL) {
		printf("%s",prompt);
		fflush(stdout);
	}

	if( fgets(buff,sz,stdin) == NULL ) {
		return NO_INPUT;
	}

	size_t len = strlen(buff);
	
	if(len < 2) {
		buff[len -1] = '\0';
		return NO_INPUT;
	}

	if(buff[len -1] != '\n') {
		extra = 0;
		while( (ch = getchar() != '\n') && (ch != EOF ) ){
			extra = 1;
		}
		if (extra == 1) {
			return TOO_LONG;
		}
	}

	buff[len -1] = '\0';
	
	return OK;
}

void calcArea(char *buff, double *area) {
	
	char *trash;
	double radius;
	double pi = 3.14;

	radius = strtod(buff,&trash);

	if(radius <= 0) {
		printf("You can't send characters to me like this: \"%s\". I only accept positive numbers!\n",buff);
		return;
	}

	*area = pi * (radius * radius);

	printf("your radius is: %.3f\n",radius);
	printf("the pi value is: %.3f\n", pi);
	printf("and the area of your circle is: %.3f\n",*area);
	
}



int main() {

	int conf;
	char buff[10];
	double areaOfCircle = 0;

	conf = getLine("Enter the radius of your circle> ",buff,sizeof(buff));

	if(conf == NO_INPUT || conf == TOO_LONG ) {
		printf("Check your input, maybe it was too long or you didn't give anything to me\n");
		return 1;
	}

	calcArea(buff,&areaOfCircle);

	return 0;
}
