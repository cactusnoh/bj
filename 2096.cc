#include <iostream>
#include <cstring>

inline int min(int a, int b)
{
  return a < b ? a : b;
}
inline int max(int a, int b)
{
  return a < b ? b : a;
}
inline int abs(int a)
{
  return a < 0 ? -a : a;
}

int N;
int map[100000][3];
int memo_min[3], memo_max[3];

/*
int solve_min(int r, int c)
{
  if(memo_min[r][c] != -1)
    return memo_min[r][c];

  memo_min[r][c] = 2147000000;
  for(int i = 0; i < 3; ++i) {
    if(abs(i - c) > 1) continue;
    memo_min[r][c] = min(map[r][c] + solve_min(r + 1, i), memo_min[r][c]);
  }

  return memo_min[r][c];
}

int solve_max(int r, int c)
{
  if(memo_max[r][c] != -1)
    return memo_max[r][c];

  for(int i = 0; i < 3; ++i) {
    if(abs(i - c) > 1) continue;
    memo_max[r][c] = max(map[r][c] + solve_max(r + 1, i), memo_max[r][c]);
  }

  return memo_max[r][c];
}
*/

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    int one, two, three;
    std::cin >> one >> two >> three;
    map[i][0] = one; map[i][1] = two; map[i][2] = three;
  }
  memo_min[0] = memo_max[0] = map[N - 1][0];
  memo_min[1] = memo_max[1] = map[N - 1][1];
  memo_min[2] = memo_max[2] = map[N - 1][2];

  for(int i = N - 2; i >= 0; --i) {
    int curr_min[3], curr_max[3];
    for(int j = 0; j < 3; ++j) {
      curr_min[j] = 2147000000;
      curr_max[j] = 0;
      for(int k = 0; k < 3; ++k) {
        if(abs(k - j) > 1) continue;
        curr_min[j] = min(curr_min[j], map[i][j] + memo_min[k]); 
        curr_max[j] = max(curr_max[j], map[i][j] + memo_max[k]); 
      }
    }
    memo_min[0] = curr_min[0]; memo_min[1] = curr_min[1]; memo_min[2] = curr_min[2];
    memo_max[0] = curr_max[0]; memo_max[1] = curr_max[1]; memo_max[2] = curr_max[2];
  }

  std::cout << max(memo_max[0], max(memo_max[1], memo_max[2])) << " ";
  std::cout << min(memo_min[0], min(memo_min[1], memo_min[2])) << "\n";

  return 0;
}