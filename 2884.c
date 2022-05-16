#include <stdio.h>

int main(void)
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);

	if(B >= 45)
		printf("%d %d", A, B - 45);
	else if(A >= 1)
		printf("%d %d", A - 1, B + 15);
	else
		printf("%d %d", 23, B + 15);
	
	return 0;
}