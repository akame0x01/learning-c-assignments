#include <stdio.h>


struct Testing
{
	int integer;
	char ch;
	float point;
};

int main()
{
	struct Testing mystruct;
	mystruct.integer = 50;
	mystruct.ch = 'W';
	mystruct.point = 3.149999232132131;
	

	printf("This is the int: %d, this is the char: %c, this is the float: %f\n",mystruct.integer,mystruct.ch,mystruct.point);

	return 0;
}