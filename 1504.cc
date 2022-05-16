#include <iostream>
#include <queue>
#include <vector>

#define INF 2147000000

typedef std::pair<int, int> pii;

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int V, E, v1, v2;
int dist[801];
std::vector<pii> adj_list[801];
bool fail;

int dijkstra(int S, int D)
{
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

  for(int j = 1; j <= V; ++j)
    dist[j] = INF;

  dist[S] = 0;
  Q.push(pii(0, S));

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second, d_u = curr.first;

    if(u == D) return dist[u];
    if(dist[u] < d_u) continue;

    for(auto next : adj_list[u]) {
      int v = next.first, weight_uv = next.second;
      if(dist[v] <= d_u + weight_uv) continue;
      dist[v] = d_u + weight_uv;
      Q.push(pii(d_u + weight_uv, v));
    }
  }
  fail = true;
  return 0;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> V >> E;

  for(int i = 0; i < E; ++i) {
    int src, dst, w;
    std::cin >> src >> dst >> w;
    adj_list[src].push_back(pii(dst, w));
    adj_list[dst].push_back(pii(src, w));
  }

  std::cin >> v1 >> v2;

  int ans = min(dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, V), dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, V));
  std::cout << (fail ? -1 : ans)<< std::endl;

  return 0;
}