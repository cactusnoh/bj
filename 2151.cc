#include <iostream>
#include <vector>
#include <deque>

#define min(a, b) (a < b ? a : b)

#define INF 0x7fffffff

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct Entry {
  Entry(int _r = 0, int _c = 0, int _dir = 0) 
    : r(_r), c(_c), dir(_dir) {}
  int r;
  int c;
  int dir;
};

int N;
char map[51][51];
std::vector<Entry> door;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // Get input
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> map[i];
  }

  // Get door positions
  for (int i = 0 ; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (map[i][j] == '#') {
        door.emplace_back(i, j);
      }
    }
  }

  // minimum required mirrors to reach a point
  int min_mirrors[51][51][4];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < 4; ++k) {
        min_mirrors[i][j][k] = INF;
      }
    }
  }

  // 0-1 BFS
  std::deque<Entry> DQ;
  DQ.clear();
  for (int dir = 0; dir < 4; ++dir) {
    DQ.emplace_back(door[0].r, door[0].c, dir);
    min_mirrors[door[0].r][door[0].c][dir] = 0;
  }

  while (!DQ.empty()) {
    auto curr = DQ.front();
    DQ.pop_front();
    // go straight
    {
      int ndir = curr.dir;
      int nr = curr.r + dr[ndir];
      int nc = curr.c + dc[ndir];
      int nmirror = min_mirrors[curr.r][curr.c][curr.dir];
      if (0 <= nr && nr < N && 0 <= nc && nc < N &&
          map[nr][nc] != '*' && 
          nmirror < min_mirrors[nr][nc][ndir]) {
        min_mirrors[nr][nc][ndir] = nmirror;
        DQ.emplace_front(nr, nc, ndir);
      }
    }
    // turn 90 degrees
    if (map[curr.r][curr.c] == '!') {
      int ndir = (curr.dir + 1) % 4;
      int nr = curr.r + dr[ndir];
      int nc = curr.c + dc[ndir];
      int nmirror = min_mirrors[curr.r][curr.c][curr.dir] + 1;
      if (0 <= nr && nr < N && 0 <= nc && nc < N && 
          map[nr][nc] != '*' && 
          nmirror < min_mirrors[nr][nc][ndir]) {
        min_mirrors[nr][nc][ndir] = nmirror;
        DQ.emplace_back(nr, nc, ndir);
      }
    }
    // turn 270 degrees
    if (map[curr.r][curr.c] == '!') {
      int ndir = (curr.dir + 3) % 4;
      int nr = curr.r + dr[ndir];
      int nc = curr.c + dc[ndir];
      int nmirror = min_mirrors[curr.r][curr.c][curr.dir] + 1;
      if (0 <= nr && nr < N && 0 <= nc && nc < N && 
          map[nr][nc] != '*' && 
          nmirror < min_mirrors[nr][nc][ndir]) {
        min_mirrors[nr][nc][ndir] = nmirror;
        DQ.emplace_back(nr, nc, ndir);
      }
    }
  }

  // get minimum
  int ret = 0x7fffffff;
  for (int dir = 0; dir < 4; ++dir) {
    ret = min(ret, min_mirrors[door[1].r][door[1].c][dir]);
  }
  std::cout << ret << "\n";

  return 0;
}