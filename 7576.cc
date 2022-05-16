#include <cstdio>
#include <deque>

int M, N;
int map[1000][1000];
std::deque<std::pair<int, int>> frontier;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void BFS()
{
  while(!frontier.empty()) {
    auto p = frontier.front();
    frontier.pop_front();
    for(int i = 0; i < 4; ++i) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(map[nx][ny] == 0) {
        map[nx][ny] = map[p.first][p.second] + 1;
        frontier.push_back({nx, ny});
      }
    }
  }
}

int main()
{
  scanf("%d%d", &M, &N);

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      scanf("%d", &map[i][j]);
  
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      if(map[i][j] == 1)
        frontier.push_back({i, j});
  
  BFS();

  int max = 0;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      if(map[i][j] == 0) {
        printf("-1\n");
        return 0;
      }
      if(map[i][j] > max)
        max = map[i][j];
    }
  }

  printf("%d\n", max - 1);
  
  return 0;
}