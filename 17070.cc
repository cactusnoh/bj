#include <iostream>

#define HORI 0
#define VERT 1
#define DIAG 2

int N;
int map[18][18];
int ans;

void DFS(int r, int c, int direction)
{
  if(r == N && c == N) {
    ++ans;
    return;
  }

  if(direction == HORI) {
    if(map[r][c + 1] == 0) 
      DFS(r, c + 1, HORI);
    if(map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
      DFS(r + 1, c + 1, DIAG);
  } else if(direction == VERT) {
    if(map[r + 1][c] == 0)
      DFS(r + 1, c, VERT);
    if(map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0) 
      DFS(r + 1, c + 1, DIAG);
  } else if(direction == DIAG) {
    if(map[r][c + 1] == 0) 
      DFS(r, c + 1, HORI);
    if(map[r + 1][c] == 0) 
      DFS(r + 1, c, VERT);
    if(map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0) 
      DFS(r + 1, c + 1, DIAG);
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
      std::cin >> map[i][j];
  
  for(int i = 1; i <= N; ++i) {
    map[i][N + 1] = 1;
    map[N + 1][i] = 1;
  }    

  DFS(1, 2, HORI);

  std::cout << ans << std::endl;

  return 0;
}