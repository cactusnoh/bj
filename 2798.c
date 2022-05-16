#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, M, max = 0, *p;
	scanf("%d%d", &N, &M);
	
	p = malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++)
		scanf("%d", &p[i]);
	
	for(int i = 0; i < N - 2; i++) {
		for(int j = i + 1; j < N -1; j++) {
			for(int k = j + 1; k < N; k++) {
				if(p[i] + p[j] + p[k] <= M && p[i] + p[j] + p[k] > max)
					max = p[i] + p[j] + p[k];
			}
		}
	}
	printf("%d", max);
	
	return 0;
}