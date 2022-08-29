#include <iostream>
#include <queue>

struct Point {
  Point (int _r = 0, int _c = 0) : r(_r), c(_c) {}
  int r;
  int c;
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int R, C;
char map[1500][1500];
bool swan_visited[1500][1500];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  // one swan will move around the map
  std::queue<Point> swan_queue[2];
  // water tiles
  std::queue<Point> water_queue[2];

  std::cin >> R >> C;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      std::cin >> map[r][c];
      // insert only one swan
      if (map[r][c] == 'L' && swan_queue[0].empty()) {
        map[r][c] = '.';
        swan_visited[r][c] = true;
        swan_queue[0].emplace(r, c);
      }
      // push all water tiles into water_queue
      if (map[r][c] != 'X') {
        water_queue[0].emplace(r, c);
      }
    }
  }

  int day = 0;
  while (true) {
    // 1. BFS for the swan
    while (!swan_queue[day & 1].empty()) {
      auto curr = swan_queue[day & 1].front();
      swan_queue[day & 1].pop();
      for (int i = 0; i < 4; ++i) {
        int nr = curr.r + dr[i];
        int nc = curr.c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
            swan_visited[nr][nc]) {
          continue;
        }
        if (map[nr][nc] == 'X') {
          // swan will visit this ice tile next day it melts
          swan_visited[nr][nc] = true;
          swan_queue[!(day & 1)].emplace(nr, nc);
        } else if (map[nr][nc] == 'L') {
          // found another swan; return
          std::cout << day << "\n";
          return 0;
        } else if (map[nr][nc] == '.') {
          // move around water tiles available
          swan_visited[nr][nc] = true;
          swan_queue[day & 1].emplace(nr, nc);
        }
      }
    }
    // 2. Melt ice adjacent to water
    while (!water_queue[day & 1].empty()) {
      auto curr = water_queue[day & 1].front();
      water_queue[day & 1].pop();
      for (int i = 0; i < 4; ++i) {
        int nr = curr.r + dr[i];
        int nc = curr.c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
            map[nr][nc] != 'X') {
          continue;
        }
        map[nr][nc] = '.';
        water_queue[!(day & 1)].emplace(nr, nc);
      }
    }
    // 3. Increment day
    ++day;
  }

  return 0;
}