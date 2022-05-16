#include <stdio.h>
#include <stdlib.h>

struct user {
	int age;
	char name[101];
};

void merge_sort(struct user *a, int p, int q);
void merge(struct user *a, int p, int middle, int q);
void insertion_sort(struct user *a, int n);

int main(void)
{
	int N;
	struct user *a;
	
	scanf("%d", &N);
	a = malloc(sizeof(struct user) * N);
	for(int i = 0; i < N; i++)
		scanf("%d %s", &a[i].age, a[i].name);

	merge_sort(a, 0, N-1);
	 
	for(int i = 0; i < N; i++)
		printf("%d %s\n", a[i].age, a[i].name); 
	
	free(a);
	
	return 0;
}

void merge_sort(struct user *a, int p, int q)
{
	int middle = (p + q) / 2;
	if(p >= q)
		return;
	if(q - p <= 20) {
		insertion_sort(a + p, q-p+1);
		return;
	}
	
	merge_sort(a, p, middle);
	merge_sort(a, middle + 1, q);
	merge(a, p, middle, q);
}

void merge(struct user *a, int p, int middle, int q)
{
	int i, j, k;
	int L_len = middle - p + 1, R_len = q - middle;
	struct user *L, *R;
	
	L = malloc(sizeof(struct user) * L_len);
	R = malloc(sizeof(struct user) * R_len);
	
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
			if(L[i].age > R[j].age)
				a[k++] = R[j++];
			else
				a[k++] = L[i++];
		}
	}

	free(L); free(R);
}

void insertion_sort(struct user *a, int n)
{
	struct user temp;
	
	for(int i = 1; i < n; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(a[j+1].age < a[j].age) {
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}