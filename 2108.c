#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, temp, count[8001] = {0}, *a;
	int max = -4001, min = 4001, sum = 0;
	int first_mode = 4001, second_mode = 4001, mode_cnt = 0;
	int k = 0;
	int average;
	scanf("%d", &N);
	
	a = malloc(sizeof(int) * N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		count[a[i] + 4000]++;
		if(a[i] > max)
			max = a[i];
		if(a[i] < min)
			min = a[i];
	}
	
	for(int i = 0; i < 8001; i++) {
		if(count[i] > mode_cnt) {
			first_mode = i - 4000;
			second_mode = 4001;
			mode_cnt = count[i];
		} else if(count[i] == mode_cnt) {
			if(i - 4000 < first_mode)
				first_mode = i - 4000;
			else if(i - 4000 < second_mode)
				second_mode = i - 4000;
		}
	}
	if(second_mode == 4001)
		second_mode = first_mode;
	
	for(int i = 0; i < 8001; i++) {
		if(count[i])
			for(int j = 0; j < count[i]; j++)
				a[k++] = i - 4000;
	}
		
	average = sum > 0 ? (double)sum / N + 0.5 : (double)sum / N - 0.5;
	printf("%d\n%d\n%d\n%d"		, average
														, a[N/2]
														, second_mode
														, max - min);
	
	return 0;
}

/*
	0    3999 4000 4001     8001
-4000 ~ -1   0   1 ~     4000

*/