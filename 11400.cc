#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
  bool operator<(const Edge &other) const {
    if (begin == other.begin) {
      return end < other.end;
    }
    return begin < other.begin;
  }
  int begin;
  int end;
};

inline int min(int a, int b) {
  return a < b ? a : b;
}
inline int max(int a, int b) {
  return a < b ? b : a;
}

int V, E;
std::vector<int> adj_list[100'001];

int timer;
int t_in[100'001];
int low[100'001];
bool visited[100'001];

std::vector<Edge> bridges;

void DFS(int curr, int prev = -1) {
  visited[curr] = true;
  t_in[curr] = low[curr] = ++timer;

  for (auto next : adj_list[curr]) {
    if (next == prev) {
      continue;
    }
    if (visited[next]) {
      low[curr] = min(low[curr], t_in[next]);
    } else {
      DFS(next, curr);
      low[curr] = min(low[curr], low[next]);
      if (low[next] > t_in[curr]) {
        bridges.push_back(Edge{min(curr, next), max(curr, next)});
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> V >> E;

  for (int i = 0; i < E; ++i) {
    int A, B;
    std::cin >> A >> B;
    adj_list[A].push_back(B);
    adj_list[B].push_back(A);
  }

  for (int i = 1; i <= V; ++i) {
    if (!visited[i]) {
      DFS(i);
    }
  }

  std::sort(bridges.begin(), bridges.end());

  std::cout << bridges.size() << "\n";
  for (auto e : bridges) {
    std::cout << e.begin << " " << e.end << "\n";
  }

  return 0;
}