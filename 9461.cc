#include <iostream>

long long memo[101];
int T, N;

long long solve(int N)
{
  if(N <= 3)
    return 1;

  if(memo[N] != -1)
    return memo[N];

  memo[N] = solve(N - 2) + solve(N - 3);
  return memo[N];
}

int main()
{
  for(int i = 0; i < 101; ++i)
    memo[i] = -1;

  std::cin >> T;
  for(int t = 0; t < T; ++t) {
    std::cin >> N;
    std::cout << solve(N) << std::endl;
  }
  
  return 0;
}