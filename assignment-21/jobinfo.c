#include <stdio.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define ERR -1 

static int getLine(char *prompt,char *buff,size_t sz) {
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

    buff[len - 1] = '\0';
}

struct data {
	char first[20];
	char last[20];
	char employee_id[8];
	char last_4_SSN[8];
	char title[20];
};

struct employees {
    struct data employee1;
    struct data employee2;
} engineering;

// i really hated this code at all

int main(void) 
{
    int rc,i;
    char buff[18];
    struct data *employee = &engineering.employee1;
    char questions[5][60] = { 
        "Enter the employee's first name: ",
        "Enter the employee's last name: ",
        "Enter the employee's ID number: ",
        "Enter the last four digits of the employee's SSN: ",
        "Enter the employee's job title: "
    };
            

    for(i = 0;i <= 1;i++) {
        if(i == 1) 
            employee = &engineering.employee2;

        rc = getLine(questions[0],buff,sizeof(buff));
        if(rc == ERR) {
            puts("Invalid input");
            return 0;
        }

        strcpy(employee->first, buff);
         
        rc = getLine(questions[1],buff,sizeof(buff));
        if(rc == ERR) {
            puts("Invalid input");
            return 0;
        }

        strcpy(employee->last, buff);

        rc = getLine(questions[2],buff,8);
        if(rc == ERR) {
            puts("Invalid input");
            return 0;
        }
        strcpy(employee->employee_id, buff);


        rc = getLine(questions[3],buff,8);
        if(rc == ERR) {
            puts("Invalid input");
            return 0;
        }
        strcpy(employee->last_4_SSN, buff);

        rc = getLine(questions[4],buff,sizeof(buff));
        if(rc == ERR) {
            puts("Invalid input");
            return 0;
        }
        strcpy(employee->title, buff);
 
      }   
    
    for(i = 0; i <=1; i++) {
        if(i == 1)
            employee = &engineering.employee2;
    
        printf("\nEmployee Data:\n");
        printf("First Name: %s\n", employee->first);
        printf("Last Name: %s\n", employee->last);
        printf("Employee ID: %s\n", employee->employee_id);
        printf("Last 4 SSN: %s\n", employee->last_4_SSN);
        printf("Job Title: %s engineer", employee->title);
    }

    return 0;
}
