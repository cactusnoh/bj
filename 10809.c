#include <stdio.h>

int main(void)
{
	int alpha[26], ch, index = 0;
	for(int i = 0; i < 26; i++)
		alpha[i] = -1;
	while((ch = getchar()) != '\n') {
		if(alpha[ch-'a'] == -1)
			alpha[ch - 'a'] = index;
		index++;
	}
	for(int i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
	
	return 0;
}