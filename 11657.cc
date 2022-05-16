#include <iostream>
#include <map>

#define INF 1000000000
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef std::pair<int, int> pii;

int N, M;
long long dist[501];
std::map<int, int> adj_list[501];

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int src, dst, w;
    std::cin >> src >> dst >> w;
    if(adj_list[src].find(dst) == adj_list[src].end())
      adj_list[src][dst] = w;
    else
      adj_list[src][dst] = min(adj_list[src][dst], w);
  }

  for(int i = 2; i <= N; ++i)
    dist[i] = INF;

  for(int i = 0; i < N; ++i) {
    for(int u = 1; u <= N; ++u) {
      for(auto next : adj_list[u]) {
        int v = next.first, w_uv = next.second;
        if(dist[u] == INF) continue;
        if(dist[v] > dist[u] + w_uv)
          dist[v] = dist[u] + w_uv;
      }
    }
  }

  for(int u = 1; u <= N; ++u) {
    for(auto next : adj_list[u]) {
      int v = next.first, w_uv = next.second;
      if(dist[u] == INF) continue;
      if(dist[v] > dist[u] + w_uv) {
        std::cout << -1 << std::endl;
        return 0;
      }
    }
  }

  for(int i = 2; i <= N; ++i)
    std::cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
  std::cout << std::endl;

  return 0;
}