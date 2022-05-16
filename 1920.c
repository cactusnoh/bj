#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *p, const void *q);
bool binary_search(int *start, int *end, int value);

int main(void)
{
	int N, M, temp;
	int *target, *array;
	
	scanf("%d", &N);
	array = malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		array[i] = temp;
	}
	qsort(array, N, sizeof(int), compare);

	scanf("%d", &M);
	target = malloc(sizeof(int) * M);
	for(int i = 0; i < M; i++) {
		scanf("%d", &temp);
		target[i] = temp;
	}
	
	for(int i = 0; i < M; i++)
		printf("%d\n", binary_search(array, array + N - 1, target[i]) ? 1 : 0);

	return 0;
}

int compare(const void *p, const void *q)
{
	return *(int *)p > *(int *)q ? 1 : -1;
}

bool binary_search(int *start, int *end, int value)
{
	if(start > end)
		return false;
	
	int *middle = start + (end - start) / 2;
	
	if(*middle == value)
		return true;
	else if(*middle > value)
		return binary_search(start, middle - 1, value);
	else
		return binary_search(middle + 1, end, value);
}