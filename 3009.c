#include <stdio.h>

int main(void)
{
	int x = 0, y = 0, t1, t2;
	
	scanf("%d%d", &t1, &t2);
	x += t1; y += t2;
	scanf("%d%d", &t1, &t2);
	if(t1 == x) x -= t1;
	else x += t1;
	if(t2 == y) y -= t2;
	else y += t2;
	scanf("%d%d", &t1, &t2);
	x -= t1; y -= t2;
	
	printf("%d %d", x > 0 ? x : -x, y > 0 ? y : -y);
		
	return 0;
}