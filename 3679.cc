#include <iostream>
#include <algorithm>

struct Point {
  Point (long long x_ = 0, long long y_ = 0) : x(x_), y(y_) {}
  long long x;
  long long y;
  int order;
};

bool operator<(const Point &lhs, const Point &rhs) {
  if (lhs.y == rhs.y) {
    return lhs.x < rhs.x;
  }
  return lhs.y < rhs.y;
}

int orientation(const Point &a, const Point &b, const Point &c) {
  long long z = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  if (z > 0) {
    return 1;
  }
  if (z < 0) {
    return -1;
  }
  return 0;
}

int C, N;
Point points[2000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> C;

  for (int tc = 1; tc <= C; ++tc) {
    std::cin >> N;

    Point p0(10001, 10001);
    for (int i = 0; i < N; ++i) {
      std::cin >> points[i].x >> points[i].y;
      points[i].order = i;
      if (points[i] < p0) {
        p0 = points[i];
      }
    }

    std::sort(points, points + N, [&p0] (const Point &lhs, const Point &rhs) {
      int o = orientation(p0, lhs, rhs);
      if (o == 0) {
        return (p0.x - lhs.x) * (p0.x - lhs.x) + (p0.y - lhs.y) * (p0.y - lhs.y) <
               (p0.x - rhs.x) * (p0.x - rhs.x) + (p0.y - rhs.y) * (p0.y - rhs.y);
      }
      return o > 0;
    });

    int i = N - 1;
    while (orientation(p0, points[N - 1], points[i]) == 0) {
      --i;
    }

    std::sort(points + i + 1, points + N, [&p0] (const Point &lhs, const Point &rhs) {
      return (p0.x - lhs.x) * (p0.x - lhs.x) + (p0.y - lhs.y) * (p0.y - lhs.y) >
             (p0.x - rhs.x) * (p0.x - rhs.x) + (p0.y - rhs.y) * (p0.y - rhs.y);
    });

    for (int i = 0; i < N; ++i) {
      std::cout << points[i].order << " ";
    }
    std::cout << "\n";
  }

  return 0;
}