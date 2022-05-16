#include <iostream>

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int seq[100000];
int size;

int cost[5][5] = {
  {0, 2, 2, 2, 2},
  {0, 1, 3, 4, 3},
  {0, 3, 1, 3, 4},
  {0, 4, 3, 1, 3},
  {0, 3, 4, 3, 1}
};

int memo[100000][5][5];

int solve(int cnt, int left, int right)
{
  if(cnt == size)
    return 0;
  if(memo[cnt][left][right] != -1)
    return memo[cnt][left][right];
  
  if(left == seq[cnt] || right == seq[cnt])
    memo[cnt][left][right] = 1 + solve(cnt + 1, left, right);
  else
    memo[cnt][left][right] = min(cost[left][seq[cnt]] + solve(cnt + 1, seq[cnt], right),
                                 cost[right][seq[cnt]] + solve(cnt + 1, left, seq[cnt]));
  return memo[cnt][left][right];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  /*
  for(int i = 0; i < 100000; ++i)
    for(int j = 0; j < 5; ++j)
      for(int k = 0; k < 5; ++k)
        memo[i][j][k] = -1;
  */

  size = 0;
  while(1) {
    int temp;
    std::cin >> temp;
    if(temp == 0) break;
    seq[size++] = temp;
  }

  //std::cout << solve(0, 0, 0) << std::endl;

  for(int cnt = size - 1; cnt >= 0; --cnt) {
    for(int left = 0; left <= 4; ++left) {
      for(int right = 0; right <= 4; ++right) {
        if(left == seq[cnt] || right == seq[cnt])
          memo[cnt][left][right] = 1 + memo[cnt + 1][left][right];
        else
          memo[cnt][left][right] = min(cost[left][seq[cnt]] + memo[cnt + 1][seq[cnt]][right],
                                       cost[right][seq[cnt]] + memo[cnt + 1][left][seq[cnt]]);
      }
    }
  }

  std::cout << memo[0][0][0] << std::endl;

  return 0;
}