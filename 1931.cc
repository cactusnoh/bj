#include <iostream>
#include <utility>
#include <algorithm>

int N, cnt;
std::pair<int, int> times[100001];

int main()
{
  std::cin >> N;

  for(int i = 1; i <= N; ++i)
    std::cin >> times[i].second >> times[i].first;
  
  std::sort(times + 1, times + N + 1);

  int lastT = 0;
  for(int i = 1; i <= N; ++i) {
    if(lastT <= times[i].second) {
      lastT = times[i].first;
      ++cnt;
    }
  }

  std::cout << cnt << std::endl;

  return 0;
}