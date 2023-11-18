#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ERR -1

static int getLineAndConvert(char *prompt,char *buff,size_t sz) {
	int ch,extra;

	if (sz < 2)
		return ERR;

	if (prompt != NULL) {
		printf("%s\n",prompt);
		fflush(stdout);
	}

	if(fgets(buff,sz,stdin) == NULL)
		return ERR;

	size_t len = strlen(buff);

	if(len < 2) {
		buff[len - 1] = '\0';
		return ERR;
	}

	if(buff[len - 1 ] != '\n') {
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
	if(buff == endp || errno)
		return ERR;

	return bet;
}

double calculeAvarege(int arr[][5],int len,int *bestPlayer) {
	int sums[5] = {0};
	double averages[5] = {0};
	double currentAverage;
	int i,j,x,y;


	for(j = 0; j < 5;j++){
		for(i = 0;i < len;i++) {
			sums[j] += arr[i][j];
		}
	}
	
    for (x = 0; x < 5; x++) {
    	currentAverage = sums[x] / len;
    	averages[x] = currentAverage;
    }

    double max = averages[0];

    for(y = 0; y < 5;y++) {
    	if(averages[y] > max)
    		max = averages[y];
    		*bestPlayer = y;
    }

	return max;
}

/*Create a program that prompts the user to input scoring totals for 5 players during 4 basketball games. 
The program will track which player had the highest scoring average over the 4 games and print the result to the terminal.
Hint: Use a two-dimensional array and nested for loops. 
The outer-most for loop will iterate on a per game basis gathering scores for the inner-most for loop interating through players
e this same model to create arrays to store total scores and to calculate averages.
*/

int main() {
	char prompt1[] = "How much matchs do you'll use to calculate the average?> ";
	char prompt2[] = "Enter scoring total for Player #1";
	char temp[] = "2345";
	char buff[11];
	double bestAverage;
	int bestPlayer;
	int *bestPlayerPointer = &bestPlayer;
	int len,rc,j,i;

	rc = getLineAndConvert(prompt1,buff,sizeof(buff));
	
	if(rc < 0 || rc > 5) {
		puts("Invalid input, sorry! Change the input and try again!\nThe max is five matchs!");
		return 0;
	}

	len = rc;

	int arr[len][5];

	for(i = 0; i < len ;i++) {
		j = 0;
		printf("#Game %d\n",(i+1));
		prompt2[32] = '1';	
		for(j = 0;j < 5;j++) {
			rc = getLineAndConvert(prompt2,buff,sizeof(buff));
			if(rc >= 0) {
				prompt2[32] = temp[j];
				arr[i][j] = rc;
			} else {
				puts("Invalid input, sorry! Change the input and try again!\n");
				j--;
			}		
		}
	}

	bestAverage = calculeAvarege(arr,len,bestPlayerPointer);
	printf("Player #%d had the highest scoring average at %2.f points per game.\n",bestPlayer,bestAverage);

	return 0;
}