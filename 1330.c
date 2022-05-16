#include <stdio.h>

int main(void)
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);

	if(A > B)
		putchar('>');
	else if(A < B)
		putchar('<');
	else {
		putchar('=');
		putchar('=');
	}
	
	return 0;
}