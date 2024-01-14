#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>

//ssize_t write(int fd, const void *buf, size_t count);
ssize_t write(int fd,const void *buf,size_t count) {
    
    int (*new_write)(int fd,const void *buf,size_t count);
    int result;

    new_write = dlsym(RTLD_NEXT,"write");
    
    if(strcmp(buf,"Hello world!n") == 0) {
        result = new_write(1,"Goodbye, cruel world!n",22);    
    } else {
        result = new_write(fd,buf,count);
    }
    return result;
}
