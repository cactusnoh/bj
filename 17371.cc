#include <iostream>

typedef std::pair<int, int> pii;

int N;
pii points[1000];
int min_avg = 2147000000;
pii min_point;

inline int dist_square(const pii &lhs, const pii &rhs)
{
  return (lhs.first - rhs.first) * (lhs.first - rhs.first) 
       + (lhs.second - rhs.second) * (lhs.second - rhs.second);
}

int main()
{
  std::cin >> N;

  for(int i = 0; i < N; ++i)
    std::cin >> points[i].first >> points[i].second;
  
  for(int i = 0; i < N; ++i) {
    int max_dist = 0;
    for(int j = 0; j < N; ++j) {
      int temp = dist_square(points[i], points[j]);
      if(temp > max_dist)
        max_dist = temp;
    }
    if(max_dist < min_avg) {
      min_avg = max_dist;
      min_point = points[i];
    }
  }

  std::cout << min_point.first << " " << min_point.second << "\n";

  return 0;
}