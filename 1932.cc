#include <iostream>

int n, triangle[501][501], memo[501][501];

int max(int a, int b)
{
  return a < b ? b : a;
}

void solve()
{
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= i; ++j) {
      if(j == 1) 
        memo[i][j] = memo[i - 1][j] + triangle[i][j];
      else if(j == i)
        memo[i][j] = memo[i - 1][j - 1] + triangle[i][j];
      else
        memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j]) + triangle[i][j];
    }
  }
}

int main()
{
  std::cin >> n;

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= i; ++j)
      std::cin >> triangle[i][j];

  solve();

  int max = 0;
  for(int j = 1; j <= n; ++j)
    if(max < memo[n][j])
      max = memo[n][j];
  std::cout << max << std::endl;

  return 0;
}