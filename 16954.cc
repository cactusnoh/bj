#include <iostream>
#include <queue>

#define min(a, b) (a < b ? a : b)

struct Entry {
  Entry(int _day = 0, int _r = 0, int _c = 0) : day(_day), r(_r), c(_c) {}
  int day;
  int r;
  int c;
};

char map[9][9][9];

int dr[9] = {-1, 0, 1, 0, 0, -1, -1, 1, 1};
int dc[9] = {0, 1, 0, -1, 0, -1, 1, 1, -1};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // get map input
  for (int i = 0; i < 8; ++i) {
    std::cin >> map[0][i];
  }

  // for days 1 ~ 8, lower walls and make map
  for (int day = 1; day <= 8; ++day) {
    for (int c = 0; c < 8; ++c) {
      map[day][0][c] = '.';
    }
    for (int r = 1; r < 8; ++r) {
      for (int c = 0; c < 8; ++c) {
        map[day][r][c] = map[day - 1][r - 1][c];
      }
    }
  }

  // BFS
  std::queue<Entry> Q;
  bool visited[9][8][8] = {false};
  bool reached = false; // true if WookJe reached (0, 7)

  Q.emplace(0, 7, 0);
  visited[0][7][0] = true;
  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();

    if (curr.r == 0 && curr.c == 7) {
      reached = true; // reached destination; success!
      break;
    }

    for (int i = 0; i < 9; ++i) {
      int nday = min(8, curr.day + 1);
      int nr = curr.r + dr[i];
      int nc = curr.c + dc[i];
      if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8 ||
          map[nday][nr][nc] != '.' || map[curr.day][nr][nc] != '.' ||
          visited[nday][nr][nc]) {
        continue;
      }
      Q.emplace(nday, nr, nc);
      visited[nday][nr][nc] = true;
    }
  }

  std::cout << (reached ? 1 : 0) << "\n";

  return 0;
}