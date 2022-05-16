#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cnt[20000001];

int main(void)
{
	int N, M, temp, count;
	int *target, *array;
	
	scanf("%d", &N);
	array = malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		array[i] = temp;
		cnt[10000000 + temp]++;
	}

	scanf("%d", &M);
	target = malloc(sizeof(int) * M);
	for(int i = 0; i < M; i++) {
		scanf("%d", &temp);
		target[i] = temp;
	}
	
	for(int i = 0; i < M; i++) {
		count = 0;
		printf("%d ", cnt[10000000 + target[i]]);
	}

	return 0;
}