#include <stdio.h>

int main(void)
{
	int N, min, max, temp;
	
	scanf("%d%d", &N, &min);
	max = min;
	while(scanf("%d", &temp) != EOF) {
		if(min > temp)
			min = temp;
		if(max < temp)
			max = temp;
	}
	printf("%d %d", min, max);
	return 0;
}