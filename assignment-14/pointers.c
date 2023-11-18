#include <stdio.h>

int main(){

	int value = 7;
	int *ptr = &value;

	printf("the pointer to value is: %p\n",ptr);
	printf("the *pointer to value is: %d\n",*ptr);

	return 0;
}