#include <iostream>
#include <vector>

int N;
int seq[1001], memo[1001], parent[1001];

int solve(int x)
{
  if(memo[x] != -1)
    return memo[x];

  int max = 0, argmax = 0;
  for(int i = 0; i < x; ++i) {
    if(seq[i] < seq[x] && solve(i) > max) {
      max = solve(i);
      argmax = i;
    }
  }
  memo[x] = max + 1;
  parent[x] = argmax;

  return memo[x];
}

int main()
{
  std::cin >> N;

  for(int i = 1; i <= N; ++i) {
    memo[i] = -1;
    std::cin >> seq[i];
  }
  
  int ans = 0, argans = 0;
  for(int i = 1; i <= N; ++i) {
    if(solve(i) > ans) {
      ans = solve(i);
      argans = i;
    }
  }
  std::cout << ans << "\n";

  std::vector<int> parents;
  int curr = argans;
  while(curr != 0) {
    parents.push_back(seq[curr]);
    curr = parent[curr];
  }

  for(int i = parents.size() - 1; i >= 0; --i)
    std::cout << parents[i] << " ";
  std::cout << "\n";

  return 0;
}