#include <iostream>

inline int abs(int a)
{
  return a < 0 ? -a : a;
}

int N;
int liquids[100000];

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  for(int i = 0; i < N; ++i)
    std::cin >> liquids[i];

  int sum = 2'147'000'000, a = -1, b = -1;
  int left = 0, right = N - 1;
  while(right > left) {
    int possible = liquids[left] + liquids[right];
    if(sum > abs(possible)) {
      sum = abs(possible);
      a = left;
      b = right;
    }
    
    if(possible > 0)
      --right;
    else if(possible == 0)
      break;
    else
      ++left;
  }

  std::cout << liquids[a] << " " << liquids[b] << std::endl;

  return 0;
}