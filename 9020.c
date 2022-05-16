#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, j, cnt, *prime;
	
	prime = malloc(sizeof(int) * 10001);
	
	prime[0] = 1; prime[1] = 1;
	for(i = 2; i <= 10000; i++)
		prime[i] = 0;
	for(i = 2; i <= 10000; i++) {
		if(prime[i] == 0) {
			for(j = 2 * i; j <= 10000; j += i)
				prime[j] = 1;
		}
	}
	
	while(scanf("%d", &n) != EOF) {
		if(n % 2 != 0 || n < 4 || n > 10000)
			continue;
		
		if(prime[n/2] == 0) {
			printf("%d %d\n", n/2, n/2);
			continue;
		}
		for(i = n/2; i > 0; i--) {
			if(prime[i] == 0 && prime[n - i] == 0) {
				printf("%d %d\n", i, n-i);
				break;
			}
		}
	}
		
	return 0;
}