#include <iostream>
#include <vector>
#include <queue>

using Node = int;
using Distance = int;
using pnd = std::pair<Node, Distance>;

int N, M, S, D;

int indegree[10'001];
std::vector<pnd> adj_list[10'001];
std::vector<Node> parent[10'001];

std::vector<Node> Order;
bool visited[10'001];

int CountRoads() {
  int ans = 0;
  bool visited[10'001] = {0};
  std::queue<Node> Q;

  visited[D] = true;
  Q.push(D);

  while (!Q.empty()) {
    Node curr = Q.front();
    Q.pop();

    ans += parent[curr].size();

    for (Node p : parent[curr]) {
      if (!visited[p]) {
        visited[p] = true;
        Q.push(p);
      }
    }
  }

  return ans;
}

void TopologicalSort() {
  std::queue<Node> Q;

  Q.push(S);

  while (!Q.empty()) {
    Node u = Q.front();
    Q.pop();

    Order.push_back(u);

    for (const auto &next : adj_list[u]) {
      Node v = next.first;

      if (--indegree[v] == 0) {
        Q.push(v);
      }
    }
  }
}

int GetMaxDist() {
  Distance dists[10'001] = {0};

  for (size_t i = 0; i < Order.size(); ++i) {
    Node u = Order[i];
    for (const auto &next : adj_list[u]) {
      Node v = next.first;
      Distance cand_dist = dists[u] + next.second;
      if (cand_dist >= dists[v]) {
        if (cand_dist > dists[v]) {
          dists[v] = cand_dist;
          parent[v] = {};
        }
        parent[v].push_back(u);
      }
    }
  }

  return dists[D];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M;

  Node u, v;
  Distance d;

  for (int i = 0; i < M; ++i) {
    std::cin >> u >> v >> d;
    adj_list[u].push_back(pnd(v, d));
    indegree[v]++;
  }

  std::cin >> S >> D;

  TopologicalSort();

  std::cout << GetMaxDist() << "\n";
  std::cout << CountRoads() << "\n";

  return 0;
}