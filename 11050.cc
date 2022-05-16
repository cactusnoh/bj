#include <iostream>

int N, K;
int memo[11];

int factorial(int n)
{
  if(n <= 1)
    return 1;
  if(memo[n])
    return memo[n];
  memo[n] = n * factorial(n - 1);
  return memo[n];
}

int main()
{
  std::cin >> N >> K;
  std::cout << factorial(N) / (factorial(N - K) * factorial(K)) << std::endl;

  return 0;
}