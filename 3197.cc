#include <iostream>
#include <queue>

struct Point {
  Point (int _r = 0, int _c = 0) : r(_r), c(_c) {}
  int r;
  int c;
};

struct Entry {
  Entry (Point _p, int _day = 0) : p(_p), day(_day) {}
  Point p;
  int day;
};

int R, C;
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, 1, -1, 0};
char map[1501][1501];

int tot_areas;
int area[1500][1500];

int parent[2'250'000];
int get_parent(int curr) {
  if (parent[curr] == curr) {
    return curr;
  }
  return (parent[curr] = get_parent(parent[curr]));
}
void unionize(int a, int b) {
  a = get_parent(a);
  b = get_parent(b);
  if (a < b) {
    int temp = a;
    a = b;
    b = temp;
  }
  parent[b] = a;
}

void mark_area(int r, int c) {
  std::queue<Point> Q;

  Q.emplace(r, c);
  area[r][c] = ++tot_areas;

  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();
    for (int i = 0; i < 4; ++i) {
      int nr = curr.r + dr[i];
      int nc = curr.c + dc[i];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
          area[nr][nc] != 0 || map[nr][nc] == 'X') {
        continue;
      }
      area[nr][nc] = tot_areas;
      Q.emplace(Point(nr, nc));
    }
  }
}

int main() {
  // fast io
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> R >> C;

  // position of swans
  std::vector<Point> swans;
  // for breaking ice
  std::queue<Entry> Q;

  for (int i = 0; i < R; ++i) {
    // get map input
    std::cin >> map[i];
    for (int j = 0; j < C; ++j) {
      // mark area number
      if (area[i][j] == 0 && map[i][j] != 'X') {
        mark_area(i, j);
      }
      // record water position
      if (map[i][j] != 'X') {
        Q.emplace(Point(i, j), 0);
      }
      // record swans position
      if (map[i][j] == 'L') {
        swans.emplace_back(i, j);
      }
    }
  }

  // swans are in the same water area initially
  if (area[swans[0].r][swans[0].c] == area[swans[1].r][swans[1].c]) {
    std::cout << 0 << "\n";
    return 0;
  }

  // setup union-find
  for (int i = 0; i <= tot_areas; ++i) {
    parent[i] = i;
  }

  // breaking ice and unionizing water
  int day = 0;
  while (!Q.empty()) {
    auto curr_e = Q.front();
    Q.pop();
    if (curr_e.day > day) {
      day = curr_e.day;
      // check equality of swan's area, when day changes
      if (get_parent(area[swans[0].r][swans[0].c]) == 
          get_parent(area[swans[1].r][swans[1].c])) {
        std::cout << day << "\n";
        return 0;
      }
    }
    // find nearby ice
    for (int i = 0; i < 4; ++i) {
      int nr = curr_e.p.r + dr[i];
      int nc = curr_e.p.c + dc[i];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != 'X') {
        continue;
      }
      map[nr][nc] = '.';
      area[nr][nc] = area[curr_e.p.r][curr_e.p.c];
      Q.emplace(Point(nr, nc), curr_e.day + 1);
      // unionize water nearby
      for (int j = 0; j < 4; ++j) {
        int kr = nr + dr[j];
        int kc = nc + dc[j];
        if (kr < 0 || kr >= R || kc < 0 || kc >= C || map[kr][kc] == 'X') {
          continue;
        }
        unionize(area[nr][nc], area[kr][kc]);
      }
    }
  }

  return 0;
}