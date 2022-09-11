#include <iostream>
#include <queue>

#define min(a, b) (a < b ? a : b);
#define INF 0x7fffffff

using pos = std::pair<int, int>;

/**
 * Entry for priority queue
 * Need to define operator> for min-heap
 */ 
struct Entry {
  Entry(int r = 0, int c = 0, int dir = 0, int dist = 0) : p_(r, c), dir_(dir), dist_(dist) {}
  pos p_;
  int dir_;
  int dist_;
};
bool operator>(const Entry &lhs, const Entry &rhs) {
  return lhs.dist_ > rhs.dist_;
}

// Directions
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int W, H;                   // width, height
char map[101][101];         // map
int min_dist[101][101][4];  // stores minimum dist to some position (dijkstra)

std::vector<pos> C;         // stores starting, ending point

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // Get input
  std::cin >> W >> H;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == 'C') {
        C.emplace_back(i, j);
      }
      for (int k = 0; k < 4; ++k) {
        min_dist[i][j][k] = INF; // initialize distance to infinite
      }
    }
  }

  // Do dijkstra
  std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> PQ;
  for (int i = 0; i < 4; ++i) {
    // initial entry for every direction
    PQ.emplace(C[0].first, C[0].second, i, 0);
    min_dist[C[0].first][C[0].second][i] = 0;
  }
  while (!PQ.empty()) {
    auto curr = PQ.top();
    PQ.pop();

    int r = curr.p_.first;  // current r
    int c = curr.p_.second; // current c

    if (min_dist[r][c][curr.dir_] < curr.dist_) {
      continue; // already visited
    }

    // Don't change direction
    {
      int ndir = curr.dir_;
      int ndist = curr.dist_ + 0;
      int nr = r + dr[ndir];
      int nc = c + dc[ndir];
      if (0 <= nr && nr < H && 0 <= nc && nc < W && 
          map[nr][nc] != '*' && ndist < min_dist[nr][nc][ndir]) {
        PQ.emplace(nr, nc, ndir, ndist);
        min_dist[nr][nc][ndir] = ndist;
      }
    }
    // Change direction 90 degrees
    {
      int ndir = (curr.dir_ + 1) % 4;
      int ndist = curr.dist_ + 1;
      int nr = r + dr[ndir];
      int nc = c + dc[ndir];
      if (0 <= nr && nr < H && 0 <= nc && nc < W && 
          map[nr][nc] != '*' && ndist < min_dist[nr][nc][ndir]) {
        PQ.emplace(nr, nc, ndir, ndist);
        min_dist[nr][nc][ndir] = ndist;
      }
    }
    // Change direction 270 degrees
    {
      int ndir = (curr.dir_ - 1 + 4) % 4;
      int ndist = curr.dist_ + 1;
      int nr = r + dr[ndir];
      int nc = c + dc[ndir];
      if (0 <= nr && nr < H && 0 <= nc && nc < W && 
          map[nr][nc] != '*' && ndist < min_dist[nr][nc][ndir]) {
        PQ.emplace(nr, nc, ndir, ndist);
        min_dist[nr][nc][ndir] = ndist;
      }
    }
  }

  // Get the minimum distance to destination; consider all directions
  int answer = 0x7fffffff;
  for (int i = 0; i < 4; ++i) {
    answer = min(answer, min_dist[C[1].first][C[1].second][i]);
  }
  std::cout << answer << std::endl;

  return 0;
}