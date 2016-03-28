#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

typedef enum { false, true } bool;

typedef struct Search
{
	char *str;
	char *txt;
} Search;

// separate the two comma separated strings
void separate (char* str, char sep, Search * s)
{
	int i = 0;
    int n = strlen (str);
    // find index of the comma ','
	while (str[i] != sep)
		i++;
    s->txt = malloc (sizeof (char) * (i + 1));
    s->str = malloc (sizeof (char) * (n - i + 1)); 
	strncpy(s->txt, str, i * sizeof(char));
    s->txt[i] = '\0';
	strcpy(s->str, &str[i+1]);
    int m = strlen (s->str);
    if (s->str[m-1] == '\n')
        s->str[m-1] = '\0';
}

void remchar (char *s, int index)
{
    for (index; s[index] != '\0'; index++)
        s[index] = s[index+1];
}

bool searchStr (Search* s)
{
    // case there is no 
	int n = strlen (s->txt) - 1;
	int m = strlen (s->str) - 1;
    // case str = "*"
    if (s->str[0] == '*' && m == 1)
        return true;
    // case str starts with '*'
    if (s->str[0] == '*') 
    {
        remchar(s->str, 0);
        m--;
    }
    // case str ends with '*'
    if (s->str[m-1] == '*' && s->str[m-2] != '\\')
    {
        remchar(s->str, m-1);
        m--;
    }
}

// Replaces all occurrences of '*' with '.*'
char* preprocStr (char* str, char* temp)
{
    int i = 0, count = 0, offset = 0;
    int m = strlen (str);
    // count occurrences of '*' to allocate mem efficiently
    while (str[i] != '\0')
    {
        if (str[i] == '*')
            count++;
        i++;
    }
    // allocate needed space
    temp = malloc ((m + i) * sizeof (char));
    i = 0;
    // replace '*' with '.*'
    while (i < m)
    {
        if (str[i] == '*' && str[i-1] != '\\')
        {
            temp[i+offset] = '.';
            offset++;
            temp[i+offset] = '*';
        } else
        {
            temp[i+offset] = str[i];
        }
        i++;
    }
    // NULL TERMINATE THIS SHIT!!
    temp[i + offset] = '\0';
    return temp;
}

bool searchWithRegex (Search* s)
{
    int err;
    char *temp;
    temp = preprocStr(s->str, temp);
    regex_t regex;
    err = regcomp(&regex, temp, REG_EXTENDED);
    if (err)
        printf("Error compiling regex\n");
    err = regexec(&regex, s->txt, 0, NULL, 0);
    regfree(&regex);
    free(temp);
    if (!err)
        return true;
    return false;
}

int main (int argc, char * argv[])
{
	FILE *file = fopen (argv[1], "r");
	char line[1024];
	while (fgets (line, 1024, file))
	{
		Search *s = (Search*) malloc (sizeof (Search)); 
		separate (line, ',', s);
		if (searchWithRegex (s))
			printf("true\n");
		else
			printf("false\n");
        free(s);
	}
	return 0;
}
