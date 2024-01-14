#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
 * $ gcc writing-something -o writing
 * $ gcc compile it with: gcc -ldl hook.c -fPIC -shared -D_GNU_SOURCE -o hooked_write.so
 * $ export LD_PRELOAD=/path/to/hooked_write.so
 * $ ./writing
 *
 * pay attention at the type of the data of the function that you are hooking
*/

int main() {

    int fd,rs;

    rs = write(1,"Hello world!n",14);

    if(rs < 0) {
        printf("Failed....!\n");
        return -1;
    }

}
