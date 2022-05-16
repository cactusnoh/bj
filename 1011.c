#include <stdio.h>
#include <math.h>

int main(void)
{
	int x, y, T, n, left;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++) {
		scanf("%d%d", &x, &y);
		n = sqrt(y-x);
		left = (y - x - n*n) % n == 0 ? 0 : 1;
		printf("%d\n", 2*n - 1 + (y - x - n*n) / n +left);
	}
	
}