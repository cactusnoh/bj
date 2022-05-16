#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, j, cnt, *prime;
	
	prime = malloc(sizeof(int) * 123456 * 2 + 1);
	
	prime[0] = 1; prime[1] = 1;
	for(i = 2; i <= 123456 * 2; i++)
		prime[i] = 0;
	for(i = 2; i <= 123456 * 2; i++) {
		if(prime[i] == 0) {
			for(j = 2 * i; j <= 123456 * 2; j += i)
				prime[j] = 1;
		}
	}
	
	while(1) {
		scanf("%d", &n);
		if(n == 0)
			break;
		cnt = 0;
		for(i = n + 1; i <= 2 * n; i++)
			if(i <= 123456 * 2 && prime[i] == 0)
				cnt++;
		printf("%d\n", cnt);
	}
		
	return 0;
}