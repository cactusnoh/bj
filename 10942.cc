#include <iostream>

int N, M;
int seq[2001], memo[2001][2001];

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> N;
  for(int i = 1; i <= N; ++i) {
    std::cin >> seq[i];
    memo[i][i] = 1;
  }

  for(int i = 1; i < N; ++i)
    if(seq[i] == seq[i + 1])
      memo[i][i + 1] = 1;

  for(int length = 3; length <= N; ++length) {
    for(int beg = 1; beg <= N - length + 1; ++beg) {
      if(seq[beg] != seq[beg + length - 1])
        continue;
      if(memo[beg + 1][beg + length - 2] == 1)
        memo[beg][beg + length - 1] = 1;
    }
  }
  
  std::cin >> M;
  for(int i = 0; i < M; ++i) {
    int beg, end;
    std::cin >> beg >> end;
    std::cout << memo[beg][end] << "\n";
  }

  return 0;
}