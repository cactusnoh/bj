#include <stdio.h>

int main(void)
{
	int max, temp, index = 1;
	
	scanf("%d", &max);
	for(int i = 0; i < 8; i++) {
		scanf("%d", &temp);
		if(max < temp) {
			max = temp;
			index = i+2;
		}
	}
	printf("%d\n%d", max, index);
	return 0;
}