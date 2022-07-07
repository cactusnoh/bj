#include <iostream>
#include <vector>
#include <queue>

#define LOG 16

struct Edge {
  int dest;
  int cost;
};

inline int min(int a, int b) {
  return a < b ? a : b;
}
inline int max(int a, int b) {
  return a < b ? b : a;
}

int N;
int K;

std::vector<Edge> adj_list[100'001];
bool visited[100'001];

int level[100'001];
int parent[100'001][LOG + 1];
int max_cost[100'001][LOG + 1];
int min_cost[100'001][LOG + 1];

void build_tree() {
  std::queue<int> Q;

  Q.push(1);
  visited[1] = true;
  level[1] = 1;

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();
    for (auto e : adj_list[curr]) {
      if (!visited[e.dest]) {
        visited[e.dest] = true;
        level[e.dest] = level[curr] + 1;
        parent[e.dest][0] = curr;
        max_cost[e.dest][0] = e.cost;
        min_cost[e.dest][0] = e.cost;
        Q.push(e.dest);
      }
    }
  }
}

void solve(int a, int b) {
  int max_ret = 0, min_ret = 1'000'001;

  if (level[a] > level[b]) {
    int temp = a;
    a = b;
    b = temp;
  }

  for (int i = LOG; i >= 0; --i) {
    if (level[parent[b][i]] >= level[a]) {
      max_ret = max(max_ret, max_cost[b][i]);
      min_ret = min(min_ret, min_cost[b][i]);
      b = parent[b][i];
    }
  }

  if (a == b) {
    std::cout << min_ret << " " << max_ret << "\n";
    return;
  }

  for (int i = LOG; i >= 0; --i) {
    if (parent[b][i] != parent[a][i]) {
      max_ret = max(max_ret, max_cost[a][i]);
      max_ret = max(max_ret, max_cost[b][i]);
      min_ret = min(min_ret, min_cost[a][i]);
      min_ret = min(min_ret, min_cost[b][i]);
      a = parent[a][i];
      b = parent[b][i];
    }
  }

  max_ret = max(max_ret, max_cost[a][0]);
  max_ret = max(max_ret, max_cost[b][0]);
  min_ret = min(min_ret, min_cost[a][0]);
  min_ret = min(min_ret, min_cost[b][0]);
  a = parent[a][0];
  b = parent[b][0];

  std::cout << min_ret << " " << max_ret << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;

  for (int i = 0; i < N - 1; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    adj_list[a].push_back(Edge{b, c});
    adj_list[b].push_back(Edge{a, c});
  }

  build_tree();

  for (int i = 1; i <= LOG; ++i) {
    for (int n = 1; n <= N; ++n) {
      parent[n][i] = parent[parent[n][i - 1]][i - 1];
      max_cost[n][i] = max(max_cost[n][i - 1], max_cost[parent[n][i - 1]][i - 1]);
      min_cost[n][i] = min(min_cost[n][i - 1], min_cost[parent[n][i - 1]][i - 1]);
    }
  }

  std::cin >> K;

  for (int i = 0; i < K; ++i) {
    int D, E;
    std::cin >> D >> E;
    solve(D, E);
  }

  return 0;
}