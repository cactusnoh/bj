#include <stdio.h>

int main(void)
{
	int N, sum, temp;
	scanf("%d", &N);
	
	for(int i = 1; i < N; i++) {
		temp = i;
		sum = i;
		while(temp) {
			sum += temp % 10;
			temp /= 10;
		}
		if(sum == N) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
		
	return 0;
}