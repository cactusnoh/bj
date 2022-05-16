#include <stdio.h>

int main(void)
{
	int A, B, C;
	
	scanf("%d%d%d", &A, &B, &C);
	
	printf("%d", B < C ? A / (C-B) + 1 : -1);
	
	return 0;
}