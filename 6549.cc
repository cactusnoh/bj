#include <iostream>

int n, histogram[100000];

void solve()
{

}

int main()
{
  while(1) {
    std::cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; ++i)
      std::cin >> histogram[i];
    solve();
  }
  return 0;
}