#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q);
void binary_search(int *start, int *end, int value, int *count);
int *upper_bound(int *start, int *end, int value);
int *lower_bound(int *start, int *end, int value);

int target[500000], array[500000];

int main(void)
{
	int N, M, temp, count;
	int *u, *l;
	
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &array[i]);
	qsort(array, N, sizeof(int), compare);
	
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
		scanf("%d", &target[i]);
	
	for(int i = 0; i < M; i++) {
		u = upper_bound(array, array + N - 1, target[i]);
		l = lower_bound(array, array + N - 1, target[i]);
		printf("%d ", *u == target[i] ? u - l + 1 : 0);
	}

	return 0;
}

int compare(const void *p, const void *q)
{
	return *(int *)p > *(int *)q ? 1 : -1;
}

int *upper_bound(int *start, int *end, int value)
{
	if(start > end)
		return end;
	
	int *middle = start + (end - start) / 2;
	
	if(*middle == value)
		return upper_bound(middle + 1, end, value);
	else if(*middle > value)
		return upper_bound(start, middle - 1, value);
	else
		return upper_bound(middle + 1, end, value);
}

int *lower_bound(int *start, int *end, int value)
{
	if(start > end)
		return start;
	
	int *middle = start + (end - start) / 2;
	
	if(*middle == value)
		return lower_bound(start, middle - 1, value);
	else if(*middle < value)
		return lower_bound(middle + 1, end, value);
	else
		return lower_bound(start, middle - 1, value);
}