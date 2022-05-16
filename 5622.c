#include <stdio.h>
#include <string.h>

int main(void)
{
	int cnt = 0;
	char phone[16];
	gets(phone);
	
	for(int i = 0; i < strlen(phone); i++) {
		if('A' <= phone[i] && phone[i] <= 'C')
			cnt += 3;
		else if('D' <= phone[i] && phone[i] <= 'F')
			cnt += 4;
		else if('G' <= phone[i] && phone[i] <= 'I')
			cnt += 5;
		else if('J' <= phone[i] && phone[i] <= 'L')
			cnt += 6;
		else if('M' <= phone[i] && phone[i] <= 'O')
			cnt += 7;
		else if('P' <= phone[i] && phone[i] <= 'S')
			cnt += 8;
		else if('T' <= phone[i] && phone[i] <= 'V')
			cnt += 9;
		else if('W' <= phone[i] && phone[i] <= 'Z')
			cnt += 10;
	}

	printf("%d", cnt);
	
	return 0;
}