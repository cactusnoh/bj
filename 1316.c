#include <stdio.h>
#include <string.h>

int main(void)
{
	int cnt = 0, N, alpha[26];
	char word[101];
	scanf("%d", &N);
	while(getchar() != '\n');
	
	while(gets(word)) {
		for(int i = 0; i < 26; i++)
			alpha[i] = 0;
		alpha[word[0] - 'a']++;
		
		for(int i = 1; i < strlen(word); i++) {
			if(word[i-1] != word[i] && alpha[word[i] - 'a'] != 0) {
				cnt--;
				break;
			} else
				alpha[word[i] - 'a']++;
		}
		cnt++;
	}

	printf("%d", cnt);
	
	return 0;
}