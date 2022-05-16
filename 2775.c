#include <stdio.h>

int main(void)
{
	int T, k, n;
	
	scanf("%d", &T);
	for(int i = 0; i < T; i++) {
		scanf("%d%d", &k , &n);
		int apart[k+1][n];
		
		for(int j = 1; j <= k; j++)
			for(int l = 0; l < n; l++)
				apart[j][l] = 0;

		for(int j = 0; j < n; j++)
			apart[0][j] = j + 1;
		
		for(int j = 1; j <= k; j++)
			for(int l = 0; l < n; l++)
				for(int m = 0; m <= l; m++)
					apart[j][l] += apart[j-1][m];
		
		printf("%d\n", apart[k][n-1]);
	}
	return 0;
}