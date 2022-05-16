#include <stdio.h>

int main(void)
{
	int N, temp, count[10001] = {0};
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		count[temp]++;
	}
		
	for(int i = 0; i < 10001; i++)
		if(count[i])
			for(int j = 0; j < count[i]; j++)
				printf("%d\n", i);
	
	return 0;
}