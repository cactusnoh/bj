#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) > 0 ? (x) : -(x))

int min(int heap[], int n);
int extract_min(int **heap, int *n);
void insert(int **heap, int *n, int x);
void min_heapify(int heap[], int n, int a);
void build_min_heap(int heap[], int n);
void heap_sort(int heap[], int n);

int main(void)
{
	int N, size = 0, temp;
	int *heap;
	
	heap = malloc(sizeof(int) * 0);
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if(temp == 0)
			printf("%d\n", extract_min(&heap, &size));
		else
			insert(&heap, &size, temp);
	}
	
	return 0;
}

int min(int heap[], int n)
{
	return n == 0 ? 0 : heap[0];
}

int extract_min(int **heap, int *n)
{
	if(*n == 0)
		return 0;
	
	int min = (*heap)[0];
	(*heap)[0] = (*heap)[*n-1];
	
	(*n)--;
	*heap = realloc(*heap, sizeof(int) * (*n));
	min_heapify(*heap, *n, 0);
	
	return min;
}

void insert(int **heap, int *n, int x)
{
	int p, temp;
	(*n)++;
	*heap = realloc(*heap, sizeof(int) * (*n));
	(*heap)[*n-1] = x;
	
	p = *n - 1;
	while(p >= 0) {
		if(ABS((*heap)[p]) < ABS((*heap)[(p - 1) / 2])) {
			temp = (*heap)[p];
			(*heap)[p] = (*heap)[(p - 1) / 2];
			(*heap)[(p - 1) / 2] = temp;
			p = (p - 1) / 2;
		} else if(ABS((*heap)[p]) == ABS((*heap)[(p - 1) / 2]) && (*heap)[p] < (*heap)[(p - 1) / 2]) {
			temp = (*heap)[p];
			(*heap)[p] = (*heap)[(p - 1) / 2];
			(*heap)[(p - 1) / 2] = temp;
			p = (p - 1) / 2;
		} else
			break;
	}
}

void min_heapify(int heap[], int n, int a)
{
	int l = 2 * a + 1, r = 2 * (a + 1), smallest = a;
	int temp;
	
	if(l < n && ABS(heap[l]) < ABS(heap[a]))
		smallest = l;
	else if(l < n && ABS(heap[l]) == ABS(heap[a]) && heap[l] < heap[a])
		smallest = l;
	if(r < n && ABS(heap[r]) < ABS(heap[smallest]))
		smallest = r;
	else if(r < n && ABS(heap[r]) == ABS(heap[smallest]) && heap[r] < heap[smallest])
		smallest = r;
	
	if(smallest != a) {
		temp = heap[smallest];
		heap[smallest] = heap[a];
		heap[a] = temp;
	} else
		return;
	
	min_heapify(heap, n, smallest);
}

void build_min_heap(int heap[], int n)
{
	for(int i = n/2 + 1; i >= 0; i--)
		min_heapify(heap, n, i);
}

void heap_sort(int heap[], int n)
{
	if(n <= 1)
		return;
	
	int temp = heap[0];
	heap[0] = heap[n-1];
	heap[n-1] = temp;
	
	min_heapify(heap, n - 1, 0);
	heap_sort(heap, n - 1);
}