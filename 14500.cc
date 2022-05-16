#include <iostream>

typedef std::pair<int, int> pii;

int N, M;
int map[500][500];
int max_sum;

pii shapes[19][4] = { 
                      // cyan
                      {pii(0, 1), pii(0, 2), pii(0, 3)},
                      {pii(1, 0), pii(2, 0), pii(3, 0)},
                      // yellow
                      {pii(0, 1), pii(1, 0), pii(1, 1)},
                      // orange
                      {pii(1, 0), pii(2, 0), pii(2, 1)},
                      {pii(1, 0), pii(2, 0), pii(2, -1)},
                      {pii(0, 1), pii(0, 2), pii(-1, 2)},
                      {pii(0, 1), pii(0, 2), pii(1, 2)},
                      {pii(0, -1), pii(0, -2), pii(-1, -2)},
                      {pii(0, -1), pii(0, -2), pii(1, -2)},
                      {pii(-1, 0), pii(-2, 0), pii(-2, -1)},
                      {pii(-1, 0), pii(-2, 0), pii(-2, 1)},
                      // green
                      {pii(1, 0), pii(1, 1), pii(2, 1)},
                      {pii(1, 0), pii(1, -1), pii(2, -1)},
                      {pii(0, 1), pii(1, 1), pii(1, 2)},
                      {pii(0, 1), pii(-1, 1), pii(-1, 2)},
                      // purple
                      {pii(0, -1), pii(1, -1), pii(-1, -1)},
                      {pii(0, 1), pii(1, 1), pii(-1, 1)},
                      {pii(1, -1), pii(1, 0), pii(1, 1)},
                      {pii(-1, -1), pii(-1, 0), pii(-1, 1)}
                    };

void check(int r, int c)
{
  for(int i = 0; i < 19; ++i) {
    int sum = 0;
    sum += map[r][c];
    for(int j = 0; j < 3; ++j) {
      int nr = r + shapes[i][j].first, nc = c + shapes[i][j].second;
      if(nr < 0 || nr >= N || nc < 0 || nc >= M) break;
      sum += map[nr][nc];
    }
    if(max_sum < sum)
      max_sum = sum;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      std::cin >> map[i][j];
  
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      check(i, j);
    }
  }

  std::cout << max_sum << std::endl;

  return 0;
}