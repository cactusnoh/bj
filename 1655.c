#include <stdlib.h>
#include <stdio.h>
//-99 1 2 4 5 5 7 10
void insert_min(int heap[], int *size, int value);
void insert_max(int heap[], int *size, int value);
void heapify_min(int heap[], int size, int index);
void heapify_max(int heap[], int size, int index);

int main(void)
{
	int max_heap[100001] = {0}, min_heap[100001] = {0};
	int max_size = 0, min_size = 0;
	int N, temp;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if(i % 2)
			insert_min(min_heap, &min_size, temp);
		else
			insert_max(max_heap, &max_size, temp);
		
		if(max_size > 0 && min_size > 0 && min_heap[0] < max_heap[0]) {
			temp = min_heap[0];
			min_heap[0] = max_heap[0];
			max_heap[0] = temp;
			heapify_min(min_heap, min_size, 0);
			heapify_max(max_heap, max_size, 0);
		}
		
		// printf("\nMin heap: ");
		// for(int i = 0; i < min_size; i++)
			// printf("%d ", min_heap[i]);
		// printf("\nMax heap: ");
		// for(int i = 0; i < max_size; i++)
			// printf("%d ", max_heap[i]);
		// printf("\n");
		
		printf("%d\n", max_heap[0]);
	}
}

void insert_max(int heap[], int *size, int value)
{	
	(*size)++;
	int index = *size - 1, temp;
	heap[*size - 1] = value;
	while(index > 0 && heap[(index - 1) / 2] < heap[index]) {
		temp = heap[index];
		heap[index] = heap[(index - 1) / 2];
		heap[(index - 1) / 2] = temp;
		index = (index - 1) / 2;
	}
}

void insert_min(int heap[], int *size, int value)
{
	(*size)++;
	int index = *size - 1, temp;
	heap[*size - 1] = value;
	while(index > 0 && heap[(index - 1) / 2] > heap[index]) {
		temp = heap[index];
		heap[index] = heap[(index - 1) / 2];
		heap[(index - 1) / 2] = temp;
		index = (index - 1) / 2;
	}
}

void heapify_min(int heap[], int size, int index)
{
	int left = 2 * index + 1, right = 2 * index + 2;
	int smallest, temp;
	
	if(left < size && heap[left] < heap[index])
		smallest = left;
	else
		smallest = index;
	if(right < size && heap[right] < heap[smallest])
		smallest = right;
	
	if(smallest != index) {
		temp = heap[index];
		heap[index] = heap[smallest];
		heap[smallest] = temp;
		heapify_min(heap, size, smallest);
	}
}

void heapify_max(int heap[], int size, int index)
{
	int left = 2 * index + 1, right = 2 * index + 2;
	int biggest, temp;
	
	if(left < size && heap[left] > heap[index])
		biggest = left;
	else
		biggest = index;
	if(right < size && heap[right] > heap[biggest])
		biggest = right;
	
	if(biggest != index) {
		temp = heap[index];
		heap[index] = heap[biggest];
		heap[biggest] = temp;
		heapify_max(heap, size, biggest);
	}
}