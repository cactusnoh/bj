#include <cstdio>
#include <queue>

typedef std::pair<int, int> pii;

int N;
char map[101][101];
bool visited_not[100][100];
bool visited_is[100][100];
std::queue<pii> Q;

int dr[4] = {1, 0, 0, -1}, dc[4] = {0, 1, -1, 0};

int is, Not;

void checkNot(int r, int c)
{
  ++Not;
  visited_not[r][c] = true;
  Q.push(pii(r, c));

  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    for(int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i], nc = curr.second + dc[i];
      if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited_not[nr][nc]) continue;
      if(map[nr][nc] != map[r][c]) continue;
      visited_not[nr][nc] = true;
      Q.push(pii(nr, nc));
    }
  }
}

void checkIs(int r, int c)
{
  ++is;
  visited_is[r][c] = true;
  Q.push(pii(r, c));

  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    for(int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i], nc = curr.second + dc[i];
      if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited_is[nr][nc]) continue;
      if(map[r][c] == 'B' && map[nr][nc] != 'B') continue;
      if((map[r][c] == 'R' || map[r][c] == 'G') && map[nr][nc] == 'B') continue;
      visited_is[nr][nc] = true;
      Q.push(pii(nr, nc));
    }
  }
}

int main()
{
  scanf("%d", &N);

  for(int i = 0; i < N; ++i)
    scanf("%s", map[i]);
  
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      if(!visited_not[i][j])
        checkNot(i, j);

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      if(!visited_is[i][j])
        checkIs(i, j);

  printf("%d %d\n", Not, is);

  return 0;
}