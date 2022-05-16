#include <iostream>
#include <deque>

struct Point {
  Point(int a = -1, int b = -1) : x(a), y(b) {}
  int x, y;
};
bool operator==(const Point &lhs, const Point &rhs)
{
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

int T, L, visited[300][300];
Point s, d;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void BFS()
{
  for(int i = 0; i < L; ++i)
    for(int j = 0; j < L; ++j)
      visited[i][j] = 0;

  std::deque<Point> frontier = {s};
  if(s == d) {
    std::cout << 0 << std::endl;
    return;
  }
  visited[s.x][s.y] = 0;
  
  while(!frontier.empty()) {
    auto curr = frontier.front();
    frontier.pop_front();

    for(int i = 0; i < 8; ++i) {
      Point v(curr.x + dx[i], curr.y + dy[i]);
      if(v.x < 0 || v.x >= L || v.y < 0 || v.y >= L) continue;
      if(v == d) {
        std::cout << visited[curr.x][curr.y] + 1 << std::endl;
        return;
      }
      if(!visited[v.x][v.y]) {
        visited[v.x][v.y] = visited[curr.x][curr.y] + 1;
        frontier.push_back(v);
      }
    }
  }
  
}

int main()
{
  std::cin >> T;
  for(int i = 0; i < T; ++i) {
    std::cin >> L
             >> s.x >> s.y
             >> d.x >> d.y;
    BFS();
  }

  return 0;
}