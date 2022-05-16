#include <iostream>
#include <vector>
#include <cstring>

typedef std::pair<int, int> pii;

int V;
std::vector<pii> adj_list[100001];
bool visited[100001];

int end, max_len;

void DFS(int s, int sum)
{
  if(visited[s]) return;

  visited[s] = true;

  if(max_len < sum) {
    max_len = sum;
    end = s;
  }

  for(auto next : adj_list[s])
    if(!visited[next.first])
      DFS(next.first, sum + next.second);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> V;

  for(int i = 0; i < V; ++i) {
    int src;
    std::cin >> src;
    while(1) {
      int dst, w;
      std::cin >> dst;
      if(dst == -1) break;
      std::cin >> w;
      adj_list[src].push_back(pii(dst, w));
    }
  }

  DFS(1, 0);
  memset(visited, 0, sizeof(visited));
  max_len = 0;
  DFS(end, 0);

  std::cout << max_len << std::endl;

  return 0;
}