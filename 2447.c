#include <stdio.h>
#include <stdlib.h>

int N;

void make_star(char **stars, int n);

int main(void)
{
	int i, j;
	char **stars;
	//allocate array
	scanf("%d", &N);
	stars = malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++)
		stars[i] = malloc(sizeof(char) * N);
	//initialize array
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			stars[i][j] = '*';
	
	make_star(stars, N);
	
	//print array
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++)
			printf("%c", stars[i][j]);
		printf("\n");
	}
	//free memory
	for(i = 0; i < N; i++)
		free(stars[i]);
	free(stars);
	
	return 0;
}

void make_star(char **stars, int n)
{
	int i, j, k;
	
	if(n == 1)
		return;
	
	for(i = n / 3; i < 2 * n / 3; i++)
		for(k = n / 3; k < N; k += n)
			for(j = k; j < k + n / 3; j++)
				stars[i][j] = ' ';
		
	for(i = 0; i < 3; i++) {
		make_star(stars + (n / 3) * i, n / 3);
	}
}