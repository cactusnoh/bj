#include <iostream>
#include <cmath>

long long N;
bool is_prime[1'000'001];

long long gcd(long long a, long long b)
{
  while(b != 0) {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main()
{
  long long ans = 0;
  std::cin >> N;

  for(long long i = 2; i <= (long long) sqrt(N); ++i) {
    if(gcd(i, N) == 1) {
      ++ans;
    }
  }

  std::cout << N - ans << std::endl;

  return 0;
}