#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

#define ERR 0

static int getLine(char *prompt,char *buff,size_t sz) {
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

	if (len < 2) {
		return ERR;
	}

	if(buff[len - 1] != '\n') {
		extra = 0;
		while((ch = getchar() != '\n') && (ch != EOF))
			extra = 1;
		if(extra == 1)
			return ERR;
	}

	buff[len - 1] = '\0';
	int bet;
	char *endp;

	bet = strtoul(buff,&endp,10);
	errno = 0;
	if(endp == buff || errno) 
		return ERR;

	if(bet <= 0) {
		puts("is not possible to calcule this because the number is zero or negative!");
		return ERR;
	}
	return bet;
}

int main() {
	
	
	char count[11];
	char prompt[] = "How many time would you like to flip the coin? ";
	int rc;

	if((rc = getLine(prompt,count,sizeof(count))) == 0) {
		puts("An error occorred, sorry!");
		return 1;
	}

	unsigned int seed;

	int i,random;
	int heads = 0;
	int tails = 0;
	seed = time(0); //amount in seconds of the current time, if you put it in for, it will be the same each time.
	srand(seed); //set the current time of the set that will be used to caught a pseudo-aleatory number using rand
	for(i = 0; i < rc; i++) {
		random = (rand() % 2) + 1; //generate a number aleatory and take the remainder 
		//of the divison for 2, what can be 0 or 1, and sum one to put it into the range of 1 or 2;

		if(random == 1) {
			heads++;
		}

		if(random == 2) {
			tails++;
		}
	}

	printf("After flipping the coin %d times, the results were:\n",i);
	printf("%d heads\n%d tails\n",heads,tails);
}