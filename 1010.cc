#include <iostream>

int T, N, M;
int memo[30][30];

int getPossible(int n, int m)
{
  if(n == 1)
    return m;
  if(memo[n][m])
    return memo[n][m];
  for(int i = 1; i <= m - n + 1; ++i)
    memo[n][m] += getPossible(n - 1, m - i);
  return memo[n][m];
}

int main()
{
  std::cin >> T;
  for(int i = 0; i < T; ++i) {
    std::cin >> N >> M;
    std::cout << getPossible(N, M) << std::endl;
  }

  return 0;
}