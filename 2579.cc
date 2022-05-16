#include <iostream>

int max(int a, int b)
{
  return a < b ? b : a;
}

int N, stairs[301], memo[301];

int solve(int stair)
{
  if(stair == 0) return 0;
  if(stair == 1) return stairs[1];
  if(stair == 2) return stairs[1] + stairs[2];
  
  if(memo[stair] != -1)
    return memo[stair];

  memo[stair] = stairs[stair] + max(solve(stair - 2), solve(stair - 3) + stairs[stair - 1]);

  return memo[stair];
}

int main()
{
  std::cin >> N;
  for(int i = 1; i <= N; ++i) {
    std::cin >> stairs[i];
    memo[i] = -1;
  }

  std::cout << solve(N) << std::endl;;
  return 0;
}