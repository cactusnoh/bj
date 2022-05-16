#include <iostream>

#define ARR_SIZE 4'000'000

inline int abs(int a)
{
  return a < 0 ? -a : a;
}

int N, S;
long long ans;
int seq[40];
int occurence[2][ARR_SIZE + 1];

void DFS_first(int seen, int sum)
{
  if(seen == N / 2) {
    ++occurence[0][sum + ARR_SIZE / 2];
    return;
  }
  DFS_first(seen + 1, sum + seq[seen]);
  DFS_first(seen + 1, sum);
}

void DFS_second(int seen, int selected, int sum)
{
  if(seen == N) {
    ++occurence[1][sum + ARR_SIZE / 2];
    return;
  }
  DFS_second(seen + 1, selected + 1, sum + seq[seen]);
  DFS_second(seen + 1, selected, sum);
}

int main() 
{
  std::cin >> N >> S;

  for(int i = 0; i < N; ++i)
    std::cin >> seq[i];

  DFS_first(0, 0);
  DFS_second(N / 2, 0, 0);

  for(int i = -2'000'000; i <= 2'000'000; ++i) {
    if(abs(S - i) <= 2'000'000) {
      ans += (long long) occurence[0][i + ARR_SIZE / 2] * occurence[1][S - i + ARR_SIZE / 2];
    }
  }

  if(S == 0)
    --ans;

  std::cout << ans << std::endl;

  return 0;
}