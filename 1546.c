#include <stdio.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	double score[n], max = 0.0, average = 0.0;
	
	for(int i = 0; i < n; i++) {
		scanf("%lf", &score[i]);
		if(max < score[i])
			max = score[i];
	}
	
	for(int i = 0; i < n; i++) {
		score[i] = score[i] / max * 100;
		average += score[i];
	}
	printf("%lf", average / n);
	
	return 0;
}