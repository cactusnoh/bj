#include <iostream>
#include <vector>
#include <queue>

#define INF 2147000000

typedef std::pair<int, int> pii;

int N, M;
int s, d;

std::vector<pii> adj_list[1001];

int dist[1001], parent[1001];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
void dijkstra()
{
  for(int i = 1; i <= N; ++i)
    dist[i] = INF;
  dist[s] = 0;
  Q.push(pii(0, s));

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second, d_u = curr.first;

    if(dist[u] != d_u) continue;
    if(u == d) break;

    for(auto next : adj_list[u]) {
      int v = next.first, w_uv = next.second;
      if(dist[v] > d_u + w_uv) {
        dist[v] = d_u + w_uv;
        parent[v] = u;
        Q.push(pii(dist[v], v));
      }
    }
  }
}


int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;

  for(int i = 0; i < M; ++i) {
    int src, dst, w;
    std::cin >> src >> dst >> w;
    adj_list[src].push_back(pii(dst, w));
  }
  std::cin >> s >> d;

  dijkstra();

  std::cout << dist[d] << "\n";
  
  std::vector<int> ans;
  int curr = d;
  while(curr != 0) {
    ans.push_back(curr);
    curr = parent[curr];
  }

  std::cout << ans.size() << "\n";
  for(int i = ans.size() - 1; i >= 0; --i)
    std::cout << ans[i] << " ";
  std::cout << "\n";

  return 0;
}