#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REP(i, n) for(int i = 0; i < n; i++)

char* concat(char *s1, char *s2)
{
	char *result = malloc(strlen(s1)+strlen(s2));
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

char* remchar (char *s, int index)
{
	char *res = malloc(strlen(s));
	strcpy(res, s);
	for (index; res[index] != '\0'; index++)
	{
		res[index] = res[index+1];
	}
	return res;

}

void permutations (char *pre, char *str)
{
	int n = strlen (str) - 1;
	if (n == 0)	
		printf("%s ", pre);
	else 
	{
		int i = 0;
		for (i; i < n; i++)
		{
			char c[2] = "\0";
			c[0] = str[i];
			permutations (concat (pre, c), remchar (str, i));
		} 
	}
}

int factorial (int n) {
	if (n == 0)
		return 1;
	return (n * factorial(n -1));
}

int main (int argc, const char * argv[])
{
	FILE *file = fopen(argv[1], "r");
	char line[1024];
	while (fgets(line, 1024, file))
	{
		permutations("", line);
		printf("\n");
	}
	return 0;
}
