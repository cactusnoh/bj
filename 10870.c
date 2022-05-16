#include <stdio.h>
int fibonacci(int n);
int main(void)
{
	int N;
	scanf("%d", &N);
	printf("%d", fibonacci(N));
	
	return 0;
}

int fibonacci(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	
	return fibonacci(n - 1) + fibonacci(n - 2);
}