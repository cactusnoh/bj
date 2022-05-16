#include <iostream>
#include <cstdio>

int N;
int map[64][64];

void DFS(int r, int c, int n)
{
  int color = map[r][c];
  for(int i = r; i < r + n; ++i) {
    for(int j = c; j < c + n; ++j) {
      if(color == map[i][j]) continue;
      std::cout << "(";
      DFS(r, c, n / 2);
      DFS(r, c + n / 2, n / 2);
      DFS(r + n / 2, c, n / 2);
      DFS(r + n / 2, c + n / 2, n / 2);
      std::cout << ")";
      return;
    }
  }
  std::cout << color;
}

int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      scanf("%1d", &map[i][j]);

  DFS(0, 0, N);

  return 0;
}