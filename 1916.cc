#include <iostream>
#include <vector>
#include <queue>

#define INF 2147000000

typedef std::pair<int, int> pii;

int N, M;
std::vector<pii> adj_list[1001];
int dist[1001];

int SRC, DST;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

int dijkstra(int s)
{
  dist[s] = 0;
  Q.push(pii(0, s));

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second, d_u = curr.first;

    if(u == DST) return d_u;
    if(dist[u] != d_u) continue;

    for(auto next : adj_list[u]) {
      int v = next.first, w_uv = next.second;
      if(dist[v] > d_u + w_uv) {
        dist[v] = d_u + w_uv;
        Q.push(pii(dist[v], v));
      }
    }
  }
  return -1;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;

  for(int i = 1; i <= N; ++i)
    dist[i] = INF;

  for(int i = 0; i < M; ++i) {
    int src, dst, w;
    std::cin >> src >> dst >> w;
    adj_list[src].push_back(pii(dst, w));
  }

  std::cin >> SRC >> DST;

  std::cout << dijkstra(SRC) << std::endl;

  return 0;
}