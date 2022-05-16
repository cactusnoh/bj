#include <iostream>
#include <vector>

int N, M;
std::vector<int> adj_list[32001], order;
bool visited[32001];

void DFS(int v)
{
  if(visited[v]) return;
  visited[v] = true;
  for(auto i : adj_list[v])
    DFS(i);
  order.push_back(v);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int src, dst;
    std::cin >> src >> dst;
    adj_list[src].push_back(dst);
  }

  for(int i = 1; i <= N; ++i)
    DFS(i);

  for(auto it = order.rbegin(); it != order.rend(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  
  return 0;
}