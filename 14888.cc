#include <iostream>

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

int N, numbers[11], operators[4];
int min = 1000000001, max = -1000000001;

void solve(int res, int used)
{
  if(used == N) {
    if(res < min) min = res;
    if(res > max) max = res;
    return;
  }

  for(int i = 0; i < 4; ++i) {
    if(operators[i] == 0) continue;
    --operators[i];
    if(i == ADD) solve(res + numbers[used], used + 1);
    if(i == SUB) solve(res - numbers[used], used + 1);
    if(i == MUL) solve(res * numbers[used], used + 1);
    if(i == DIV) solve(res / numbers[used], used + 1);
    ++operators[i];
  }
}

int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> numbers[i];
  for(int i = 0; i < 4; ++i)
    std::cin >> operators[i];

  solve(numbers[0], 1);

  std::cout << max << "\n" << min << std::endl;
}