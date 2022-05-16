#include <stdio.h>

int main(void)
{
	int N, N_orig, cnt = 0;
	scanf("%d", &N);
	N_orig = N;
	
	do {
		if(N < 10)
			N = N*10 + N;
		else
			N = (N % 10 * 10) + (N % 10 + N / 10) % 10;
		cnt++;
	} while(N != N_orig);
	
	printf("%d", cnt);
	
	return 0;
}