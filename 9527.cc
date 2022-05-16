#include <iostream>

long long pow(long long a, long long x)
{
  if(x == 0)
    return 1;
  long long temp = pow(a, (x >> 1));
  if(x & 1)
    return temp * temp * a;
  else
    return temp * temp;
}

long long solve(long long n)
{
  if(n == 0)
    return 0;
  int digits;
  for(digits = 63; digits >= 0; --digits)
    if(n & ((long long) 1 << digits))
      break;
  n = n ^ ((long long) 1 << digits);
  return digits * ((long long) 1 << (digits - 1)) + (n + 1) + solve(n);
}

long long A, B;

int main()
{
  std::cin >> A >> B;

  std::cout << solve(B) - solve(A - 1) << std::endl;

  return 0;
}