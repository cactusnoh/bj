#include <stdio.h>

int main(void)
{
	int n, cont, score;
	char input;
	scanf("%d", &n);
	while(getchar() != '\n');
	for(int i = 0; i < n; i++) {
		score = 0;
		cont = 0;
		while((input = getchar()) != '\n' && input != EOF) {
			if(input == 'O') {
				cont++;
				score += cont;
			} else {
				cont = 0;
			}
		}
		printf("%d\n", score);
	}
	
	return 0;
}