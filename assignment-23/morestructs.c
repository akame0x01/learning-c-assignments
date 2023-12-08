#include <stdio.h>

struct mine_struct {
    int integer;
};

int main() {
    struct mine_struct *ptr;
    struct mine_struct test;

    ptr = &test;

    //passing value directly by instance
    test.integer = 1;
    printf("instance.integer: %d\n",test.integer); 

    //passing value by the pointer that points the instance
    // *ptr grab the value= test instance
    (*ptr).integer =2;
    printf("*ptr.integer: %d\n",test.integer);
    
    ptr->integer =3;
    printf("ptr -> integer: %d\n", test.integer);

    return 0;
}
