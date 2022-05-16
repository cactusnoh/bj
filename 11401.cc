#include <iostream>

#define DIVISOR 1000000007

long long power(long long n, long long k)
{
  long long res = 1;
  while(k > 0) {
    if(k & 1)
      res = res * n % DIVISOR;
    n = n * n % DIVISOR;
    k = k >> 1;
  }
  return res;
}

int N, K;
long long fact[4000001];

int main()
{
  std::cin >> N >> K;

  fact[0] = fact[1] = 1;
  for(int i = 2; i <= N; ++i)
    fact[i] = (fact[i - 1] * i) % DIVISOR;

  long long ans = fact[N], inverse = power((fact[N - K] * fact[K]) % DIVISOR, DIVISOR - 2);

  ans = ans * inverse % DIVISOR;
  std::cout << ans << std::endl;

  return 0;
}