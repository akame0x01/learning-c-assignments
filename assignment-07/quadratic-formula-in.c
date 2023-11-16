#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define ERR 1

static int getLine(char *prompt,char *buff,size_t sz) {
	int ch,extra;

	if(sz < 2) 
		return ERR;

	if(prompt != NULL) {
		printf("%s\n",prompt);
		fflush(stdout);
	}

	if( fgets(buff,sz,stdin) == NULL ) 
		return ERR;
	
	size_t len = strlen(buff);

	if(len < 2) {
		buff[len -1] = '\0';
		return ERR;
	}

	if(buff[len - 1] != '\n'){
		extra = 0;
		while((ch = getchar()) != '\n' && (ch != EOF))
			extra = 1;
		return (extra == 1 ) ? ERR : OK;
	}

	buff[len - 1] = '\0';
	return OK;
}

int convertToInt(char *string) {
	char *endp;
	int bet;

	bet = strtoul(string,&endp,10);

	errno = 0;
	if(endp ==  string || errno) 
		return 0;
	return bet;
}

int getValuesAndConvert(char *prompt) {
	char input[11];
	int rc;
	int numberConverted;

	if (rc = getLine(prompt,input,sizeof(input)) != 0) {
		puts("You enter a invalid value!");
		return 0;
	} 

	if( (numberConverted = convertToInt(input)) != 0) {
		return numberConverted;
	}

	puts("You enter a invalid input!");
	return 0;
}

int calc(double a,double b,double c) {
	// f(x) = a²x + bx + c = 0
	// y = b² - 4.a.c
	// x1 = (-b + sqrt(y)) / 2.a
	// x2 = (-b - sqrt(y)) / 2.a
 	double x1,x2,y;
	double test;

 	y = (b*b) - (4*a*c);

 	if( y < 0) {
 		printf("isn't possible to do this calc because delta is negative!\n");
 		printf("Y value is: %2.f\n",y);
 		return 0;
 	}

 	x1 = ((-b) + sqrt(y)) / (2*a);
 	x2 = ((-b) - sqrt(y)) / (2*a);

 	printf("Y value is: %2.f\n",y);
 	printf("The solution using the \'+\' is: %f\n",x1);
 	printf("The solution using the \'-\' is: %f\n",x2);

 	//the input isnot catching double numbers!
}


int main() {
	int a,b,c;

	if( (a = getValuesAndConvert("Enter the a value here> ")) == 0)
		return 0;

	if ( (b = getValuesAndConvert("Enter the b value here> ")) == 0)
		return 0;

	if ( (c = getValuesAndConvert("Enter the c value here>  ")) == 0)
		return 0;

	calc(a,b,c);

	return 0;
}
