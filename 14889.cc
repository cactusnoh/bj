#include <iostream>
#include <cmath>

int N, stat[21][21], min = 987654321;
bool team_1[21];

void solve(int seen, int picked, int sum_1, int sum_2)
{
  if(seen == N && picked == N / 2) {
    if(abs(sum_1 - sum_2) < min)
      min = abs(sum_1 - sum_2);
    return;
  } else if(seen == N)
    return;

  int psum_1 = sum_1, psum_2 = sum_2;

  for(int i = 1; i <= seen; ++i) {
    if(team_1[i])
      psum_1 += stat[i][seen + 1] + stat[seen + 1][i];
    else
      psum_2 += stat[i][seen + 1] + stat[seen + 1][i];
  }

  if(picked < N / 2) {
    team_1[seen + 1] = true;
    solve(seen + 1, picked + 1, psum_1, sum_2);
    team_1[seen + 1] = false;
  }

  solve(seen + 1, picked, sum_1, psum_2);
}

int main()
{
  std::cin >> N; 
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= N; ++j)
      std::cin >> stat[i][j];
  
  team_1[1] = true;
  solve(1, 1, 0, 0);

  std::cout << min << std::endl;
}