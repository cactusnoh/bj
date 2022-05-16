#include <iostream>

int N, M, ans, areaCnt;
int visited[1001][1001];
char map[1001][1001];

void DFS(int r, int c, int areaNum)
{
  if(visited[r][c]) {
    if(visited[r][c] != areaNum)
      --ans;
    return;
  }

  visited[r][c] = areaNum;
  switch(map[r][c]) {
    case 'U':
    DFS(r - 1, c, areaNum);
    break;
    case 'D':
    DFS(r + 1, c, areaNum);
    break;
    case 'L':
    DFS(r, c - 1, areaNum);
    break;
    case 'R':
    DFS(r, c + 1, areaNum);
    break;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;
  
  for(int i = 0; i < N; ++i)
    std::cin >> map[i];

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      if(visited[i][j])
        continue;
      DFS(i, j, ++areaCnt);
      ++ans;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}