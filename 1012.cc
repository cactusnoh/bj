#include <iostream>
#include <vector>
#include <deque>

int T, N, M, K;
int map[50][50];
bool visited[50][50];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int cnt;

void reset()
{
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      map[i][j] = 0;
      visited[i][j] = false;
    }
  }
  cnt = 0;
}

void DFS(int x, int y)
{
  visited[x][y] = true;

  for(int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if(nx < 0 || nx >= N || ny < 0 || ny >= M)
      continue;
    if(!visited[nx][ny] && map[nx][ny])
      DFS(nx, ny);
  }
}

void BFS(int x, int y)
{
  std::deque<std::pair<int, int>> frontier = {{x, y}};
  ++cnt;
  visited[x][y] = true;

  while(!frontier.empty()) {
    auto pair = frontier.front();
    frontier.pop_front();

    for(int i = 0; i < 4; ++i) {
      int nx = pair.first + dx[i], ny = pair.second + dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if(!visited[nx][ny] && map[nx][ny]) {
        frontier.push_back({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}

/*
int main()
{
  std::cin >> T;

  for(int i = 0; i < T; ++i) {
    std::cin >> N >> M >> K;
    for(int j = 0; j < K; ++j) {
      int x, y;
      std::cin >> x >> y;
      map[x][y] = 1;
    }

    for(int j = 0; j < N; ++j) {
      for(int k = 0; k < M; ++k) {
        if(!visited[j][k] && map[j][k])
          BFS(j, k);
      }
    }
    std::cout << cnt << std::endl;

    reset();
  }

  return 0;
}
*/

int main()
{
  std::cin >> T;

  for(int i = 0; i < T; ++i) {
    std::cin >> N >> M >> K;
    for(int j = 0; j < K; ++j) {
      int x, y;
      std::cin >> x >> y;
      map[x][y] = 1;
    }

    for(int j = 0; j < N; ++j) {
      for(int k = 0; k < M; ++k) {
        if(!visited[j][k] && map[j][k]) {
          DFS(j, k);
          ++cnt;
        }
      }
    }
    std::cout << cnt << std::endl;

    reset();
  }

  return 0;
}