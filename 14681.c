#include <stdio.h>

int main(void)
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);

	if(A > 0 && B > 0)
		putchar('1');
	if(A > 0 && B < 0)
		putchar('4');
	if(A < 0 && B > 0)
		putchar('2');
	if(A < 0 && B < 0)
		putchar('3');
	
	return 0;
}