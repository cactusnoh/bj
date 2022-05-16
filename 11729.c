#include <stdio.h>

void hanoi(int n, int init, int helper, int target);

int main(void)
{
	int N, cnt = 1;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		cnt *= 2;
	printf("%d\n", cnt - 1);
	hanoi(N, 1, 2, 3);
	
	return 0;
}

void hanoi(int n, int init, int helper, int target)
{
	if(n == 1) {
		printf("%d %d\n", init, target);
		return;
	}
	
	hanoi(n - 1, init, target, helper);
	hanoi(1, init, helper, target);
	hanoi(n - 1, helper, init, target);
	
}

/*
1 -> 3


1 -> 2
1 -> 3
2 -> 3
1 init 2 helper 3 target


1 -> 3
1 -> 2
3 -> 2
1 init 3 helper 2 target
1 -> 3
2 init 1 helper 3 target

1   3     7    15
1 1+1+1 3+1+3 7+1+7
*/