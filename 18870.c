#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *a, int p, int q);
void merge(int *a, int p, int middle, int q);
void insertion_sort(int *a, int n);
int binary_search(int *a, int p, int q, int target);

int main(void) {
	int N, *a, *sorted, *unique, unique_cnt = 0;
	scanf("%d", &N);
	
	a = malloc(sizeof(int) * N);
	sorted = malloc(sizeof(int) * N);
	unique = malloc(sizeof(int) * N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		sorted[i] = a[i];
	}
	
	merge_sort(sorted, 0, N - 1);
	unique[unique_cnt++] = sorted[0];
	for(int i = 1; i < N; i++)
		if(sorted[i] != sorted[i-1])
			unique[unique_cnt++] = sorted[i];
		
	for(int i = 0; i < N; i++)
		printf("%d ", binary_search(unique, 0, unique_cnt-1, a[i]));
	
	free(a);
	free(sorted);
	free(unique);
	
	return 0;
}

void merge_sort(int *a, int p, int q)
{
	int middle = (p + q) / 2;
	if(p >= q)
		return;
	if(q - p <= 42) {
		insertion_sort(a + p, q-p+1);
		return;
	}
	
	merge_sort(a, p, middle);
	merge_sort(a, middle + 1, q);
	merge(a, p, middle, q);
}

void merge(int *a, int p, int middle, int q)
{
	int i, j, k;
	int L_len = middle - p + 1, R_len = q - middle;
	int *L, *R;
	
	L = malloc(sizeof(int) * L_len);
	R = malloc(sizeof(int) * R_len);
	
	for(int i = 0; i < L_len; i++)
		L[i] = a[p + i];
	for(int i = 0; i < R_len; i++)
		R[i] = a[middle + i + 1];
	
	i = 0; j = 0; k = p;
	while(k <= q) {
		if(i >= L_len)
			a[k++] = R[j++];
		else if(j >= R_len)
			a[k++] = L[i++];
		else {
			if(L[i] > R[j])
				a[k++] = R[j++];
			else
				a[k++] = L[i++];
		}
	}

	free(L); free(R);
}

void insertion_sort(int *a, int n)
{
	int temp;
	
	for(int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

int binary_search(int *a, int p, int q, int target)
{
	if(a[(p+q)/2] == target)
		return (p+q) / 2;
	
	if(a[(p+q)/2] > target)
		return binary_search(a, p, (p+q)/2 - 1, target);
	else
		return binary_search(a, (p+q)/2 + 1, q, target);
}