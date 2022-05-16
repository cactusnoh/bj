#include <cstdio>
#include <utility>

#define SIZE 9
#define SEG(r, c) (3 * ((r) / 3) + (c) / 3)

typedef std::pair<int, int> pii;

int map[SIZE][SIZE];
bool occupied_row[9][10], occupied_col[9][10], occupied_seg[9][10];
pii toSolve[81]; int totSolve;

bool solve(int solved)
{
  if(solved == totSolve)
    return true;

  int r = toSolve[solved].first, c = toSolve[solved].second;
  
  for(int i = 1; i <= 9; ++i) {
    if(occupied_row[r][i] || occupied_col[c][i] || occupied_seg[SEG(r, c)][i])
      continue;
    bool temp1 = occupied_row[r][i], temp2 = occupied_col[c][i], temp3 = occupied_seg[SEG(r, c)][i];
    occupied_row[r][i] = occupied_col[c][i] = occupied_seg[SEG(r, c)][i] = true;
    map[r][c] = i;
    if(solve(solved + 1))
      return true;
    map[r][c] = 0;
    occupied_row[r][i] = temp1; occupied_col[c][i] = temp2; occupied_seg[SEG(r, c)][i] = temp3;
  }

  return false;
}

int main()
{
  for(int i = 0; i < SIZE; ++i) {
    for(int j = 0; j < SIZE; ++j) {
      scanf("%1d", &map[i][j]);
      if(map[i][j] == 0)
        toSolve[totSolve++] = pii(i, j);
      occupied_row[i][map[i][j]] = occupied_col[j][map[i][j]] = true;
      occupied_seg[SEG(i, j)][map[i][j]] = true;
    }
  }

  solve(0);

  for(int i = 0; i < SIZE; ++i) {
    for(int j = 0; j < SIZE; ++j)
      printf("%d", map[i][j]);
    printf("\n");
  }

  return 0;
}