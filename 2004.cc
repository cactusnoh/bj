#include <iostream>

int min(int a, int b)
{
  return a < b ? a : b;
}

int n, m;
int r;

int main()
{
  std::cin >> n >> m;

  r = n - m;
  int nsave = 0, msave = 0, rsave = 0;
  int nsave2 = 0, msave2 = 0, rsave2 = 0;

  int divider = 5;
  while(n / divider || m / divider || r / divider) {
    nsave += (n / divider);
    msave += (m / divider);
    rsave += (r / divider);
    divider *= 5;
    if(divider > 1500000000)
      break;
  }

  divider = 2;
  while(n / divider || m / divider || r / divider) {
    nsave2 += (n / divider);
    msave2 += (m / divider);
    rsave2 += (r / divider);
    divider *= 2;
    if(divider > 2100000000)
      break;
  }

  std::cout << min(nsave - (msave + rsave), nsave2 - (msave2 + rsave2)) << std::endl;

  return 0;
}