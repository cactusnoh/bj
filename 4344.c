#include <stdio.h>

int main(void)
{
	int n, student, temp, cnt;
	double average;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		cnt = 0;
		average = 0.0;
		scanf("%d", &student);
		int score[student];
		for(int j = 0; j < student; j++) {
			scanf("%d", &score[j]);
			average += score[j];
		}
		average /= student;
		for(int j = 0; j < student; j++)
			if(score[j] > average)
				cnt++;
		printf("%.3lf%%\n", (double) cnt * 100 / student);
	}
	
	return 0;
}