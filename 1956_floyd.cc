#include <iostream>

#define min(a, b) (a < b ? a : b)

#define INF 0x7fffffff

int V, E;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // Get input
  std::cin >> V >> E;

  int cost[401][401];

  // Initialize cost matrix
  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      cost[i][j] = INF;
    }
  }

  // Get input of adjacency relationship
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    cost[a][b] = c;
  }

  // Do Floyd-Warshall (All-Pairs Shortest-Path)
  for (int k = 1; k <= V; ++k) {
    for (int i = 1; i <= V; ++i) {
      for (int j = 1; j <= V; ++j) {
        if (cost[i][k] != INF && cost[k][j] != INF &&
            cost[i][k] + cost[k][j] < cost[i][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
        }
      }
    }
  }

  // For every vertex, find minimum cycle cost
  int ans = INF;
  for (int start = 1; start <= V; ++start) {
    ans = min(cost[start][start], ans);
  }

  std::cout << (ans == INF ? -1 : ans) << "\n";

  return 0;
}