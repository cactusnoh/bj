#include <iostream>

int min(int a, int b)
{
  return a < b ? a : b;
}

int N;
int memo[1000001];

int solve(int N)
{
  if(N == 1) return 0;

  if(memo[N] != -1) return memo[N];

  int temp = 987654321;
  if(N % 3 == 0)
    temp = 1 + solve(N / 3);
  if(N % 2 == 0)
    temp = min(temp, 1 + solve(N / 2));

  memo[N] = min(temp, 1 + solve(N - 1));

  return memo[N];
}

int main()
{
  for(int i = 2; i < 1000001; ++i) memo[i] = -1;

  std::cin >> N;
  std::cout << solve(N) << std::endl;

  return 0;
}