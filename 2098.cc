#include <iostream>

#define MAX_CITY 16
#define INF 2000000000

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int N;
int W[MAX_CITY][MAX_CITY], memo[16][1 << MAX_CITY];

int solve(int curr_city, int visited)
{
  if(visited == ((1 << N) - 1))
    return (W[curr_city][0] == 0 ? INF : W[curr_city][0]);
  
  int &ret = memo[curr_city][visited];

  if(ret != -1)
    return ret;
  
  ret = INF;
  for(int i = 0; i < N; ++i) {
    if(visited & (1 << i) || W[curr_city][i] == 0)
      continue;
    ret = min(ret, W[curr_city][i] + solve(i, visited | (1 << i)));
  }
  return ret;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      std::cin >> W[i][j];
    }
    for(int k = 0; k < (1 << N); ++k)
      memo[i][k] = -1;
  }

  int ans = solve(0, (1 << 0));
  
  std::cout << ans << std::endl;

  return 0;
}