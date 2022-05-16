#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch, count[10] = {0};
	
	while(!isspace(ch = getchar()) && ch != EOF)
		count[ch - '0']++;
	
	for(int i = 9; i >= 0; i--)
		if(count[i])
			for(int j = 0; j < count[i]; j++)
				printf("%d", i);
}