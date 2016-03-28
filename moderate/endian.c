#include <stdio.h>
int main()
{
	int x = 1;
	char *y = (char*)&x;
	if (*y+48)
		printf("LittleEndian");
	else
		printf("BigEndian");
}
