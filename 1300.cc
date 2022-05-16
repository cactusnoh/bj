#include <iostream>

int main()
{
  int N, k;

  std::cin >> N >> k;

  int beg = 1, end = k;
  int ans;

  while(end >= beg) {
    int mid = beg + (end - beg) / 2;
    int lower = 0, upper = 0, cnt = 0;
    for(int i = 1; i <= N; i++)
      cnt += std::min<int>(N, mid / i);
    if(cnt >= k) {
      ans = mid;
      end = mid - 1;
    } else
      beg = mid + 1;
  }

  std::cout << ans << std::endl;
  return 0;
}