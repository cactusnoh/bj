#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compare_board(char **p, char (*q)[8], int i, int j);

int main(void)
{
	int N, M, row = 0, col = 0, diff1, diff2, min = 65;
	char **p, ch;
	char chess_1[8][8] = 	{	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
													'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
													'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
													'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
													'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
													'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
													'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
													'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'
												};
	char chess_2[8][8] = 	{	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
													'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
													'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
													'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
													'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
													'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
													'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
													'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
												};
												
	scanf("%d%d", &N, &M);
	
	p = malloc(N * sizeof(char *));
	for(int i = 0; i < N; i++)
		p[i] = malloc(M * sizeof(char));
	
	while(isspace(ch = getchar()));
	for(int i = 0; i < M * N; i++) {
		p[row][col++] = ch;
		if(col == M) {
			row++;
			col = 0;
		}
		while(isspace(ch = getchar()));
	}
	
	for(int i = 0; i <= N - 8; i++) {
		for(int j = 0; j <= M - 8; j++) {
			diff1 = compare_board(p, chess_1, i, j);
			diff2 = compare_board(p, chess_2, i, j);
			if(diff1 < min)
				min = diff1;
			if(diff2 < min)
				min = diff2;
		}
	}
	
	printf("%d", min);
	
	return 0;
}

int compare_board(char **p, char (*q)[8], int row, int col)
{
	int cnt = 0;
	for(int i = row; i < row + 8; i++) {
		for(int j = col; j < col + 8; j++) {
			if(p[i][j] != q[i - row][j - col])
				cnt++;
		}
	}
	return cnt;
}