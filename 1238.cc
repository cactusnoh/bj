#include <iostream>
#include <vector>
#include <queue>

#define INF 2147000000

typedef std::pair<int, int> pii;

inline int min(int a, int b)
{
  return a < b ? a : b;
}
inline int max(int a, int b)
{
  return a < b ? b : a;
}

int N, M, X;
std::vector<pii> adj_list[1001];

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
int getDist(int s, int d)
{
  int dist[1001];

  for(int i = 1; i <= N; ++i)
    dist[i] = INF;
  dist[s] = 0;

  while(!Q.empty()) 
    Q.pop();
  Q.push(pii(0, s));

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second, d_u = curr.first;

    if(dist[u] != d_u) continue;
    if(u == d) return d_u;

    for(auto next: adj_list[u]) {
      int v = next.first, w_uv = next.second;
      if(dist[v] > d_u + w_uv) {
        dist[v] = d_u + w_uv;
        Q.push(pii(dist[v], v));
      }
    }
  }
  return 2147000;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M >> X;

  for(int i = 0; i < M; ++i) {
    int src, dst, w;
    std::cin >> src >> dst >> w;
    adj_list[src].push_back(pii(dst, w));
  }

  int dist_x[1001];
  for(int i = 1; i <= N; ++i)
    dist_x[i] = INF;
  dist_x[X] = 0;

  Q.push(pii(0, X));

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second, d_u = curr.first;

    if(dist_x[u] != d_u) continue;

    for(auto next: adj_list[u]) {
      int v = next.first, w_uv = next.second;
      if(dist_x[v] > d_u + w_uv) {
        dist_x[v] = d_u + w_uv;
        Q.push(pii(dist_x[v], v));
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; ++i) {
    ans = max(ans, getDist(i, X) + dist_x[i]);
  }

  std::cout << ans << std::endl;

  return 0;
}