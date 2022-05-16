#include <stdio.h>

int main(void)
{
	int A;
	scanf("%d", &A);

	if(A % 4 == 0 && A % 100 != 0)
		putchar('1');
	else if(A % 400 == 0)
		putchar('1');
	else
		putchar('0');
	
	return 0;
}