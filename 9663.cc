#include <iostream>
#include <cmath>

int map[15];
int N, cnt;

void queen(int q)
{
  if(q == N) {
    ++cnt;
    return;
  }

  for(int i = 0; i < N; ++i) {
    bool possible = true;
    for(int j = 0; j < q; ++j) {
      if(i == map[j] || abs(j - q) == abs(i - map[j])) {
        possible = false;
        break;
      }
    }
    if(possible) {
      map[q] = i;
      queen(q + 1);
    }
  }
}

int main()
{
  std::cin >> N;
  queen(0);
  std::cout << cnt << std::endl;

  return 0;
}