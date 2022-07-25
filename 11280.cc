#include <iostream>
#include <vector>
#include <cstring>

int N, M;
std::vector<int> adj[20001], adj_t[20001];

inline int VertexNumber(int n) {
  return n > 0 ? n : -n + N;
}

bool visited[20001];
std::vector<int> order;
void DFS1(int n) {
  visited[n] = true;

  for (auto next : adj[n]) {
    if (!visited[next]) {
      DFS1(next);
    }
  }

  order.push_back(n);
}

int comp[20001];
void DFS2(int n, int c) {
  visited[n] = true;
  comp[n] = c;

  for (auto next : adj_t[n]) {
    if (!visited[next]) {
      DFS2(next, c);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M;

  for (int c = 0; c < M; ++c) {
    int i, j;
    std::cin >> i >> j;
    adj[VertexNumber(-i)].push_back(VertexNumber(j));
    adj_t[VertexNumber(j)].push_back(VertexNumber(-i));
    adj[VertexNumber(-j)].push_back(VertexNumber(i));
    adj_t[VertexNumber(i)].push_back(VertexNumber(-j));
  }

  for (int i = 1; i <= 2 * N; ++i) {
    if (!visited[i]) {
      DFS1(i);
    }
  }

  memset(visited, 0, sizeof(visited));

  int comp_cnt = 0;
  for (int i = order.size() - 1; i >= 0; --i) {
    if (!visited[order[i]]) {
      DFS2(order[i], comp_cnt++);
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (comp[i] == comp[i + N]) {
      std::cout << 0 << "\n";
      return 0;
    }
  }

  std::cout << 1 << "\n";

  return 0;
}