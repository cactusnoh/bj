#include <iostream>
#include <queue>
#include <vector>

#define INF 0x7fffffff

using pos = std::pair<int, int>;

inline int min(int a, int b) {
  return a < b ? a : b;
}

struct Entry {
  Entry(pos _p, int _dist = 0) : p(_p), dist(_dist) {}
  pos p;
  int dist;
};

bool operator>(const Entry &lhs, const Entry &rhs) {
  return lhs.dist > rhs.dist;
}

int TC;
int H, W;

char map[102][102];
int dist[3][102][102];
std::vector<pos> person;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, 1, -1, 0};

void dijkstra(int (*dist)[102], pos start) {
  // initialize dist
  for (int i = 0; i <= H + 1; ++i) {
    for (int j = 0; j <= W + 1; ++j) {
      dist[i][j] = INF;
    }
  }
  // do dijkstra
  std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> PQ;
  PQ.emplace(start, 0);
  dist[start.first][start.second] = 0;
  while (!PQ.empty()) {
    auto curr = PQ.top();
    PQ.pop();

    int h = curr.p.first;
    int w = curr.p.second;

    if (curr.dist > dist[h][w]) {
      continue;
    }

    for (int i = 0; i < 4; ++i) {
      int nh = h + dr[i];
      int nw = w + dc[i];
      if (nh < 0 || nh >= H + 2 || nw < 0 || nw >= W + 2 ||
          map[nh][nw] == '*') {
        continue;
      }
      int ndist = curr.dist + (map[nh][nw] == '#' ? 1 : 0);
      if (ndist < dist[nh][nw]) {
        dist[nh][nw] = ndist;
        PQ.emplace(pos(nh, nw), ndist);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> TC;

  for (int tc = 1; tc <= TC; ++tc) {
    person.clear(); // Clear starting positions of people
    person.emplace_back(0, 0); // Sang-Keun starts at position (0, 0)
    std::cin >> H >> W; // Get jail height(H) and width(W)
    // Set border outside the jail to '.'
    for (int h = 0; h <= H; ++h) {
      map[h][0] = '.';
      map[h][W + 1] = '.';
    }
    for (int w = 0; w <= W; ++w) {
      map[0][w] = '.';
      map[H + 1][w] = '.';
    }
    // Get jail info
    for (int h = 1; h <= H; ++h) {
      for (int w = 1; w <= W; ++w) {
        std::cin >> map[h][w];
        if (map[h][w] == '$') {
          // add starting position of this prisoner
          person.emplace_back(h, w);
        }
      }
    }
    // Execute dijkstra for all people
    for (auto i = 0; i < 3; ++i) {
      dijkstra(dist[i], person[i]);
    }
    // Sum up all dist and find minimum sum
    int min_sum = INF;
    for (int h = 0; h <= H + 1; ++h) {
      for (int w = 0; w <= W + 1; ++w) {
        int local_sum = (map[h][w] == '#' ? -2 : 0); // subtract duplicate lock count
        for (auto i = 0; i < 3; ++i) {
          local_sum += dist[i][h][w];
        }
        min_sum = min(min_sum, local_sum); // update minimum lock count
      }
    }
    std::cout << min_sum << "\n";
  }

  return 0;
}