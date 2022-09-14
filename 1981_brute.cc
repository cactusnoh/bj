#include <iostream>
#include <queue>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

inline int abs(int a) {
  return a < 0 ? -a : a;
}

struct Pos {
  Pos (int r = 0, int c = 0) : r_(r), c_(c) {}
  int r_;
  int c_;
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int N;
int map[100][100];

/* Use BFS to figure out whether there is a path from (0,0) to (n-1,n-1) */
bool BFS(int min_num, int max_num) {
  if (map[0][0] < min_num || map[0][0] > max_num) {
    return false;
  }

  std::queue<Pos> Q;
  bool visited[100][100] = {false};

  Q.emplace(0, 0);
  visited[0][0] = true;
  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();
    for (int i = 0; i < 4; ++i) {
      int nr = curr.r_ + dr[i];
      int nc = curr.c_ + dc[i];
      if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || 
          map[nr][nc] > max_num || map[nr][nc] < min_num) {
        continue;
      }
      Q.emplace(nr, nc);
      visited[nr][nc] = true;
    }
  }

  return visited[N - 1][N - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int global_max = 0;
  int global_min = 0x7fffffff;

  // Get input
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> map[i][j];
      global_max = max(global_max, map[i][j]);
      global_min = min(global_min, map[i][j]);
    }
  }

  // For all possible differences, minimum, maximum number, try to find path
  for (int diff = abs(map[0][0] - map[N - 1][N - 1]); diff <= (global_max - global_min); ++diff) {
    for (int min_num = global_min; min_num <= 200 - diff; ++min_num) {
      int max_num = min_num + diff;
      if (BFS(min_num, max_num)) {
        std::cout << diff << "\n";
        return 0;
      }
    }
  }

  return 0;
}