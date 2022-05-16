#include <stdio.h>

int trees[1000000];
int max_tree = 0;
int max_len = 0;

int main(void)
{
	int N, M;
	
	scanf("%d%d", &N, &M);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &trees[i]);
		if(max_tree < trees[i])
			max_tree = trees[i];
	}
	
	int p = 0, q = max_tree;
	long sum;
	while(p <= q) {
		//printf("p = %d, q = %d\n", p, q);
		sum = 0;
		for(int i = 0; i < N; i++)
			sum += trees[i] > (p + q) / 2 ? trees[i] - (p + q) / 2 : 0;
		
		if(sum > M)
			p = (p + q) / 2 + 1;
		else if(sum < M)
			q = (p + q) / 2 - 1;
		else {
			printf("%d\n", (p + q) / 2);
			return 0;
		}
	}
	
	printf("%d\n", q);
	
	return 0;
}

/*

1 ~ 20

sum of cut trees
lower bound that meets requirement

38 - 14
37 - 17
36 - 20

*/