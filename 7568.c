#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, cnt, **p;
	scanf("%d", &N);
	
	p = malloc(sizeof(int *) * N);
	for(int i = 0; i < N; i++) {
		p[i] = malloc(sizeof(int) * 2);
		scanf("%d%d", &p[i][0], &p[i][1]);
	}
	
	for(int i = 0; i < N; i++) {
		cnt = 0;
		for(int j = 0; j < N; j++) {
			if(i == j)
				continue;
			if(p[i][0] < p[j][0] && p[i][1] < p[j][1])
				cnt++;
		}
		printf("%d\n", cnt + 1);
	}
	
	return 0;
}