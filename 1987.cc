#include <cstdio>

int R, C;
char map[20][20];
bool visitedAlpha[26];
int maxLevel;

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, 1, -1, 0};
void solve(int r, int c, int seen)
{
  visitedAlpha[map[r][c] - 'A'] = true;

  bool canGo = false;
  for(int i = 0; i < 4; ++i) {
    int nr = r + dr[i], nc = c + dc[i];
    if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
    if(visitedAlpha[map[nr][nc] - 'A']) continue;
    canGo = true;
    solve(nr, nc, seen + 1);
  }

  if(canGo == false && maxLevel < seen)
      maxLevel = seen;

  visitedAlpha[map[r][c] - 'A'] = false;
}

int main()
{
  scanf("%d %d\n", &R, &C);
  for(int i = 0; i < R; ++i)
    for(int j = 0; j < C; ++j)
      scanf("%1c ", &map[i][j]);

  solve(0, 0, 1);

  printf("%d\n", maxLevel);

  return 0;
}