#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

void merge_sort(int *a, int p, int q);
void merge(int *a, int p, int middle, int q); 
void insertion_sort(int *a, int n);

int main(void)
{
	int N, *a;
	scanf("%d", &N);
	
	a = malloc(sizeof(int) * N);
	
	for(int *p = a; p < a + N; p++)
		scanf("%d", p);
	
	merge_sort(a, 0, N - 1);
	
	for(int *p = a; p < a + N; p++)
		printf("%d\n", *p);
	
	free(a);
	
	return 0;
}

void merge_sort(int *a, int p, int q)
{
	if(p >= q)
		return;
	
	if(q - p <= 42) {
		insertion_sort(a + p, q-p+1);
		return;
	}
	
	int middle = (p + q) / 2;
	
	merge_sort(a, p, middle);
	merge_sort(a, middle + 1, q);
	merge(a, p, middle, q);
}

void merge(int *a, int p, int middle, int q)
{
	int i = 0, j = 0, k;
	int *b, *c;
	
	b = malloc(sizeof(int) * (middle - p + 2));
	c = malloc(sizeof(int) * (q - middle + 1));
	
	for(k = 0; k < middle - p + 1; k++)
		b[k] = a[k + p];
	b[middle - p + 1] = MAX;
	for(k = 0; k < q - middle; k++)
		c[k] = a[k + middle + 1];
	c[q - middle] = MAX;

	k = p;
	while(k <= q) {
			if(b[i] < c[j])
				a[k++] = b[i++];
			else
				a[k++] = c[j++];
	}
	
	free(b);
	free(c);
}

void insertion_sort(int *a, int n)
{
	int temp;
	
	for(int i = 1; i < n; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(a[j + 1] < a[j]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}