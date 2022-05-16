#include <iostream>

int max(int a, int b)
{
  return a > b ? a : b;
}

int N;
int seq[100001], memo[100001];

int main()
{
  std::cin >> N;

  for(int i = 1; i <= N; ++i)
    std::cin >> seq[i];

  for(int i = 1; i <= N; ++i)
    memo[i] = max(seq[i - 1], memo[i - 1]) + seq[i];

  int sum = -987654321;
  for(int i = 1; i <= N; ++i) {
    if(sum < max(seq[i], memo[i]))
      sum = max(seq[i], memo[i]);
  }

  std::cout << sum << std::endl;

  return 0;
}