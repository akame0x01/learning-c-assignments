#include <stdio.h>

void hello(void)
{
	char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};
	char arr[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33, '\0'};
	
	puts("Using printf:\n");	

	printf("%s\n", array);
	printf("%s\n", arr);

	puts("\n=============================================\nUsing puts:\n");

	puts(array);
	puts(arr);


}

int main(void) 
{
	hello();
}