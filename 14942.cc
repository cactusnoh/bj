#include <iostream>
#include <vector>

#define LOG 16

struct Edge {
  int dest;
  int cost;
};

int N;
int parent[100'001][LOG + 1];
int dist[100'001][LOG + 1];
int energy[100'001];

std::vector<Edge> adj_list[100'001];
bool visited[100'001];

void DFS(int node) {
  visited[node] = true;
  for (const auto &e : adj_list[node]) {
    if (!visited[e.dest]) {
      visited[e.dest] = true;
      parent[e.dest][0] = node;
      dist[e.dest][0] = e.cost;
      DFS(e.dest);
    }
  }
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;

  for (int i = 1; i <= N; ++i) {
    std::cin >> energy[i];
  }

  int a, b, c;
  for (int i = 0; i < N - 1; ++i) {
    std::cin >> a >> b >> c;
    adj_list[a].push_back(Edge{b, c});
    adj_list[b].push_back(Edge{a, c});
  }
  DFS(1);

  for (int level = 1; level <= LOG; ++level) {
    for (int node = 2; node <= N; ++node) {
      parent[node][level] = parent[parent[node][level - 1]][level - 1];
      dist[node][level] = dist[parent[node][level - 1]][level - 1] + dist[node][level - 1];
    }
  }

  for (int node = 1; node <= N; ++node) {
    int energy_left = energy[node];
    int curr = node;
    for (int level = LOG; level >= 0; --level) {
      if (parent[curr][level] != 0 && dist[curr][level] <= energy_left) {
        energy_left -= dist[curr][level];
        curr = parent[curr][level];
      }
    }
    std::cout << curr << "\n";
  }

  return 0;
}