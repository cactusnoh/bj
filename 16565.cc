#include <iostream>

#define DIVISOR 10007

int N, memo[53][53], fact_memo[53];

int power(int a, int b)
{
  if(b == 0)
    return 1;
  int temp = power(a, b >> 1);
  temp = (temp * temp) % DIVISOR;
  return (b & 1 ? (temp * a) % DIVISOR : temp);
}

int factorial(int n)
{
  if(n <= 1)
    return 1;
  if(fact_memo[n] != -1)
    return fact_memo[n];
  fact_memo[n] = (n * factorial(n - 1)) % DIVISOR;
  return fact_memo[n];
}

int comb(int n, int r)
{
  if(r == 0)
    return 1;
  return (factorial(n) * power((factorial(r) * factorial(n - r)) % DIVISOR, DIVISOR - 2)) % DIVISOR;
}

int solve(int n, int r)
{
  if(memo[n][r] != -1)
    return memo[n][r];
  
  memo[n][r] = 0;
  for(int i = 1; i <= r / 4; ++i)
    memo[n][r] = (memo[n][r] + comb(n / 4, i) * (comb(n - 4 * i, r - 4 * i) - solve(n - 4 * i, r - 4 * i))) % DIVISOR;
  return memo[n][r];
}

int main()
{
  for(int i = 0; i <= 52; ++i)
    fact_memo[i] = -1;
  for(int i = 4; i <= 52; ++i)
    for(int j = 4; j <= 52; ++j)
      memo[i][j] = -1;

  std::cin >> N;

  std::cout << solve(52, N) << std::endl;

  return 0;
}