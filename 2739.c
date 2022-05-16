#include <stdio.h>

int main(void)
{
	int A;
	scanf("%d", &A);

	for(int i = 0; i < 9; i++)
		printf("%d * %d = %d\n", A, i+1, A * (i+1));
	return 0;
}