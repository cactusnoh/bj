#include <stdio.h>

int main(void)
{
	int N, i;
	
	scanf("%d", &N);
	
	if(N == 1)
		return 0;
	
	while(N != 1) {
		for(i = 2; i*i <= N; i++) {
			if(N % i == 0) {
				printf("%d\n", i);
				N /= i;
				break;
			}
		}
		if(i*i > N) {
			printf("%d\n", N);
			N /= N;
		}
	}
	
	return 0;
}