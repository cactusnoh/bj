#include <stdio.h>

int main(void)
{
	int T, A, B;
	scanf("%d", &T);

	for(int i = 0; i < T; i++) {
		scanf("%d", &A);
		scanf("%d", &B);
		printf("%d\n", A + B);
	}
	return 0;
}