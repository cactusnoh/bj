#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point {
	int x;
	int y;
};

void merge_sort(struct point *a, int p, int q);
void merge(struct point *a, int p, int middle, int q);
bool compare_point(struct point a, struct point b);

int main(void)
{
	int N;
	struct point *coords;
	scanf("%d", &N);
	
	coords = malloc(sizeof(struct point) * N);
	for(int i = 0; i < N; i++) {
		scanf("%d%d", &coords[i].x, &coords[i].y);
	}
	
	merge_sort(coords, 0, N - 1);
	
	for(int i = 0; i < N; i++)
		printf("%d %d\n", coords[i].x, coords[i].y);
	
	free(coords);
	
	return 0;
}

void merge_sort(struct point *a, int p, int q)
{
	if(p >= q)
		return;
	
	int middle = (p + q) / 2;
	
	merge_sort(a, p, middle);
	merge_sort(a, middle + 1, q);
	merge(a, p, middle, q);
}

void merge(struct point *a, int p, int middle, int q)
{
	int len1 = middle - p + 1, len2 = q - middle;
	struct point *b, *c;
	int i, j, k;
	
	b = malloc(sizeof(struct point) * len1);
	c = malloc(sizeof(struct point) * len2);
	for(i = 0; i < len1; i++)
		b[i] = a[p + i];
	for(i = 0; i < len2; i++)
		c[i] = a[middle + 1 + i];
	
	i = 0; j = 0; k = 0;
	while(k < len1 + len2) {
		if(i >= len1)
			a[p + k++] = c[j++];
		else if(j >= len2)
			a[p + k++] = b[i++];
		else {
			if(compare_point(b[i], c[j]))
				a[p + k++] = c[j++];
			else
				a[p + k++] = b[i++];
		}
	}

	free(b); free(c);
}

bool compare_point(struct point a, struct point b)
{
	if(a.y == b.y)
		return a.x > b.x;
	return a.y > b.y;
}