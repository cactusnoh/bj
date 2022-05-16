#include <stdio.h>
int factorial(int n);
int main(void)
{
	int N;
	scanf("%d", &N);
	printf("%d", factorial(N));
	
	return 0;
}

int factorial(int n)
{
	if(n == 0)
		return 1;
	
	return n * factorial(n - 1);
}