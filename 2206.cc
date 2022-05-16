#include <iostream>
#include <cstdio>
#include <utility>
#include <deque>

struct Point {
  Point(int a = 0, int b = 0, int c = 0) : x(a), y(b), broke(c) {}
  int x, y, broke;
};

int N, M, map[1001][1001], level[1001][1001][2];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0,};
int min = INT32_MAX;

void BFS()
{
  std::deque<Point> frontier = {Point(1, 1)};
  level[1][1][0] = 1;

  while(!frontier.empty()) {
    Point curr = frontier.front();
    frontier.pop_front();
    for(int i = 0; i < 4; ++i) {
      int nx = curr.x + dx[i], ny = curr.y + dy[i], broke = curr.broke;
      if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
      if(level[nx][ny][broke] != 0) continue;
      if(map[nx][ny] == 1 && broke == 0) {
        level[nx][ny][1] = level[curr.x][curr.y][curr.broke] + 1;
        frontier.push_back(Point(nx, ny, 1));
      }
      if(map[nx][ny] == 0) {
        level[nx][ny][curr.broke] = level[curr.x][curr.y][curr.broke] + 1;
        frontier.push_back(Point(nx, ny, curr.broke));
      }
    }
  }

  if(level[N][M][0])
    min = level[N][M][0];
  if(level[N][M][1] && min > level[N][M][1])
    min = level[N][M][1];
}

int main()
{
  std::cin >> N >> M;

  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= M; ++j)
      scanf("%1d", &map[i][j]);

  BFS();

  std::cout << (min == INT32_MAX ? -1 : min) << std::endl;

  return 0;
}