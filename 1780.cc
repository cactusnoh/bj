#include <iostream>

int N, map[2187][2187];
int cnt[3];

void DFS(int r, int c, int n)
{
  int number = map[r][c];
  for(int i = r; i < r + n; ++i) {
    for(int j = c; j < c + n; ++j) {
      if(map[i][j] == number) continue;
      DFS(r, c, n / 3);
      DFS(r, c + n / 3, n / 3);
      DFS(r, c + 2 * n / 3, n / 3);
      DFS(r + n / 3, c, n / 3);
      DFS(r + n / 3, c + n / 3, n / 3);
      DFS(r + n / 3, c + 2 * n / 3, n / 3);
      DFS(r + 2 * n / 3, c, n / 3);
      DFS(r + 2 * n / 3, c + n / 3, n / 3);
      DFS(r + 2 * n / 3, c + 2 * n / 3, n / 3);
      return;
    }
  }
  ++cnt[number + 1];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);
  
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      std::cin >> map[i][j];

  DFS(0, 0, N);
  for(int i = 0; i < 3; ++i)
    std::cout << cnt[i] << std::endl;

  return 0;
}