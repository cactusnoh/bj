#include <stdio.h>

int main(void)
{
	int N, d, cnt = 0;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &d);
		if(d == 1)
			cnt--;
		for(int j = d-1; j > 1; j--) {
			if(d % j == 0) {
				cnt--;
				break;
			}
		}
		cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}