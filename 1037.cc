#include <iostream>
#include <algorithm>

int N, factors[50];

int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> factors[i];

  std::sort(factors, factors + N);

  std::cout << factors[0] * factors[N - 1] << std::endl;

  return 0;
}