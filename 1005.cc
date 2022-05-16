#include <iostream>
#include <vector>

inline int max(int a, int b)
{
  return a < b ? b : a;
}

int T, N, K, W;
int cost[1001], memo[1001];
std::vector<int> back_list[1001];

int solve(int n)
{
  if(back_list[n].size() == 0)
    return cost[n];
  if(memo[n] != -1)
    return memo[n];
  
  int ans = 0;
  for(auto prev : back_list[n])
    ans = max(ans, solve(prev));
  memo[n] = ans + cost[n];
  return memo[n];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> T;

  for(int tc = 1; tc <= T; ++tc) {
    std::cin >> N >> K;

    for(int i = 1; i <= N; ++i) {
      memo[i] = -1;
      back_list[i].clear();
      std::cin >> cost[i];
    }

    for(int i = 0; i < K; ++i) {
      int src, dst;
      std::cin >> src >> dst;
      back_list[dst].push_back(src);
    }

    std::cin >> W;
    std::cout << solve(W) << "\n";
  }
  return 0;
}