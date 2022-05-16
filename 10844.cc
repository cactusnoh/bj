#include <iostream>

#define DIV 1000000000

int N, cnt[101][10] = {{0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int solve()
{
  for(int i = 2; i <= N; ++i)
    for(int j = 0; j < 10; ++j)
      cnt[i][j] = ((j - 1 >= 0 ? cnt[i - 1][j - 1] : 0) + (j + 1 <= 9 ? cnt[i - 1][j + 1] : 0)) % DIV;

  int sum = 0;
  for(int i = 0; i < 10; ++i)
    sum = (sum + cnt[N][i]) % DIV ;
  return sum % DIV;
}

int main()
{
  std::cin >> N;
  std::cout << solve() << std::endl;
}