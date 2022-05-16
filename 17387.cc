#include <iostream>

typedef std::pair<long long, long long> pll;

int ccw(const pll &a, const pll &b, const pll &c)
{
  long long outer = ((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first));
  return outer == 0 ? 0 : (outer < 0 ? -1 : 1);
}

pll points[4];

int main()
{
  std::cin >> points[0].first >> points[0].second
           >> points[1].first >> points[1].second
           >> points[2].first >> points[2].second
           >> points[3].first >> points[3].second;

  int ans1 = ccw(points[0], points[1], points[2]) * ccw(points[0], points[1], points[3]),
      ans2 = ccw(points[2], points[3], points[0]) * ccw(points[2], points[3], points[1]);

  if(ans1 == 0 && ans2 == 0) {
    if(points[0] > points[1]) {
      pll temp = points[0];
      points[0] = points[1];
      points[1] = temp;
    }
    if(points[2] > points[3]) {
      pll temp = points[2];
      points[2] = points[3];
      points[3] = temp;
    }

    if(points[1] >= points[2] && points[0] <= points[3])
      std::cout << 1 << std::endl;
    else
      std::cout << 0 << std::endl;
  } else if(ans1 <= 0 && ans2 <= 0) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}