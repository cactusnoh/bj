#include <iostream>
#include <queue>
#include <cstring>

typedef std::pair<int, int> pii;

int N, M;
int map[8][8];
int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, 1, -1, 0};

pii viruses[10], emptys[64];
int virusCnt, emptyCnt;

int ans;

std::queue<pii> Q;
bool visited[8][8];
int BFS()
{
  int cnt = 0;
  memset(visited, 0, sizeof(visited));

  for(int i = 0; i < virusCnt; ++i)
    Q.push(viruses[i]);

  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    for(int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i], nc = curr.second + dc[i];
      if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || map[nr][nc] != 0) continue;
      visited[nr][nc] = true;
      ++cnt; 
      Q.push(pii(nr, nc));
    }
  }

  return emptyCnt - cnt - 3;
}

void chooseWalls(int tosee, int cnt)
{
  if(tosee == emptyCnt || cnt == 3) {
    if(cnt != 3) return;
    int temp = BFS();
    if(temp > ans)
      ans = temp;
    return;
  }

  pii temp = emptys[tosee];
  map[temp.first][temp.second] = 1;
  chooseWalls(tosee + 1, cnt + 1);
  map[temp.first][temp.second] = 0;
  chooseWalls(tosee + 1, cnt);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      std::cin >> map[i][j];
      if(map[i][j] == 2)
        viruses[virusCnt++] = pii(i, j);
      else if(map[i][j] == 0)
        emptys[emptyCnt++] = pii(i, j);
    }
  }

  chooseWalls(0, 0);
  std::cout << ans << std::endl;

  return 0;
}