#include <stdlib.h>
#include <stdio.h>

void insert(int a[], int n, int value);
int *binary_search(int a[], int n, int value);

int main(void)
{
	int sorted_array[100000];
	int N, size = 0, temp;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		insert(sorted_array, size++, temp);

		if(size % 2)
			printf("%d\n", sorted_array[size / 2]);
		else
			printf("%d\n", sorted_array[size / 2] > sorted_array[size / 2 - 1] ? sorted_array[size / 2 - 1] : sorted_array[size / 2]);
	}
}

void insert(int a[], int n, int value)
{
	int insert_index = binary_search(a, n, value) - a;
	
	for(int i = n; i >= insert_index; i--)
		a[i + 1] = a[i];
	
	a[insert_index] = value;
}

int *binary_search(int a[], int n, int value)
{
	if(n == 0)
		return a;
	
	if(n == 1)
		return a[0] > value ? a : a + 1;
	
	if(a[n / 2] < value)
		return binary_search(a + n / 2 + 1, n / 2, value);
	else if(a[n / 2] > value)
		return binary_search(a, n / 2, value);
	else
		return a + n / 2;
}