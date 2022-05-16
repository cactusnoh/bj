#include <iostream>

#define INF 2147000000

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int N, dimensions[501][2];
int memo[501][501];

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> N;
  for(int i = 1; i <= N; ++i)
    std::cin >> dimensions[i][0] >> dimensions[i][1];

  for(int i = 1; i < N; ++i)
    memo[i][i + 1] += dimensions[i][0] * dimensions[i][1] * dimensions[i + 1][1];

  for(int length = 3; length <= N; ++length) {
    for(int i = 1; i <= N - length + 1; ++i) {
      memo[i][i + length - 1] = INF;
      for(int j = i; j <= i + length - 2; ++j) {
        memo[i][i + length - 1] = min(memo[i][i + length - 1], memo[i][j] + memo[j + 1][i + length - 1] + dimensions[i][0] * dimensions[j][1] * dimensions[i + length - 1][1]);
      }
    }
  }
  std::cout << memo[1][N] << std::endl;

  return 0;
}