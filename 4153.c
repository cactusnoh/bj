#include <stdio.h>

int main(void)
{
	int x[3], max, sum = 0;
	
	while(1) {
		sum = 0;
		scanf("%d%d%d", &x[0], &x[1], &x[2]);
		if(x[0] == 0)
			break;
		max = x[0];
		for(int i = 1; i < 3; i++)
			if(max < x[i])
				max = x[i];
		for(int i = 0; i < 3; i++)
			if(x[i] != max)
				sum += x[i] * x[i];
		
		if(max * max == sum)
			printf("right\n");
		else
			printf("wrong\n");
	}
	
	return 0;
}