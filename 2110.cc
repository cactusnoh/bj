#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int N, C, temp;
  int max_dist, ans;
  std::vector<int> houses;

  std::cin >> N >> C;
  for(size_t i = 0; i < N; i++) {
    std::cin >> temp;
    houses.push_back(temp);
  }
  std::sort(houses.begin(), houses.end());
  max_dist = houses.back() - houses.front();

  int begin = 1, end = max_dist;
  while(end >= begin) {
    int mid = begin + (end - begin) / 2;
    int prev_house = houses.front();
    int possible = 1;

    for(size_t i = 1; i < N; i++) {
      if(houses[i] - prev_house < mid)
        continue;
      prev_house = houses[i];
      //std::cout << mid << " " << prev_house << std::endl;
      possible++;
    }

    if(possible >= C) {
      ans = mid;
      begin = mid + 1;
    } else
      end = mid - 1;
  }

  std::cout << ans << std::endl;

  return 0;
}