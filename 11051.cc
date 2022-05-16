#include <iostream>

int N, K;
int memo[1001][1001];

int main()
{
  std::cin >> N >> K;
  for(int i = 1; i <= 1000; ++i) {
    memo[i][0] = memo[i][i] = 1;
  }
  for(int i = 2; i <= N; ++i) {
    for(int j = 1; j < i; ++j)
      memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]) % 10007;
  }
  std::cout << memo[N][K] << std::endl;

  return 0;
}