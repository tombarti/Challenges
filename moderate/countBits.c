#include <stdio.h>

int countBits (int n)
{
	int count = 0;
	while (n > 0)
	{
		if (n & 1) 
			count++;
		n >>= 1;
	}
	return count;
}


int main (int argc, const char * argv[])
{
	FILE *file = fopen (argv[1], "r");
	int n = 0;
	fscanf (file, "%i", &n);
	while (!feof (file))
	{
		printf("%i\n", countBits(n));
		fscanf(file, "%i", &n);
	}
}
