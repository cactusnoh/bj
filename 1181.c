#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge_sort(char **a, int p, int q);
void merge(char **a, int p, int middle, int q);
void insertion_sort(char **a, int n);
int compare_str(char *p, char *q);

int main(void)
{
	int N;
	char **a;
	
	scanf("%d", &N);
	a = malloc(sizeof(char *) * N);
	for(int i = 0; i < N; i++) {
		a[i] = malloc(sizeof(char) * 51);
		scanf("%s", a[i]);
	}

	merge_sort(a, 0, N-1);
	
	printf("%s\n", a[0]); 
	for(int i = 1; i < N; i++)
		if(strcmp(a[i-1], a[i]) != 0)
			printf("%s\n", a[i]); 
	
	for(int i = 0; i < N; i++)
		free(a[i]);
	free(a);
	
	return 0;
}

void merge_sort(char **a, int p, int q)
{
	int middle = (p + q) / 2;
	if(p >= q)
		return;
	if(q - p <= 10) {
		insertion_sort(a + p, q-p+1);
		return;
	}
	
	merge_sort(a, p, middle);
	merge_sort(a, middle + 1, q);
	merge(a, p, middle, q);
}

void merge(char **a, int p, int middle, int q)
{
	int i, j, k;
	int L_len = middle - p + 1, R_len = q - middle;
	char **L, **R;
	
	L = malloc(sizeof(char *) * L_len);
	R = malloc(sizeof(char *) * R_len);
	
	for(int i = 0; i < L_len; i++) {
		L[i] = malloc(sizeof(char) * 51);
		strcpy(L[i], a[p + i]);
	}
	for(int i = 0; i < R_len; i++) {
		R[i] = malloc(sizeof(char) * 51);
		strcpy(R[i], a[middle + i + 1]);
	}
	
	i = 0; j = 0; k = p;
	while(k <= q) {
		if(i >= L_len)
			strcpy(a[k++], R[j++]);
		else if(j >= R_len)
			strcpy(a[k++], L[i++]);
		else {
			if(compare_str(L[i], R[j]))
				strcpy(a[k++], R[j++]);
			else
				strcpy(a[k++], L[i++]);
		}
	}
	
	for(int i = 0; i < L_len; i++)
		free(L[i]);
	for(int i = 0; i < R_len; i++)
		free(R[i]);
	free(L); free(R);
}

void insertion_sort(char **a, int n)
{
	char temp[51];
	
	for(int i = 1; i < n; i++) {
		for(int j = i - 1; j >= 0; j--) {
			if(compare_str(a[j], a[j+1])) {
				strcpy(temp, a[j+1]);
				strcpy(a[j+1], a[j]);
				strcpy(a[j], temp);
			}
		}
	}
}

int compare_str(char *p, char *q)
{
	if(strlen(p) == strlen(q)) {
		if(strcmp(p, q) > 0)
			return 1;
		else 
			return 0;
	}
	return strlen(p) > strlen(q);
}