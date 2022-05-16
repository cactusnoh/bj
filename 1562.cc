#include <iostream>

#define DIVISOR 1'000'000'000

int N, ans;
int memo[101][10][1 << 10];

int solve(int level, int curr_num, int visited)
{
  if(level == 1) {
    if(curr_num == 0)
      return 0;
    if(visited != (1 << curr_num))
      return 0;
    return 1;
  }
  
  int &ret = memo[level][curr_num][visited];
  if(ret != -1)
    return ret;
  long long temp = 0;
  if(curr_num > 0)
    temp = (temp + solve(level - 1, curr_num - 1, visited) + solve(level - 1, curr_num - 1, visited ^ (1 << curr_num))) % DIVISOR;
  if(curr_num < 10)
    temp = (temp + solve(level - 1, curr_num + 1, visited) + solve(level - 1, curr_num + 1, visited ^ (1 << curr_num))) % DIVISOR;
  ret = temp;
  return ret;
}

int main()
{
  std::cin >> N;

  for(int i = 2; i <= N; ++i)
    for(int j = 0; j < 10; ++j)
      for(int k = 0; k < 1024; ++k)
        memo[i][j][k] = -1;

  int ans = 0;
  for(int i = 0; i < 10; ++i)
    ans = (ans + solve(N, 0, (1 << 10) - 1)) % DIVISOR;

  std::cout << ans << std::endl;

  return 0;
}