#include <iostream>
#include <vector>
#include <deque>

int K, V, E;
std::vector<int> adj_list[20001];
int visited[20001];

void DFS(int s, int color)
{
  visited[s] = color;
  for(int i : adj_list[s])
    if(visited[i] == 0)
      DFS(i, 3 - color);
}

bool isBipartite()
{
  for(int v = 1; v <= 20000; ++v) {
    for(int u : adj_list[v])
      if(visited[u] == visited[v])
        return false;
  }
  return true;
}

int main()
{
  std::cin >> K;
  for(int i = 0; i < K; ++i) {
    std::cin >> V >> E;
    for(int j = 0; j < E; ++j) {
      int a, b;
      std::cin >> a >> b;
      adj_list[a].push_back(b);
      adj_list[b].push_back(a);
    }
    for(int v = 1; v <= V; ++v)
      if(visited[v] == 0)
        DFS(v, 1);

    if(isBipartite())
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
    
    for(int j = 1; j <= V; ++j) {
      visited[j] = 0;
      adj_list[j].clear();
    }
  }
}