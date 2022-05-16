#include <iostream>

int max(int a, int b)
{
  return a < b ? b : a;
}

int n, wines[10001], memo[10001];

int solve(int seen)
{
  if(seen == 1)
    return wines[1];
  
  if(memo[seen] != -1)
    return memo[seen];

  memo[seen] = max(solve(seen - 1), solve(seen - 3) + wines[seen - 1] + wines[seen]);
  memo[seen] = max(memo[seen], solve(seen - 2) + wines[seen]);

  return memo[seen];
}

int main()
{
  std::cin >> n;
  for(int i = 1; i <= n; ++i) {
    memo[i] = -1;
    std::cin >> wines[i];
  }

  std::cout << solve(n) << std::endl;

  return 0;
}