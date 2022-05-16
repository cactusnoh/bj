#include <iostream>

inline int abs(int n)
{
  return n < 0 ? -n : n;
}

int W, M, weights[31];
int memo[31][15001];

void solve(int i, int w)
{
  if(i > W || memo[i][w]) return;
  memo[i][w] = true;
  solve(i + 1, w);
  solve(i + 1, w + weights[i + 1]);
  solve(i + 1, abs(w - weights[i + 1]));
}

int main()
{
  int weight_sum = 0;

  std::cin >> W;
  for(int i = 1; i <= W; ++i) {
    std::cin >> weights[i];
    weight_sum += weights[i];
  }
  solve(0, 0);

  std::cin >> M;
  int tmp;
  for(int i = 0; i < M; ++i) {
    std::cin >> tmp;
    if(tmp > 15000) 
      std::cout << "N ";
    else 
      std::cout << (memo[W][tmp] ? "Y " : "N ");
  }
  std::cout << std::endl;

  return 0;
}