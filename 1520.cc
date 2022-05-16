#include <iostream>

int N, M, map[501][501], memo[501][501];
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, -1, 1};

int solve(int r, int c)
{
  if(r == 1 && c == 1)
    return 1;
  if(memo[r][c] != -1)
    return memo[r][c];
  
  int ret = 0;
  for(int i = 0; i < 4; ++i) {
    int nr = r + dr[i], nc = c + dc[i];
    if(nr < 1 || nr > N || nc < 1 || nc > M)
      continue;
    ret += (map[nr][nc] > map[r][c] ? solve(nr, nc) : 0);
  }
  memo[r][c] = ret;

  return ret;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> N >> M;
  for(int r = 1; r <= N; ++r) {
    for(int c = 1; c <= M; ++c) {
      std::cin >> map[r][c];
      memo[r][c] = -1;
    }
  }
  
  solve(N, M);
  std::cout << memo[N][M] << std::endl;

  return 0;
}