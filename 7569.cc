#include <cstdio>
#include <deque>

struct Point {
  Point(int a = -1, int b = -1, int c = -1) : x(a), y(b), z(c) {}
  int x, y, z;
};

int M, N, H;
int map[100][100][100];
std::deque<Point> frontier;

const int dx[6] = {0, 0, 0, 0, 1, -1};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {1, -1, 0, 0, 0, 0};

void BFS()
{
  while(!frontier.empty()) {
    Point p = frontier.front();
    frontier.pop_front();
    for(int i = 0; i < 6; ++i) {
      int nx = p.x + dx[i], ny = p.y + dy[i], nz = p.z + dz[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
      if(map[nx][ny][nz] == 0) {
        map[nx][ny][nz] = map[p.x][p.y][p.z] + 1;
        frontier.push_back(Point(nx, ny, nz));
      }
    }
  }
}

int main()
{
  scanf("%d%d%d", &M, &N, &H);

  for(int k = 0; k < H; ++k)
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < M; ++j)
        scanf("%d", &map[i][j][k]);

  for(int k = 0; k < H; ++k)
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < M; ++j)
        if(map[i][j][k] == 1)
          frontier.push_back(Point(i, j, k));
  
  BFS();

  int max = 0;
  for(int k = 0; k < H; ++k) {
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < M; ++j) {
        if(map[i][j][k] == 0) {
          printf("-1\n");
          return 0;
        }
        if(map[i][j][k] > max)
          max = map[i][j][k];
      }
    }
  }

  printf("%d\n", max - 1);
  
  return 0;
}