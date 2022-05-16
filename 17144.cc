#include <iostream>
#include <queue>

typedef std::pair<int, int> pii;
typedef std::pair<pii, int> ppiii;

int R, C, T;
int map[50][50];
int cleaner[2]; int cleanerCnt;

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, 1, -1, 0};

std::queue<ppiii> Q;
void BFS()
{
  for(int i = 0; i < R; ++i)
    for(int j = 0; j < C; ++j)
      if(map[i][j] != -1 && map[i][j] != 0)
        Q.push(ppiii(pii(i, j), map[i][j]));

  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    pii curr_pos = curr.first; 
    int quantity = curr.second, spread_cnt = 0;

    for(int i = 0; i < 4; ++i) {
      int nr = curr_pos.first + dr[i], nc = curr_pos.second + dc[i];
      if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == -1) continue;
      map[nr][nc] += quantity / 5;
      ++spread_cnt;
    }

    map[curr_pos.first][curr_pos.second] -= spread_cnt * (quantity / 5);
  }
  
  // counter clockwise
  for(int i = cleaner[0] - 1; i > 0; --i)
    map[i][0] = map[i - 1][0];
  for(int i = 0; i < C - 1; ++i)
    map[0][i] = map[0][i + 1];
  for(int i = 0; i < cleaner[0]; ++i)
    map[i][C - 1] = map[i + 1][C - 1];
  for(int i = C - 1; i > 1; --i)
    map[cleaner[0]][i] = map[cleaner[0]][i - 1];
  map[cleaner[0]][1] = 0;

  // clockwise
  for(int i = cleaner[1] + 1; i < R - 1; ++i)
    map[i][0] = map[i + 1][0];
  for(int i = 0; i < C - 1; ++i)
    map[R - 1][i] = map[R - 1][i + 1];
  for(int i = R - 1; i > cleaner[1]; --i)
    map[i][C - 1] = map[i - 1][C - 1];
  for(int i = C - 1; i > 1; --i)
    map[cleaner[1]][i] = map[cleaner[1]][i - 1];
  map[cleaner[1]][1] = 0;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> R >> C >> T;

  for(int i = 0; i < R; ++i) {
    for(int j = 0; j < C; ++j) {
      std::cin >> map[i][j];
      if(map[i][j] == -1)
        cleaner[cleanerCnt++] = i;
    }
  }

  while(T--)
    BFS();

  int ans = 0;
  for(int i = 0; i < R; ++i)
    for(int j = 0; j < C; ++j)
      if(map[i][j] != -1 && map[i][j] != 0)
        ans += map[i][j];
  std::cout << ans << std::endl;

  return 0;
}