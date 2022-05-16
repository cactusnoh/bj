#include <stdio.h>

int main(void)
{
	char ch;
	int t, r;
	scanf("%d", &t);
	
	for(int i = 0; i < t; i++) {
		scanf("%d", &r);
		getchar();
		while((ch = getchar()) != '\n' && ch != EOF) {
			for(int j = 0; j < r; j++)
				printf("%c", ch);
		}
		printf("\n");
	}
	
	return 0;
}