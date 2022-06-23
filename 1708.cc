#include <iostream>
#include <algorithm>
#include <vector>

struct Point {
  long long x;
  long long y;
};

long long CCW(Point a, Point b, Point c) { 
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int N;
Point points[100'000];

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    std::cin >> points[i].x >> points[i].y;
  }

  Point p0 = points[0];
  for (int i = 0; i < N; ++i) {
    if (points[i].y < p0.y ||
        (points[i].y == p0.y && points[i].x < p0.x)) {
      p0 = points[i];
    }
  }

  std::sort(points, points + N, [&p0] (const Point &lhs, const Point &rhs) {
              long long o = CCW(p0, lhs, rhs);
              if (o == 0) {
                return (lhs.x - p0.x) * (lhs.x - p0.x) + (lhs.y - p0.y) * (lhs.y - p0.y) <
                       (rhs.x - p0.x) * (rhs.x - p0.x) + (rhs.y - p0.y) * (rhs.y - p0.y);
              }
              return o > 0;
            });
  
  std::vector<Point> convex_hull;
  for (int i = 0; i < N; ++i) {
    size_t size;
    while ((size = convex_hull.size()) >= 2 && CCW(convex_hull[size - 2], convex_hull[size - 1], points[i]) <= 0) {
      convex_hull.pop_back();
    }
    convex_hull.push_back(points[i]);
  }

  std::cout << convex_hull.size() << "\n";

  return 0;
}