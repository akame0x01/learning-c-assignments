#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define ERR 0
#define OK 1
#define INITIAL_CAPACITY 3

static int getLine(char *prompt,char *buff,size_t sz) {
	int ch,extra;

	if(sz < 2) 
		return ERR;

	if(prompt != NULL) {
		printf("%s",prompt);
		fflush(stdout);
	}

	if ( fgets(buff,sz,stdin) == NULL )
		return ERR;

	size_t len = strlen(buff);

	if(len < 2) {
		buff[len - 1] = '\0';
		return ERR;
	}

	if(buff[len - 1] != '\n') {
		extra = 0;
		while((ch = getchar() != '\n') && (ch != EOF))
			extra = 1;
		if(extra == 1) 
			return ERR;
	}

	//removing '\n'
	buff[len - 1] = '\0';
	return OK;
}

int convertLine(char *buff) {
	char *endp;
	int bet;

	bet = strtoul(buff,&endp,10);
	errno = 0;
	if(endp == buff || errno) 
		return ERR;

	return bet;
}

int check() { 
    char buff[3];
    char prompt[] = "Would you like to continue? Y/N "; 
    int rc;

    if ((rc = getLine(prompt, buff, sizeof(buff))) == 1) {

        if ((strncmp(buff, "Y", 1) == 0) || (strncmp(buff, "y", 1) == 0)) {
            return 1;
        }

        if ((strncmp(buff, "N", 1) == 0) || (strncmp(buff, "n", 1) == 0)) {
            return 0;
        }
    }

    puts("I only accept y or n characters!\n");    
    return check();
}

void calculeAverage(int arr[]) {

	int sum = 0;
	float average;
	int i = 0;

	while(arr[i] != 0 && i <= 9) {
		printf("the index %d is %d\n",i,arr[i]);
		printf("sum is equal to: %d\n",sum);
		sum += arr[i];
		i++;
	}

	average = (float) sum / i;

	printf("The average of all scores that you give me is: %f.\nAnd the sum of all is: %d\n",average,sum);

}

int main() {
	double *scores = malloc(INITIAL_CAPACITY * sizeof(double));
	if(!scores)
	{
		puts("Failed to allocate memory.\n");
		return 1;
	}

	int capacity = INITIAL_CAPACITY;
	int numScores,rc;
	char answer[] = "y";
	char prompt[] = "Would you like to continue? y/n "; 

	for(numScores = 0;strncmp(answer,"y",1) == 0;++numScores) {

		if(numScores == capacity) {
			capacity *= 2;
			scores = realloc(scores,capacity * sizeof(double));
			if(!scores) {
				puts("Failed to allocate memory.\n");
				return 1;
			}
		}


	}


}
