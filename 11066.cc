#include <iostream>

#define INF 2100000000

int min(int a, int b)
{
  return a < b ? a : b;
}

int T, K;
int memo[501][501], partial_sum[501];

int main()
{
  std::cin >> T;
  for(int t = 0; t < T; ++t) {
    std::cin >> K;
    // input
    int temp;
    for(int i = 0; i < K; ++i) {
      std::cin >> temp;
      partial_sum[i] = (i > 0 ? partial_sum[i - 1] : 0) + temp;
      memo[i][i] = 0;
    }
    // solve
    for(int j = 1; j < K; ++j) {
      for(int i = 0; i < K - j; ++i) {
        memo[i][i + j] = INF;
        for(int k = i; k < i + j; ++k) {
          memo[i][i + j] = min(memo[i][i + j], memo[i][k] + memo[k + 1][i + j] + partial_sum[i + j] - (i > 0 ? partial_sum[i - 1] : 0));
        }
      }
    }
    std::cout << memo[0][K - 1] << std::endl;
  }

  return 0;
}