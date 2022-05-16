#include <stdio.h>

int main(void)
{
	int T, k, n
	
	scanf("%d", &T);
	for(int i = 0; i < T; i++) {
		scanf("%d%d%d", &H, &W, &N);
		printf("%d\n", N % H == 0 ? 100 * H + (N / H) : 100 * (N % H) + (N / H) + 1);
	}
	return 0;
}