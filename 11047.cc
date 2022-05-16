#include <iostream>

int N, K, cnt;
int coins[11];

int main()
{
  std::cin >> N >> K;
  for(int i = 1; i <= N; ++i)
    std::cin >> coins[i];
  
  for(int i = N; i >= 1; --i) {
    if(K / coins[i] != 0) {
      cnt += K / coins[i];
      K %= coins[i];
    }
  }

  std::cout << cnt << std::endl;

  return 0;
}