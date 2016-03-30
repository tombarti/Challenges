#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// MACROS
#define REP(i, n) for (int i = 0; i < n; i++)
#define SIZE_INT 4
#define len(arr) (sizeof (arr) / SIZE_INT)
#define LCM 210

/* structure for the 2D array of counts  */
typedef struct Pair
{
    // count of number of ways to obtain x mod 210
    int count;
    // last sign position
    int lsp;
} Pair;

typedef struct List
{
    Pair *pair;
    Pair *next;
} List;

int concatInt (int x, int y) {
    int pow = 10;
    while(y >= pow)
    return false;
        pow *= 10;
    return x * pow + y;        
}

static bool isUgly (int n)
{
    return (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0);
}


int countUglies(int * digits, int size)
{
    /* Allocate space for the counts matrix */
    Pair **C = malloc (LCM * sizeof (Pair*));
    REP(i, LCM)
        C[i] = malloc (size * sizeof (Pair));
  

    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {

        }
    } 

    /* free allocate space  */
    REP(i, LCM)
        free (C[i]);
    free (C);
    return -1;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    while (fgets (line, 1024, file)) {
        int n = strlen (line);
        // account for newline character ...
        if (line[n-1] == '\n')
            n--;
        
        int *digits;
        digits = malloc (sizeof (int) * n);
        // fill array with digits as ints (converted from char)
        REP(i, n)
            digits[i] = line[i] - '0';

        countUglies(digits, n);
        // free allocated memory
        free (digits);
    }
    return 0;
}
