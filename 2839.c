#include <stdio.h>

int main(void)
{
	int N, five, three;
	scanf("%d", &N);
	
	five = N / 5;
	while(five >= 0) {
		if((N - five * 5) % 3 == 0) {
			three = (N - five * 5) / 3;
			break;
		}
		five--;
	}
	
	printf("%d", five >= 0 ? five + three : -1);
}