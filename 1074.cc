#include <iostream>

int N, R, C;
int cnt = 0;

void solve(int n, int r, int c)
{
  if(r <= R && R < r + n && c <= C && C < c + n) {
    if(n > 2) {
      solve(n >> 1, r, c);
      solve(n >> 1, r, c + (n >> 1));
      solve(n >> 1, r + (n >> 1), c);
      solve(n >> 1, r + (n >> 1), c + (n >> 1));
      return;
    }

    for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < 2; ++j) {
        if(r + i == R && c + j == C)
          std::cout << cnt << std::endl;
        ++cnt;
      }
    }
  } else {
    cnt += n * n;
  }
}

int main()
{
  std::cin >> N >> R >> C;

  solve((1 << N), 0, 0);

  return 0;
}