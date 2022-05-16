#include <iostream>

#define P 1000000007

long long power(long long a, long long x)
{
  if(x == 0)
    return 1;
  
  long long temp = power(a, x >> 1);
  temp = (temp * temp) % P;

  if(x & 1)
    return (temp * a) % P;
  else
    return temp;  
}

long long M;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  long long sum = 0;
  std::cin >> M;

  for(int i = 0; i < M; ++i) {
    long long N, S;
    std::cin >> N >> S;
    sum = ((power(N, P - 2) * S) % P + sum) % P;
  }

  std::cout << sum << std::endl;

  return 0;
}