#include <stdio.h>
#include <string.h>

int main(void)
{
	int cnt = 0;
	char alpha[101];
	gets(alpha);
	
	for(int i = 0; i < strlen(alpha);) {
		if(alpha[i] == 'd' && alpha[i+1] == 'z' && alpha[i+2] == '=') {
			cnt++;
			i = i + 3;
		} else if(alpha[i] == 'c' && alpha[i+1] == '=') {
			cnt++;
			i = i + 2;
		} else if(alpha[i] == 'c' && alpha[i+1] == '-') {
			cnt++;
			i = i + 2;
		} else if(alpha[i] == 'd' && alpha[i+1] == '-') {
			cnt++;
			i = i + 2;
		} else if(alpha[i] == 'l' && alpha[i+1] == 'j') {
			cnt++;
			i = i + 2;
		} else if(alpha[i] == 'n' && alpha[i+1] == 'j') {
			cnt++;
			i = i + 2;
		} else if(alpha[i] == 's' && alpha[i+1] == '=') {
			cnt++;
			i = i + 2;
		} else if(alpha[i] == 'z' && alpha[i+1] == '=') {
			cnt++;
			i = i + 2;
		} else {
			cnt++;
			i++;
		}
		
	}

	printf("%d", cnt);
	
	return 0;
}