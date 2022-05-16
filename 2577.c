#include <stdio.h>

int main(void)
{
	int n, temp, cnt[10];
	
	scanf("%d", &n);
	scanf("%d", &temp);
	n *= temp;
	scanf("%d", &temp);
	n *= temp;
	for(int i = 0; i < 10; i++) {
		cnt[i] = 0;
	}
	while(n) {
		cnt[n % 10]++;
		n /= 10;
	}
	for(int i = 0; i < 10; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}