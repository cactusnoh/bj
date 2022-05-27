#include <iostream>

long long N;

int main()
{
  std::cin >> N;

  long long ans = N;

  for(long long i = 2; i * i <= N; ++i) {
    if(N % i == 0) {
      // Euler's phi function
      ans -= ans / i;
      // Divide N by i until N has no i factor
      while(N % i == 0) {
        N /= i;
      }
    }
  }

  if(N != 1) {
    ans -= ans / N;
  }

  std::cout << ans << std::endl;

  return 0;
}