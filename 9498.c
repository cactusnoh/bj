#include <stdio.h>

int main(void)
{
	int A;
	scanf("%d", &A);

	if(A >= 90)
		putchar('A');
	else if(A >= 80)
		putchar('B');
	else if(A >= 70)
		putchar('C');
	else if(A >= 60)
		putchar('D');
	else
		putchar('F');
	
	return 0;
}