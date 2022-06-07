#include <iostream>
#include <vector>
#include <queue>

#define LOG 15

typedef int Node;
typedef int Dist;
typedef std::pair<Node, Dist> pnd;

int N, M;
std::vector<pnd> adj_list[40'001];

int level[40'001];
Node parent[40'001][LOG + 1];
Dist dist[40'001][LOG + 1];

void build_tree()
{
  bool visited[40'001] = {0};
  std::queue<Node> Q;

  visited[1] = true;
  level[1] = 1;
  Q.push(1);

  while (!Q.empty()) {
    Node curr = Q.front();
    Q.pop();

    for (const auto &n : adj_list[curr]) {
      Node child = n.first;
      Dist d = n.second;

      if (!visited[child]) {
        visited[child] = true;

        parent[child][0] = curr;
        dist[child][0] = d;
        level[child] = level[curr] + 1;

        Q.push(child);
      }
    }
  }

  for (int i = 1; i <= LOG; ++i) {
    for (Node curr = 2; curr <= N; ++curr) {
      parent[curr][i] = parent[parent[curr][i - 1]][i - 1];
      dist[curr][i] = dist[curr][i - 1] + dist[parent[curr][i - 1]][i - 1];
    }
  }
}

Dist solve(Node u, Node v)
{
  Dist ans = 0;

  if (level[u] > level[v]) {
    Node temp = u;
    u = v;
    v = temp;
  }

  for (int i = LOG; i >= 0; --i) {
    if (parent[v][i] != 0 && level[parent[v][i]] >= level[u]) {
      ans += dist[v][i];
      v = parent[v][i];
    }
  }

  if (u == v) {
    return ans;
  }

  for (int i = LOG; i >= 0; --i) {
    if (parent[u][i] != parent[v][i]) {
      ans += dist[u][i] + dist[v][i];
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  ans += dist[u][0] + dist[v][0];

  return ans;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;

  Node u, v;
  Dist d_uv;
  for (int i = 0; i < N - 1; ++i) {
    std::cin >> u >> v >> d_uv;
    adj_list[u].push_back(pnd(v, d_uv));
    adj_list[v].push_back(pnd(u, d_uv));
  }

  build_tree();

  std::cin >> M;

  for (int i = 0; i < M; ++i) {
    std::cin >> u >> v;
    std::cout << solve(u, v) << "\n";
  }

  return 0;
}