#include <stdio.h>

void d(int a[], int n);

int main(void)
{
	int n;
	scanf("%d", &n);
	
	int a, b, c, cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(i < 100)
			cnt++;
		else if(i < 1000) {
			a = i % 10;
			b = i / 10 % 10;
			c = i / 100;
			if(a-b == b-c)
				cnt++;
		}
	}
	printf("%d",cnt);
	
	return 0;
}