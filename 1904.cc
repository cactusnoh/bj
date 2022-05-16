#include <iostream>

/*
n = 1 1
n = 2 00, 00 / 11, 11 -> 00, 11
n = 3 001, 100 / 100, 001, 111, 111 -> 001, 100, 111
n = 4 0000, 0000, 1100, 0011 / 1100, 1001, 1001, 0011, 1111, 1111 -> 0000, 1100, 0011, 1001, 1111
n = 5 00001, 00100, 00100, 10000, 00111, 11100 / 10000, 00001, 11100, 11001, 10011, 00111, 11001, 10011, 11111, 11111
*/

int N, memo[1000001];

int solve(int N)
{
  if(N == 1)
    return 1;
  if(N == 2)
    return 2;

  if(memo[N] != -1)
    return memo[N];
  
  memo[N] = (solve(N - 1) + solve(N - 2)) % 15746;

  return memo[N];
}

int main()
{
  std::cin >> N;

  for(int i = 0; i <= N; ++i)
    memo[i] = -1;

  std::cout << solve(N) << std::endl;
  
  return 0;
}