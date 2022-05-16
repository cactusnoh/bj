#include <iostream>

int n, k;
int coins[101], memo[10001];

int main()
{
  std::cin >> n >> k;
  for(int i = 1; i <= n; ++i)
    std::cin >> coins[i];
  
  memo[0] = 1;
  for(int i = 1; i <= n; ++i) {    
    for(int j = coins[i]; j <= k; ++j) {
      memo[j] += memo[j - coins[i]];
    }
  }

  std::cout << memo[k] << std::endl;

  return 0;
}