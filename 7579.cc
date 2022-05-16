#include <iostream>

int max(int a, int b)
{
  return a < b ? b : a;
}

int N, M;
int size[101], cost[101], memo[10001];

int main()
{
  std::cin >> N >> M;

  for(int i = 1; i <= N; ++i)
    std::cin >> size[i];
  for(int i = 1; i <= N; ++i)
    std::cin >> cost[i];

  for(int i = 1; i <= N; ++i) {
    for(int j = 10000; j >= 1; --j) {
      if(cost[i] > j) continue;
      memo[j] = max(memo[j], memo[j - cost[i]] + size[i]);
    }
  }

  for(int i = 1; i <= 10000; ++i) {
    if(memo[i] >= M) {
      std::cout << i << std::endl;
      return 0;
    }
  }

  return 0;
}