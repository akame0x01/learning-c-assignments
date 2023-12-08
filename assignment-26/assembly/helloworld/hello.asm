; Compiling the program
; For compiling this hello world program you can use nasm and ld
;   $ nasm -f elf32 -o hello.o hello.asm
;   $ ld -m elf_i386 -o hello hello.o
;   $ ./hello

section .text
        global _start
_start:
       mov edx, len ; move the length
       mov ecx, msg ; move msg
       mov ebx, 1 ; stdout fd
       mov eax, 4 ; sys_write id
       int 0x80 ; call kernel
       mov eax, 1 ; sys_exit id
       int 0x80 ; call kernel again

section .data
        msg db "Hello world!", 0xa ;data byte and a newline char 0xa
        len equ $ - msg  ;get the length of msg
