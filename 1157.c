#include <stdio.h>

int main(void)
{
	int ch, alpha[26], max_index = 0, max = 0;
	
	for(int i = 0; i < 26; i++) {
		alpha[i] = 0;
	}
	
	while((ch = getchar()) != EOF) {
		if(ch >= 'a')
			alpha[ch - 'a']++;
		else
			alpha[ch - 'A']++;
	}
	
	for(int i = 0; i < 26; i++) {
		if(alpha[i] > max) {
			max_index = i;
			max = alpha[i];
		}
	}
	
	for(int i = 0; i < 26; i++) {
		if(i != max_index && alpha[i] == max) {
			printf("?");
			return 0;
		}
	}
	
	printf("%c", max_index + 'A');
	
	return 0;
}