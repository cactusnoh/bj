#include <iostream>
#include <vector>
#include <queue>

#define INF 2147000000

struct Edge {
  Edge(int _dest, int _cost) : dest(_dest), cost(_cost) {}
  int dest;
  int cost;
};
struct Path {
  Path(int _dest, int _dist, int _length) : dest(_dest), dist(_dist), length(_length) {}

  bool operator>(const Path &other) const {
    return dist > other.dist;
  }
  int dest;
  int dist;
  int length;
};

inline int min(int a, int b) {
  return a < b ? a : b;
}

int N, M, K, S, D;
int cost_increase[30'001];
std::vector<Edge> adj_list[1001];

int min_dist[1001];
int dist[1001][1001];
void BFS() {
  for (int i = 1; i <= N; ++i) {
    min_dist[i] = INF;
    for (int j = 0; j < N; ++j) {
      dist[i][j] = INF;
    }
  }

  std::queue<Path> Q;

  Q.emplace(S, 0, 0);
  min_dist[S] = 0;
  dist[S][0] = 0;
  
  while (!Q.empty()) {
    Path curr = Q.front();
    Q.pop();

    if (curr.dist != dist[curr.dest][curr.length]) {
      continue;
    }

    for (const auto &next : adj_list[curr.dest]) {
      int next_dist = next.cost + curr.dist;
      if (next_dist < min_dist[next.dest]) {
        min_dist[next.dest] = dist[next.dest][curr.length + 1] = next_dist;
        Q.emplace(next.dest, next_dist, curr.length + 1);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M >> K >> S >> D;

  int a, b, w;
  for (int i = 0; i < M; ++i) {
    std::cin >> a >> b >> w;
    adj_list[a].emplace_back(b, w);
    adj_list[b].emplace_back(a, w);
  }

  for (int i = 1; i <= K; ++i) {
    std::cin >> cost_increase[i];
  }

  BFS();

  int tot_increase = 0;
  for (int i = 0; i <= K; ++i) {
    int min_dist = INF;
    tot_increase += cost_increase[i];
    for (int j = 0; j < N; ++j) {
      if (dist[D][j] != INF) {
        min_dist = min(dist[D][j] + tot_increase * j, min_dist);
      }
    }
    std::cout << min_dist << "\n";
  }

  return 0;
}