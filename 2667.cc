#include <iostream>
#include <queue>
#include <cstdio>

int N, cnt, len;
int map[25][25];
bool visited[25][25];
std::priority_queue<int , std::vector<int>, std::greater<int>> lens;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void DFS(int x, int y)
{
  ++len;
  visited[x][y] = true;

  for(int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if(nx < 0 || nx >= N || ny < 0 || ny >= N) 
      continue;
    if(!visited[nx][ny] && map[nx][ny])
      DFS(nx, ny);
  }
}


void BFS(int x, int y) {  
  int len = 0;
  std::queue<std::pair<int, int>> frontier;

  frontier.push({x, y});
  visited[x][y] = true;
  ++cnt; ++len;

  while(!frontier.empty()) {
    auto p = frontier.front();
    frontier.pop();

    for(int i = 0; i < 4; ++i) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N) 
        continue;
      if(!visited[nx][ny] && map[nx][ny]) {
        visited[nx][ny] = true;
        frontier.push({nx, ny});
        ++len;
      }
    }

  }

  lens.push(len);
}

// BFS implementation
/*
int main()
{
  std::cin >> N;

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      scanf("%1d", &map[i][j]);

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      if(!visited[i][j] && map[i][j])
        BFS(i, j);

  std::cout << cnt << std::endl;
  while(!lens.empty()) {
    std::cout << lens.top() << std::endl;
    lens.pop();
  }
  
  return 0;
}
*/

// DFS implementation
int main()
{
  std::cin >> N;

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      scanf("%1d", &map[i][j]);

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(!visited[i][j] && map[i][j]) {
        len = 0;
        ++cnt;
        DFS(i, j);
        lens.push(len);
      }
    }
  }

  std::cout << cnt << std::endl;
  while(!lens.empty()) {
    std::cout << lens.top() << std::endl;
    lens.pop();
  }
  
  return 0;
}