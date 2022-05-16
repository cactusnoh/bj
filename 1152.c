#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int cnt = 0, ch, ch_prev = 0;
	
	while(isspace(ch = getchar()));
	if(ch == EOF) {
		printf("0");
		return 0;
	}
	cnt++;
	
	while((ch = getchar()) != EOF) {
		if(isspace(ch) && isspace(ch_prev))
			break;
		if(!isspace(ch) && isspace(ch_prev))
			cnt++;
		ch_prev = ch;
	}
	
	printf("%d", cnt);
	return 0;
}