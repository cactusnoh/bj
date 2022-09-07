#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using Entry = std::pair<int, int>;

inline int min(int a, int b) {
  return a < b ? a : b;
}
inline int max(int a, int b) {
  return a < b ? b : a;
}

int N;
int R, C;
char map[101][101];

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, 1, -1, 0};
bool visited[101][101];

bool pull_down(int r, int c) {
  std::vector<Entry> cluster; // all positions of the cluster
  int max_r = 0; // lowest row of cluster
  int bottom_of_col[101] = {0}; // lowest row of each column

  // determine cluster
  std::queue<Entry> Q;
  Q.emplace(r, c);
  cluster.emplace_back(r, c);
  visited[r][c] = true;
  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();

    max_r = max(curr.first, max_r);
    bottom_of_col[curr.second] = max(bottom_of_col[curr.second], curr.first);

    for (int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i];
      int nc = curr.second + dc[i];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
          visited[nr][nc] || map[nr][nc] == '.') {
        continue;
      }
      visited[nr][nc] = true;
      cluster.emplace_back(nr, nc);
      Q.emplace(nr, nc);
    }
  }

  // return false if cluster is not floating
  if (max_r == R - 1) {
    return false;
  }

  // determine how much to pull down
  int pull = 0x7fffffff; 
  for (auto c = 0; c < C; ++c) {
    if (bottom_of_col[c] == 0) {
      continue;
    }
    int local_pull = 1;
    int r = bottom_of_col[c];
    while (r + local_pull < R && map[r + local_pull][c] != 'x') {
      ++local_pull;
    }
    pull = min(local_pull - 1, pull);
  }

  // pull down cluster
  for (const auto &p : cluster) {
    map[p.first][p.second] = '.';
  }
  for (const auto &p : cluster) {
    map[p.first + pull][p.second] = 'x';
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> R >> C;
  for (int r = 0; r < R; ++r) {
    std::cin >> map[r];
  }

  std::cin >> N;
  int r, c;
  for (int i = 0; i < N; ++i) {
    // reset visited
    memset(visited, 0, sizeof(visited));
    // get input
    std::cin >> r;
    r = R - r;
    // break mineral
    if ((i & 1) == 0) {
      for (c = 0; c < C; ++c) {
        if (map[r][c] == 'x') {
          map[r][c] = '.';
          break;
        }
      }
    } else {
      for (c = C - 1; c >= 0; --c) {
        if (map[r][c] == 'x') {
          map[r][c] = '.';
          break;
        }
      }
    }
    // pull down floating mineral cluster
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 <= nr && nr < R && 0 <= nc && nc < C &&
          map[nr][nc] == 'x' && !visited[nr][nc] &&
          pull_down(nr, nc)) {
        break;
      }
    }
  }

  for (int r = 0; r < R; ++r) {
    std::cout << map[r] << "\n";
  }

  return 0;
}