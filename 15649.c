#include <stdio.h>
#include <stdlib.h>

void all_choices(int *a, int *b, int n);

int main(void)
{
	int N, M, permutation = 1; 
	int **ans;
	scanf("%d%d", &N, &M);

	for(int i = N; i > N - M; i--)
		permutation *= i;
	
	ans = malloc(sizeof(int *) * permutation);
	for(int i = 0; i < permutation; i++)
		ans[i] = malloc(sizeof(int) * M);
	
	
	
	return 0;
}

void all_choices(int *a, int *b, int n)
{
	
}
/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2

1 2 3 4 5 6 7 8

1 2 3 4
1 2 3 5
1 2 3 6 
1 2 3 7
1 2 3 8
....


*/