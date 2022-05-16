#include <iostream>
long long A, B, C;

long long power(long long a, long long b)
{
  if(b == 0) return 1;
  long long result = power(a, b / 2);
  result = result * result % C;
  if(b % 2) result = result * a % C;
  return result;
}

int main()
{
  std::cin >> A >> B >> C;
  std::cout << power(A, B) << std::endl;
  return 0;
}