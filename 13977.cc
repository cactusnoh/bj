#include <iostream>

#define P 1'000'000'007

long long power(long long a, long long x)
{
  long long ret = 1;

  while(x) {
    if(x & 1) {
      ret = (ret * a) % P;
    }
    a = (a * a) % P;
    x >>= 1;
  }

  return ret;
}

int N, M, K;

long long factorial[4'000'001];

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> M;

  factorial[0] = 1;
  for(int i = 1; i <= 4'000'000; ++i) {
    factorial[i] = (factorial[i - 1] * i) % P;
  }

  for(int i = 0; i < M; ++i) {
    std::cin >> N >> K;
    long long y_inv = power((factorial[K] * factorial[N - K]) % P, P - 2);
    std::cout << (factorial[N] * y_inv) % P << "\n";
  }

  return 0;
}