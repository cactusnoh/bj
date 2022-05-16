#include <stdio.h>
#include <stdlib.h>

void max_heapify(int heap[], int n, int a);
void build_max_heap(int heap[], int n);
void heap_sort(int heap[], int n);

int main(void)
{
	int N, *a;
	scanf("%d", &N);
	
	a = malloc(sizeof(int) * N);
	
	for(int *p = a; p < a + N; p++)
		scanf("%d", p);
	
	build_max_heap(a, N);
	heap_sort(a, N);
	
	for(int *p = a; p < a + N; p++)
		printf("%d\n", *p);
	
	free(a);
	
	return 0;
}

void max_heapify(int heap[], int n, int a)
{
	int temp;
	while(a < n) {
		if(2*a+1 < n && heap[2*a+1] > heap[a] && heap[2*a+1] > heap[2*a]) {
			temp = heap[a];
			heap[a] = heap[2*a+1];
			heap[2*a+1] = temp;
			a = 2*a+1;
		} else if(2*a < n && heap[2 * a] > heap[a] && heap[2*a] > heap[2*a + 1]) {
			temp = heap[a];
			heap[a] = heap[2*a];
			heap[2*a] = temp;
			a = 2*a;
		} else
			return;
	}
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