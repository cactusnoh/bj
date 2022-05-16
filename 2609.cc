#include <iostream>

int min(int a, int b)
{
  return a < b ? a : b;
}

int a, b;

int main()
{
  int gcd = 0;

  std::cin >> a >> b;

  for(int i = 1; i <= min(a, b); ++i)
    if(a % i == 0 && b % i == 0)
      gcd = i;
  
  std::cout << gcd << std::endl;
  std::cout << gcd * (a / gcd) * (b / gcd) << std::endl;

  return 0;
}