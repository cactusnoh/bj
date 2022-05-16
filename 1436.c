#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int cnt = 0, six_cnt, N, i = 0, temp;
	bool cont;
	scanf("%d", &N);
	
	while(cnt != N) {
		six_cnt = 0;
		temp = i;
		cont = false;
		
		while(temp) {
			if(temp % 10 == 6) {
				if(cont == false) {
					cont = true;
					six_cnt = 1;
				} else
					six_cnt++;
			} else
				cont = false;
			
			if(six_cnt >= 3) {
				cnt++;
				break;
			}
			
			temp /= 10;
		}
		
		i++;
	}
	
	printf("%d", i-1);
	return 0;
}

/*
666 1666 2666 3666 4666 5666 
6660 6661 6662 6663 ~ 6669
7666 8666 9666
10666 ~
20666
*/