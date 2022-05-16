#include <stdio.h>

int main(void)
{
	int N, sum = 1, shell = 1;
	
	scanf("%d", &N);
	
	while(sum < N) {
		sum += 6 * shell;
		shell++;
	}
	
	printf("%d", shell);
	
	return 0;
}