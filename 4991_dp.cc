#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 0x7fffffff
#define min(a, b) (a < b ? a : b);

struct Pos {
  Pos(int r = 0, int c = 0) : r_(r), c_(c) {}
  int r_; 
  int c_;
};

struct Entry {
  Entry(Pos p, int dist = 0) : r_(p.r_), c_(p.c_), dist_(dist) {}
  Entry(int r = 0, int c = 0, int dist = 0) : r_(r), c_(c), dist_(dist) {}
  int r_;
  int c_;
  int dist_;
};

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int W, H;
char map[21][21];
int dist[11][21][21];
Pos cleaner;
std::vector<Pos> dirty;

void BFS(int idx, int (*dist)[21]) {
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      dist[i][j] = INF;
    }
  }

  std::queue<Entry> PQ;
  PQ.emplace(dirty[idx], 0);
  dist[dirty[idx].r_][dirty[idx].c_] = 0;

  while (!PQ.empty()) {
    auto curr = PQ.front();
    PQ.pop();

    for (int i = 0; i < 4; ++i) {
      int nr = curr.r_ + dr[i];
      int nc = curr.c_ + dc[i];
      int ndist = curr.dist_ + 1;
      if (nr < 0 || nr >= H || nc < 0 || nc >= W ||
          map[nr][nc] == 'x') {
        continue;
      }
      if (ndist < dist[nr][nc]) {
        dist[nr][nc] = ndist;
        PQ.emplace(nr, nc, ndist);
      }
    }
  }
}

/**
 * Returns minimum distance to visit remaining points
 * 
 * @param memo memoization table
 * @param visited visited status
 * @param curr point currently visiting
 */ 
int solve(int (*memo)[11], int visited, int curr) {
  if (memo[visited][curr] != -1) {
    return memo[visited][curr];
  }

  if (visited == (1 << dirty.size()) - 1) {
    // visited all points, return 0
    return 0;
  }

  // For all points not visited, calculate minimum
  int ret = INF;
  for (size_t i = 0; i < dirty.size(); ++i) {
    if ((visited & (1 << i)) == 0) {
      int dist_next = dist[curr][dirty[i].r_][dirty[i].c_];
      ret = min(ret, dist_next + solve(memo, visited | (1 << i), i));
    }
  }
  memo[visited][curr] = ret;

  return ret;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  while (1) {
    // Get W, H
    std::cin >> W >> H;
    if (W == 0 && H == 0) {
      break;
    }

    dirty.clear();                      // empty dirty points
    // Get map
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        std::cin >> map[i][j];
        if (map[i][j] == 'o') {
          cleaner = Pos(i, j);          // save starting position
        } else if (map[i][j] == '*') {
          dirty.emplace_back(i, j);     // save dirty points
        }
      }
    }
    dirty.emplace(dirty.begin(), cleaner); // insert starting position to 0th index

    for (size_t i = 0; i < dirty.size(); ++i) {
      BFS(i, dist[i]); // Get distance from one point to every other point
    }

    // Check if every dirty point is reachable
    bool fail = false;  // true if some dirty point is not reachable
    for (size_t i = 1; i < dirty.size(); ++i) {
      if (dist[0][dirty[i].r_][dirty[i].c_] == INF) {
        fail = true;
      }
    }
    if (fail) {
      std::cout << -1 << "\n";
      continue;
    }
    
    // Dynamic programming
    int memo[2048][11];
    for (int i = 0; i < 2048; ++i) {
      for (int j = 0; j < 11; ++j) {
        memo[i][j] = -1;
      }
    }

    // start from initial cleaner
    std::cout << solve(memo, 1, 0) << "\n";
  }

  return 0;
}