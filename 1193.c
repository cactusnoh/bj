#include <stdio.h>

int main(void)
{
	int X, n = 1, diff, denom, num;
	scanf("%d", &X);
	
	while(n*(n+1) / 2 < X)
		n++;
	
	diff = n*(n+1) / 2 - X;
	if(n % 2 == 0)
		printf("%d/%d", n - diff, 1 + diff);
	else
		printf("%d/%d", 1 + diff, n - diff);
	
	return 0;
}