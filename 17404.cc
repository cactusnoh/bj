#include <iostream>

#define RED 0
#define GREEN 1
#define BLUE 2

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int N;
int cost[1001][3];
int memo[1001][3][3];

int solve(int house, int color, int lastColor)
{
  if(house == N)
    return cost[N][color];
  if(memo[house][color][lastColor] != -1)
    return memo[house][color][lastColor];
  
  int ans = 2147000000;
  for(int i = 0; i < 3; ++i) {
    if(i == color) continue;
    if(house == N - 2 && i == lastColor) continue;
    if(house == N - 1 && i != lastColor) continue;
    ans = min(ans, solve(house + 1, i, lastColor));
  }

  memo[house][color][lastColor] = cost[house][color] + ans;
  return memo[house][color][lastColor];
}

int main()
{
  std::cin >> N;

  for(int i = 1; i <= N; ++i)
    for(int j = 0; j < 3; ++j)
      for(int k = 0; k < 3; ++k)
        memo[i][j][k] = -1;

  for(int i = 1; i <= N; ++i) {
    int r, g, b;
    std::cin >> r >> g >> b;
    cost[i][RED] = r; cost[i][GREEN] = g; cost[i][BLUE] = b;
  }

  int ans = 2147000000;
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      if(i == j) continue;
      ans = min(ans, solve(1, i, j));
    }
  }
  std::cout << ans << std::endl;

  return 0;
}