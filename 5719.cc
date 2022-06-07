#include <iostream>
#include <vector>
#include <queue>

#define INF 2147000000

typedef std::pair<int, int> pii;

int N, M, S, D;
int adj_mat[500][500];
std::vector<int> parent[500];

int dijkstra()
{
  int dist[500];
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> PQ;

  for (int i = 0; i < N; ++i) {
    dist[i] = INF;
  }
  dist[S] = 0;
  
  PQ.push(pii(0, S));

  while (!PQ.empty()) {
    pii curr = PQ.top();
    PQ.pop();

    int u = curr.second, d_u = curr.first;

    if (d_u != dist[u]) {
      continue;
    }
    
    for (int v = 0; v < N; ++v) {
      int d_uv = adj_mat[u][v];

      if (d_uv != -1 && d_u + d_uv <= dist[v]) {
        if (d_u + d_uv < dist[v]) {
          dist[v] = d_u + d_uv;
          parent[v].clear();
          PQ.push(pii(dist[v], v));
        }
        parent[v].push_back(u);
      }
    }
  }

  return dist[D] == INF ? -1 : dist[D];
}

void BFS()
{
  std::queue<int> Q;
  bool visited[500] = {0};

  visited[D] = true;
  Q.push(D);

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    for (int prev : parent[curr]) {
      if (!visited[prev]) {
        visited[prev] = true;
        Q.push(prev);
      }
      adj_mat[prev][curr] = -1;
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  while (true) {
    std::cin >> N >> M;

    if(N == 0) {
      break;
    }

    for(int i = 0; i < N; ++i) {
      parent[i].clear();
      for(int j = 0; j < N; ++j) {
        adj_mat[i][j] = -1;
      }
    }

    std::cin >> S >> D;

    int u, v, p;

    for(int i = 0; i < M; ++i) {
      std::cin >> u >> v >> p;
      adj_mat[u][v] = p;
    }

    dijkstra();

    BFS();

    std::cout << dijkstra() << "\n";
  }

  return 0;
}