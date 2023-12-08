#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ERR -1

static int getLineAndConvert(char *prompt,char *buff,size_t sz) {
    int ch,extra;

    if(sz < 2)
        return ERR;

    if(prompt != NULL) {
        printf("%s",prompt);
        fflush(stdout);
    }

    if(fgets(buff,sz,stdin) == NULL)
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
    //converting to int/double
    buff[len - 1] = '\0';
    int bet;
    char *endp;

    bet = strtoul(buff,&endp,10);
    errno = 0;
    if(buff == endp || errno)
        return ERR;

    return bet;
}

struct stats {
    int points;
    int games;
};

int main(int argc, char *argv[]) {
    struct stats player[5];
    int j,i,rc;
    float average;
    char buff[11];
    char temp[] ="2345";
    //14
    char prompt1[] = "Enter Player 1's point total: ";
    char prompt2[] = "Enter Player 1's game total: ";    

    for(i = 0;i < 5;i++) {
        rc = getLineAndConvert(prompt1,buff,sizeof(buff));
        if(rc != ERR) {
            player[i].points = rc;

            rc = getLineAndConvert(prompt2,buff,sizeof(buff));

            if(rc != ERR) {
                player[i].games = rc;    
            } else {
                puts("Invalid input,sorry! Change your input and try again!\n");
                i--;
            }

        } else {
            puts("Invalid input,sorry! Change your input and try again!\n");
            i--;
        }
        prompt1[13] = temp[i];
        prompt2[13] = temp[i];
    }
    
    for(j = 0;j < 5; j++){
        puts("\n");
        average = (float) (player[j].points) / (player[j].games);
        rc = j + 1;
        printf("Player #%d average: %2.f ppg",rc,average);
    }
}
