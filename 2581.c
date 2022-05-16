#include <stdio.h>

int main(void)
{
	int M, N, i, j, sum = 0, min = -1, a[10000];
	
	scanf("%d%d", &M, &N);
	
	for(i = 1; i < N; i++)
		a[i] = 1;
	for(i = 1; i < N; i++) {
		if(a[i] != 0) {
			for(j = i+1; j < N; j++) {
				if((j+1) % (i+1) == 0)
					a[j] = 0;
			}
		}
	}
	
	for(i = M-1; i < N; i++)
		if(a[i] == 1) {
			min = i+1;
			break;
		}
	
	for(i = M-1; i < N; i++)
		if(a[i] != 0)
			sum += i+1;
	
	if(min != -1)
		printf("%d\n%d", sum, min);
	else
		printf("-1");
	
	return 0;
}