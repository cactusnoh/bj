#include <iostream>
#include <vector>

#define INF 2147000000

typedef std::pair<int, int> pii;

int TC, N, M, W;
std::vector<pii> adj_list[501];
int dist[501];

bool bellmanFord(int s)
{
  for(int i = 1; i <= N; ++i)
    dist[i] = INF;
  dist[s] = 0;

  for(int i = 0; i < N - 1; ++i) {
    for(int u = 1; u <= N; ++u) {
      for(auto edge : adj_list[u]) {
        int v = edge.first, w_uv = edge.second;
        if(dist[v] > dist[u] + w_uv)
          dist[v] = dist[u] + w_uv;
      }
    }
  }

  for(int u = 1; u <= N; ++u) {
    for(auto edge : adj_list[u]) {
      int v = edge.first, w_uv = edge.second;
      if(dist[v] > dist[u] + w_uv) {
        dist[v] = dist[u] + w_uv;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> TC;

  for(int test_case = 1; test_case <= TC; ++test_case) {
    std::cin >> N >> M >> W;
    int S, E, T;
    for(int i = 1; i <= N; ++i)
      adj_list[i].clear();

    for(int i = 0; i < M; ++i) {
      std::cin >> S >> E >> T;
      adj_list[S].push_back(pii(E, T));
      adj_list[E].push_back(pii(S, T));
    }
    for(int i = 0; i < W; ++i) {
      std::cin >> S >> E >> T;
      adj_list[S].push_back(pii(E, -T));
    }

    bool exit = false;
    if(bellmanFord(1)) 
        std::cout << "YES" << "\n";
    else
    std::cout << "NO" << "\n";
  }

  return 0;
}