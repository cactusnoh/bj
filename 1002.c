#include <stdio.h>

int main(void)
{
	int i;
	int T, x1, y1, x2, y2, r1, r2;
	int r_squared, d_squared, cnt;
	scanf("%d", &T);
	
	for(i = 0; i < T; i++) {
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		r_squared = (r1 - r2) * (r1 - r2);
		d_squared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		
		if(d_squared > (r1 + r2) * (r1 + r2))
			cnt = 0;
		else if(d_squared == (r1 + r2) * (r1 + r2))
			cnt = 1;
		else {
			if(d_squared > r_squared)
				cnt = 2;
			else if(d_squared == r_squared)
				cnt = 1;
			else
				cnt = 0;
		}
		
		if(x1 == x2 && y1 == y2 && r1 == r2)
			cnt = -1;
		
		printf("%d\n", cnt);
	
	}
	return 0;
}