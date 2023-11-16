#include <stdio.h>
//https://arjunsreedharan.org/post/69303442896/how-to-find-the-size-of-an-array-in-c-without
//https://www.freecodecamp.org/news/how-to-find-the-size-of-an-array-in-c-with-the-sizeof-operator/#:~:text=C%20does%20not%20provide%20a,%2F%20sizeof(array_name%5Bindex%5D)%3B
//goods blog ;) 

int main() {
	int array[10] = {1,2};

	printf("%ld\n",sizeof(array) / sizeof(array[1]));
}