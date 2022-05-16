#include <iostream>
#include <vector>

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int N;
std::vector<int> adj_list[1'000'001];
int parent[1'000'001];
int memo[1'000'001][2];

bool visited[1'000'001];
std::vector<int> child_list[1'000'001];
void make_tree(int n)
{
  visited[n] = true;
  for(int child : adj_list[n]) {
    if(visited[child]) {
      continue;
    }
    make_tree(child);
    parent[child] = n;
    child_list[n].push_back(child);
  }
}

int solve(int n, int early)
{
  if(memo[n][early] != -1)
    return memo[n][early];
  
  int ret = 0;
  if(early) {
    ++ret;
    for(int i : child_list[n])
      ret += min(solve(i, 1), solve(i, 0));
  } else {
    for(int i : child_list[n])
      ret += solve(i, 1);
  }
  memo[n][early] = ret;
  return ret;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> N;

  int a, b;
  for(int i = 1; i <= N; ++i) {
    memo[i][0] = memo[i][1] = -1;
  }

  for(int i = 0; i < N - 1; ++i) {
    std::cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  make_tree(1);

  std::cout << min(solve(1, 1), solve(1, 0)) << std::endl;

  return 0;
}