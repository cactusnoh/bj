#include <iostream>
#include <queue>

typedef std::pair<int, int> pii;

int N, M;
int map[1000][1000], freeArea[1000010], freeCnt = 2;
char ans[1001][1001];
bool visited[1000010];

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};

std::queue<pii> Q;
void BFS(int i, int j)
{
  map[i][j] = freeCnt;
  Q.push(pii(i, j));
  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    int r = curr.first, c = curr.second;

    ++freeArea[freeCnt];

    for(int k = 0; k < 4; ++k) {
      int nr = r + dr[k], nc = c + dc[k];
      if(nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc]) 
        continue;
      map[nr][nc] = freeCnt;
      Q.push(pii(nr, nc));
    }
  }
  ++freeCnt;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  char buf[1001];
  std::cin >> N >> M;

  for(int i = 0; i < N; ++i) {
    std::cin >> buf;
    for(int j = 0; j < M; ++j)
      map[i][j] = buf[j] - '0';
  }

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      if(map[i][j] == 0)
        BFS(i, j);

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      if(map[i][j] != 1) {
        ans[i][j] = '0';
        continue;
      }

      int sum = 1;
      for(int k = 0; k < 4; ++k) {
        int nr = i + dr[k], nc = j + dc[k];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[map[nr][nc]])
          continue;
        visited[map[nr][nc]] = true;
        sum += freeArea[map[nr][nc]];
      }
      
      for(int k = 0; k < 4; ++k) {
        int nr = i + dr[k], nc = j + dc[k];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M)
          continue; 
        visited[map[nr][nc]] = false;
      }
      
      sum %= 10;
      ans[i][j] = sum + '0';
    }
  }

  for(int i = 0; i < N; ++i)
    std::cout << ans[i] << "\n";

  return 0;
}