#include <iostream>
#include <cstdio>
#include <deque>

int N, M;
int map[100][100];
int level[100][100];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void BFS(int x, int y)
{
  std::deque<std::pair<int, int>> frontier = {{x, y}};
  ++level[x][y];

  while(!frontier.empty()) {
    auto pair = frontier.front();
    frontier.pop_front();
    for(int i = 0; i < 4; ++i) {
      int nx = pair.first + dx[i], ny = pair.second + dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if(level[nx][ny] == 0 && map[nx][ny]) {
        level[nx][ny] = level[pair.first][pair.second] + 1;
        frontier.push_back({nx, ny});
      }
    }
  }
}

int main()
{
  std::cin >> N >> M;

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      scanf("%1d", &map[i][j]);
  
  BFS(0, 0);

  printf("%d\n", level[N - 1][M - 1]);

  return 0;
}