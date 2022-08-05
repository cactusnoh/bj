#include <iostream>
#include <algorithm>

#define INF 2'147'000'000

using pii = std::pair<int, int>;

struct cmp_y {
  bool operator()(const pii &a, const pii &b) const {
    return a.second < b.second;
  }
};

inline int abs(int a) {
  return a < 0 ? -a : a;
}
inline int min(int a, int b) {
  return a < b ? a : b;
}
inline int get_dist(const pii &a, const pii &b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int N;
pii points[100'000];
pii temp[100'000];

int min_dist(int l, int r) {
  if (r - l <= 3) {
    int ret = INF;
    for (int i = l; i < r; ++i) {
      for (int j = i + 1; j < r; ++j) {
        ret = min(ret, get_dist(points[i], points[j]));
      }
    }
    std::sort(points + l, points + r, cmp_y());
    return ret;
  }

  int middle = l + ((r - l) >> 1);
  int mid_x = points[middle].first; // need to save this...!

  int left_ret = min_dist(l, middle);
  int right_ret = min_dist(middle, r);
  int ret = min(left_ret, right_ret);

  std::merge(points + l, points + middle, points + middle, points + r, temp, cmp_y());
  std::copy(temp, temp + r - l, points + l);

  int temp_size = 0;
  for (int i = l; i < r; ++i) {
    if ((points[i].first - mid_x) * (points[i].first - mid_x) >= ret) {
      continue;
    }
    for (int j = temp_size - 1; j >= 0 && (points[i].second - temp[j].second) * (points[i].second - temp[j].second) < ret; --j) {
      ret = min(ret, get_dist(points[i], temp[j]));
    }
    temp[temp_size++] = points[i];
  }

  return ret;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    std::cin >> points[i].first >> points[i].second;
  }
  std::sort(points, points + N);

  std::cout << min_dist(0, N) << "\n";

  return 0;
}