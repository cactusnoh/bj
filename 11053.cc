#include <iostream>

int N, seq[1001], memo[1001];

int solve(int seen)
{
  if(seen == 1)
    return 1;

  if(memo[seen] != -1)
    return memo[seen];

  int max = 0;
  for(int i = 1; i < seen; ++i)
    if(seq[i] < seq[seen] && max < solve(i))
      max = solve(i);

  memo[seen] = max + 1;

  return memo[seen];
}

int main()
{
  std::cin >> N;
  for(int i = 1; i <= N; ++i) {
    memo[i] = -1;
    std::cin >> seq[i];
  }

  int max = 0;
  for(int i = 1; i <= N; ++i)
    if(max < solve(i))
      max = solve(i);
  std::cout << max << std::endl;

  return 0;
}