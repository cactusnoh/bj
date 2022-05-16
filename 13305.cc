#include <iostream>

int N, price[100000], dist[100000];

int main()
{
  long long curr_price = 1000000001;
  long long ret = 0;

  std::cin >> N;
  for(int i = 0; i < N - 1; ++i)
    std::cin >> dist[i];
  for(int i = 0; i < N; ++i)
    std::cin >> price[i];

  for(int i = 0; i < N - 1; ++i) {
    if(curr_price > price[i])
      curr_price = price[i];
    ret += curr_price * dist[i];
  }
  
  std::cout << ret << std::endl;

  return 0;
}