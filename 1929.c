#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int M, N, i, j, *prime;
	
	prime = malloc(sizeof(int) * 1000001);
	
	scanf("%d%d", &M, &N);
	
	prime[0] = 1; prime[1] = 1;
	for(i = 2; i <= N; i++)
		prime[i] = 0;
	
	for(i = 2; i <= N; i++) {
		if(prime[i] == 0) {
			for(j = 2; i * j <= N; j++)
				prime[i*j] = 1;
		}
	}
	
	for(i = M; i <= N; i++)
		if(prime[i] == 0)
			printf("%d\n", i);
		
	return 0;
}