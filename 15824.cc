#include <iostream>
#include <algorithm>

#define P 1'000'000'007

int N;
int seq[300'000];

long long power(long long a, long long b)
{
  if(b == 0)
    return 1;
  long long temp = power(a, b >> 1);
  temp = (temp * temp) % P;
  if(b & 1)
    temp = (temp * a) % P;
  return temp;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> seq[i];
    
  std::sort(seq, seq + N);

  long long ans = 0;
  for(int i = 0; i < N; ++i) {
    ans = (ans + ((power(2, i) - power(2, N - 1 - i)) % P) * seq[i]) % P;
  }

  std::cout << ans << std::endl;

  return 0;
}