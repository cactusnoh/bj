#include <stdio.h>

#define PI 3.141592653589793238

int main(void)
{
	double R;
	scanf("%lf", &R);
	
	printf("%lf\n%lf", (double)PI * R * R, (double)R*R*2);
	
	return 0;
}