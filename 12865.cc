#include <iostream>

int N, K;
int weight[101], value[101];
int memo[100001];

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::cin >> N >> K;
  for(int i = 1; i <= N; ++i)
    std::cin >> weight[i] >> value[i];

  for(int i = 1; i <= N; ++i)
    for(int w = K; w >= weight[i]; --w)
      memo[w] = max(memo[w], memo[w - weight[i]] + value[i]);

  std::cout << memo[K] << std::endl;

  return 0;
}