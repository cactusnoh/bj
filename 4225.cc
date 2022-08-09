#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
  Point (long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
  long long x, y;
};

template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T max(T a, T b) {
  return a < b ? b : a;
}

inline long long outer_product(const Point &a, const Point &b, const Point &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

/**
 * @brief check orientation of three points
 * @details
 * | (    i    ) (    j    ) (    k    ) |
 * | (b.x - a.x) (b.y - a.y) (    0    ) | = k * {(b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)}
 * | (c.x - a.x) (c.y - a.y) (    0    ) |
 * @return 
 * -1: clockwise
 * 0: one line
 * 1: counter clockwise
 */
int ccw(const Point &a, const Point &b, const Point &c) {
  long long ret = outer_product(a, b, c);
  return (ret == 0 ? 0 : (ret < 0 ? -1 : 1));
}

long long get_dist(const Point &lhs, const Point &rhs) {
  return (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y);
}

int N;
Point points[100];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int tc = 1;
  while (true) {
    std::cin >> N;

    if (N == 0) {
      break;
    }

    // get input and find out base
    Point base(0, 2147000000);
    for (int i = 0; i < N; ++i) {
      std::cin >> points[i].x >> points[i].y;
      if (points[i].y < base.y) {
        base = points[i];
      }
    }

    // sort points by degree & distance from base
    std::sort(points, points + N, [&] (const Point &lhs, const Point &rhs) {
      int orientation = ccw(base, lhs, rhs);
      return orientation > 0 || (orientation == 0 && get_dist(lhs, base) < get_dist(rhs, base));
    });

    // convex hull
    std::vector<Point> convex_hull;
    for (auto i = 0; i < N; ++i) {
      size_t sz = convex_hull.size();
      // beware of while!
      while (sz >= 2 && ccw(convex_hull[sz - 2], convex_hull[sz - 1], points[i]) <= 0) {
        --sz;
        convex_hull.pop_back();
      }
      convex_hull.emplace_back(points[i]);
    }

    // get minimum of maximum distance from a line to some point in convex hull
    double min_of_dist = 1e10;
    for (auto i = 0; i < convex_hull.size(); ++i) {
      double max_dist = 0.0;
      Point &s = convex_hull[i];
      Point &e = convex_hull[(i + 1) % convex_hull.size()];
      for (const auto &p : convex_hull) {
        max_dist = max(max_dist, abs(outer_product(s, e, p)) / sqrt(get_dist(s, e)));
      }
      min_of_dist = min(min_of_dist, max_dist);
    }
    
    std::cout << std::fixed << std::setprecision(2) << "Case " << tc << ": " << ceil(min_of_dist * 100) / 100.0 << "\n";
    ++tc;
  }

  return 0;
}