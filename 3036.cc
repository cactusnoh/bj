#include <iostream>

int gcd(int a, int b)
{
  while(a % b) {
    int temp = a;
    a = b;
    b = temp % b;
  }
  return b;
}

int N, rings[100];

int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> rings[i];
  
  for(int i = 1; i < N; ++i) {
    int GCD = gcd(rings[0], rings[i]);
    std::cout << rings[0] / GCD << "/" << rings[i] / GCD << std::endl;
  }

  return 0;
}