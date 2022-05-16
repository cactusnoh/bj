#include <stdio.h>

int wires[10000];

int main(void)
{
	int K, N;
	int max_len, wires_cnt = 0;
	int start, middle, end;
	
	scanf("%d%d", &K, &N);
	
	scanf("%d", &wires[0]);
	max_len = wires[0];
	for(int i = 1; i < K; i++) {
		scanf("%d", &wires[i]);
		if(max_len < wires[i])
			max_len = wires[i];
	}
	
	start = 1; end = max_len;
	
	while(end >= start) {
		middle = (start + end) / 2;
		wires_cnt = 0;
		
		for(int j = 0; j < K; j++)
			wires_cnt += wires[j] / middle;
		
		if(wires_cnt >= N) {
			start = middle + 1;
			max_len = middle;
		} else
			end = middle - 1;
	}

	printf("%d", max_len);
	
	return 0;
}
