#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> pii;

int N;
int max_length;
int end;

std::vector<pii> adj_list[10001];

void DFS(int n, int prev, int sum)
{
  bool canGo = false;

  for(auto next : adj_list[n]) {
    if(next.first == prev) continue;
    canGo = true;
    DFS(next.first, n, sum + next.second);
  }

  if(!canGo) {
    if(max_length < sum) {
      max_length = sum;
      end = n;
    }
    return;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  for(int i = 0; i < N - 1; ++i) {
    int parent, child, weight;
    std::cin >> parent >> child >> weight;
    adj_list[parent].push_back(pii(child, weight));
    adj_list[child].push_back(pii(parent, weight));
  }

  DFS(1, 0, 0);
  DFS(end, 0, 0);

  std::cout << max_length << std::endl;

  return 0;
}