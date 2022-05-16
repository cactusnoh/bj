#include <iostream>

int N, cnt[2];
int map[128][128];

void DFS(int r, int c, int n)
{
  int color = map[r][c];
  for(int i = r; i < r + n; ++i) {
    for(int j = c; j < c + n; ++j) {
      if(map[i][j] == color) continue;
      DFS(r, c, n / 2);
      DFS(r + n / 2, c, n / 2);
      DFS(r, c + n / 2, n / 2);
      DFS(r + n / 2, c + n / 2, n / 2);
      return;
    }
  }
  ++cnt[color];
}

int main()
{
  std::cin >> N;

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      std::cin >> map[i][j];

  DFS(0, 0, N);
  std::cout << cnt[0] << "\n" << cnt[1] << std::endl;
  return 0;
}