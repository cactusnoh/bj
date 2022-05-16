#include <stdio.h>
int main(void)
{
	int i1, i2;
	scanf("%d %d", &i1, &i2);
	printf("%.9lf", (double)i1/i2);
	return 0;
}