#include <stdio.h>
#include <stdlib.h>

int main() {
	char *ptr;
	char arr[10];
	size_t size;

	size = 10 * sizeof(char);

	if((ptr = malloc(size)) == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}

	printf("Your memory was successfully allocated!\n");
	free(ptr);
	return 0;

}