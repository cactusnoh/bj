#include <stdio.h>
#include <stdlib.h>

int max(int heap[], int n);
int extract_max(int **heap, int *n);
void insert(int **heap, int *n, int x);
void max_heapify(int heap[], int n, int a);
void build_max_heap(int heap[], int n);
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
			printf("%d\n", extract_max(&heap, &size));
		else
			insert(&heap, &size, temp);
	}
	
	return 0;
}

int max(int heap[], int n)
{
	return n == 0 ? 0 : heap[0];
}

int extract_max(int **heap, int *n)
{
	if(*n == 0)
		return 0;
	
	int max = (*heap)[0];
	(*heap)[0] = (*heap)[*n-1];
	
	(*n)--;
	*heap = realloc(*heap, sizeof(int) * (*n));
	max_heapify(*heap, *n, 0);
	
	return max;
}

void insert(int **heap, int *n, int x)
{
	int p, temp;
	(*n)++;
	*heap = realloc(*heap, sizeof(int) * (*n));
	(*heap)[*n-1] = x;
	
	p = *n - 1;
	while(p >= 0) {
		if((*heap)[p] >(*heap)[(p - 1) / 2]) {
			temp = (*heap)[p];
			(*heap)[p] = (*heap)[(p - 1) / 2];
			(*heap)[(p - 1) / 2] = temp;
			p = (p - 1) / 2;
		} else
			break;
	}
	
}

void max_heapify(int heap[], int n, int a)
{
	int l = 2 * a + 1, r = 2 * (a + 1), largest = a;
	int temp;
	
	if(l < n && heap[l] > heap[a])
		largest = l;
	if(r < n && heap[r] > heap[largest])
		largest = r;
	
	if(largest != a) {
		temp = heap[largest];
		heap[largest] = heap[a];
		heap[a] = temp;
	} else
		return;
	
	max_heapify(heap, n, largest);
}

void build_max_heap(int heap[], int n)
{
	for(int i = n/2 + 1; i >= 0; i--)
		max_heapify(heap, n, i);
}

void heap_sort(int heap[], int n)
{
	if(n <= 1)
		return;
	
	int temp = heap[0];
	heap[0] = heap[n-1];
	heap[n-1] = temp;
	
	max_heapify(heap, n - 1, 0);
	heap_sort(heap, n - 1);
}