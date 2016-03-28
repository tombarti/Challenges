#include <stdio.h>
#include <stdlib.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define K 2 

typedef struct matrix {
	int arr[K][K];
} Matrix;

Matrix* mult(Matrix *A, Matrix *B) {
	Matrix *C = malloc(sizeof(Matrix));
	C->arr[0][0] = C->arr[0][1] = C->arr[1][0] = C->arr[1][1] = 0;
	REP(i, K) REP(j, K) REP(k, K)
		C->arr[i][j] += A->arr[i][k] * B->arr[k][j];
	return C;
}

Matrix* power(Matrix *A, int p) {
	if (p == 1)
		return A;
	if (p % 2)
		return mult(A, power(A, p-1));
	Matrix *X = power(A, p/2);
	return mult(X, X);
}

int fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1 || n == 2) 
		return 1;
	n--;
	int F1[K] = {1, 1};
	Matrix T = {{{0, 1}, {1, 1}}};
	Matrix *S = power(&T, n-1);
	int res = 0;
	REP(i, K)
		res += S->arr[1][i] * F1[i];
	return res;
}

int main(int argc, const char * argv[]) {
	FILE *file = fopen(argv[1], "r");
	int n = 0;
	fscanf(file, "%d", &n);
	while (!feof(file)) {
		printf("%i\n", fibonacci(n));
		fscanf(file, "%d", &n);
	}
	return 0;
}
