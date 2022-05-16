#include <stdio.h>

int main(void)
{
	int n = 0, temp, cnt[42];
	
	for(int i = 0; i < 42; i++)
		cnt[i] = 0;
	for(int i = 0; i < 10; i++) {
		scanf("%d", &temp);
		cnt[temp % 42]++;
	}
	for(int i = 0; i < 42; i++)
		if(cnt[i])
				n++;
	printf("%d", n);
	return 0;
}