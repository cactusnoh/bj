#include <iostream>
#include <algorithm>

int N, times[1000], ans;

int main()
{
  std::cin >> N;

  for(int i = 0; i < N; ++i)
    std::cin >> times[i];
  std::sort(times, times + N);

  int sum = 0;
  for(int i = 0; i < N; ++i) {
    sum += times[i];
    ans += sum;
  }

  std::cout << ans << std::endl;

  return 0;
}