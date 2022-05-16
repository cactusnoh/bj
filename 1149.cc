#include <iostream>

#define R 0
#define G 1
#define B 2

int N, cost[1001][3];
int memo[1001][3];

int min(int a, int b)
{
  return a < b ? a : b;
}

void solve()
{
  for(int i = 1; i <= N; ++i) {
    memo[i][R] = min(memo[i - 1][G] + cost[i][R], memo[i - 1][B] + cost[i][R]);
    memo[i][G] = min(memo[i - 1][R] + cost[i][G], memo[i - 1][B] + cost[i][G]);
    memo[i][B] = min(memo[i - 1][G] + cost[i][B], memo[i - 1][R] + cost[i][B]);
  }
}

int main()
{
  for(int i = 1; i <= 1001; ++i)
    memo[i][R] = memo[i][G] = memo[i][B] = -1;

  std::cin >> N;
  for(int i = 1; i <= N; ++i)
    std::cin >> cost[i][R] >> cost[i][G] >> cost[i][B]; 

  solve();

  std::cout << min(memo[N][R], min(memo[N][G], memo[N][B])) << std::endl;

  return 0;
}