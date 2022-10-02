#include <iostream>
#include <queue>
#include <vector>

struct Entry {
  Entry(int _r = 0, int _c = 0) : r(_r), c(_c) {}
  int r;
  int c;
};

int N;
bool map[2001][2001];
bool visited[2001][2001];

std::vector<Entry> entry_point;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

/**
 * @brief BFS to mark all overlapping lines
 * 
 * @param r entry point row index
 * @param c entry point column index
 */
void BFS(int r, int c) {
  std::queue<Entry> Q;

  Q.emplace(r, c);
  visited[r][c] = true;

  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();
    
    for (int dir = 0; dir < 4; ++dir) {
      int nr = curr.r + dr[dir];
      int nc = curr.c + dc[dir];
      if (nr < 0 || nr > 2000 || nc < 0 || nc > 2000 ||
          visited[nr][nc] || !map[nr][nc]) {
        continue;
      }
      Q.emplace(nr, nc);
      visited[nr][nc] = true;
    }
  }
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  /*
   * Make the map two times bigger and mark all points of rectangles.
   * Why two times bigger? To correctly use BFS on points that are 
   * not connected as a line but are next to each other.
   * Think about squares (0,0)~(1,1) and (0,2)~(1,3)
   */
  int x1, y1, x2, y2;
  for (int i = 0; i < N; ++i) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    x1 = (x1 + 500) << 1;
    y1 = (y1 + 500) << 1;
    x2 = (x2 + 500) << 1;
    y2 = (y2 + 500) << 1;
    entry_point.emplace_back(x1, y1);
    for (int r = x1; r <= x2; ++r) {
      map[r][y1] = true;
      map[r][y2] = true;
    }
    for (int c = y1; c <= y2; ++c) {
      map[x1][c] = true;
      map[x2][c] = true;
    }
  }

  /* 
   * For all rectangles, if the entry point is not visited,
   * it means we have a separate structure of possibly overlapping rectangles
   */
  int num_overlaps = 0;
  for (const auto &p : entry_point) {
    if (map[p.r][p.c] && !visited[p.r][p.c]) {
      ++num_overlaps;
      BFS(p.r, p.c);
    }
  }

  std::cout << num_overlaps - (map[1000][1000] ? 1 : 0) << "\n";

  return 0;
}