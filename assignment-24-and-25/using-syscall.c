#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void){

    int filedescriptor,writerc;
    
    //O_WRONLY -> WRITE-ONLY
    //O_CREAT -> CREATE FILE IF THE DOES NOT EXIST
    //S_IRWXU -> '(S_IRUSR,S_IWUSR,S_IXUSR)' read,write and execution for the owner and root
    filedescriptor = open("myfile.txt",O_WRONLY | O_CREAT,S_IRWXU);

    if(filedescriptor < 0) {
        printf("the open operation falied...\n");
        return -1;
    }
    
    printf("The open operation succeeded!\n");
    

    writerc = write(filedescriptor,"Writing data in file!",21);

    if(writerc != 21) {
        printf("The write operation failed...\n");
        return -1;
    }

    printf("The write operation succeeded!\n");
    if( (close(filedescriptor)) != 0)
        return -1;
    
    printf("All operations succeeded!\n");
    return 0;

}
