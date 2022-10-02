#include <iostream>
#include <vector>
#include <queue>

#define min(a, b) (a < b ? a : b)

#define INF 0x7fffffff

struct Edge {
  Edge(int _dst = 0, int _cost = 0) : dst(_dst), cost(_cost) {}
  int dst;
  int cost;
};

struct Entry {
  Entry(int _dst = 0, int _cost = 0) : dst(_dst), cost(_cost) {}
  int dst;
  int cost;
};

bool operator>(const Entry &lhs, const Entry &rhs) {
  return lhs.cost > rhs.cost;
}

int V, E;
std::vector<Edge> adj_list[401];

int find_min_cycle(int start) {
  int ret = INF;

  std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> PQ;
  int cost[401];

  for (int i = 1; i <= V; ++i) {
    cost[i] = INF;
  }

  PQ.emplace(start, 0);
  cost[start] = 0;

  while (!PQ.empty()) {
    auto curr = PQ.top();
    PQ.pop();

    if (cost[curr.dst] < curr.cost) {
      continue;
    }

    for (const auto &next : adj_list[curr.dst]) {
      int ncost = curr.cost + next.cost;
      if (next.dst == start) {
        ret = min(ncost, ret);
      }
      if (ncost < cost[next.dst]) {
        PQ.emplace(next.dst, ncost);
        cost[next.dst] = ncost;
      }
    }
  }

  return ret;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> V >> E;

  for (int i = 0; i < E; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    adj_list[a].emplace_back(b, c);
  }

  int ans = INF;
  for (int start = 1; start <= V; ++start) {
    ans = min(ans, find_min_cycle(start));
  }

  std::cout << (ans == INF ? -1 : ans) << "\n";

  return 0;
}