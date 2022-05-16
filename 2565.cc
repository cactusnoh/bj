#include <iostream>
#include <algorithm>
#include <utility>

int N;
std::pair<int, int> lines[100];
int memo[100];

int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> lines[i].first >> lines[i].second;
  std::sort(lines, lines + N);

  memo[0] = 1;
  for(int i = 1; i < N; ++i) {
    int max = 0;
    for(int j = 0; j < i; ++j)
      if(lines[j].second < lines[i].second && max < memo[j])
        max = memo[j];
    memo[i] = max + 1;
  }

  int max = 0;
  for(int i = 0; i < N; ++i)
    if(max < memo[i])
      max = memo[i];
  std::cout << N - max << std::endl;

  return 0;
}