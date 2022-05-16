#include <iostream>
#include <vector>
#include <queue>

int N, M;
int conn_count;
bool visited[1001];
std::vector<int> adj_list[1001];

std::queue<int> Q;

void BFS(int i)
{
  if(visited[i]) return;
  ++conn_count;

  visited[i] = true;
  Q.push(i);

  while(!Q.empty()) {
    auto u = Q.front(); Q.pop();
    for(auto v : adj_list[u]) {
      if(visited[v]) continue;
      visited[v] = true;
      Q.push(v);
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> N >> M;

  for(int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v; 
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  for(int i = 1; i <= N; ++i)
    BFS(i);

  std::cout << conn_count << std::endl;

  return 0;
}