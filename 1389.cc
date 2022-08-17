#include <iostream>
#include <vector>
#include <queue>

int N, M;
int bacon[101];
std::vector<int> adj_list[101];

void BFS(int n) {
  std::queue<int> Q;
  bool visited[101] = {false};
  int dist[101];

  Q.push(n);
  visited[n] = true;
  dist[n] = 0;

  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();

    for (int next : adj_list[curr]) {
      if (!visited[next]) {
        dist[next] = dist[curr] + 1;
        visited[next] = true;
        Q.push(next);
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    bacon[n] += dist[i];
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M;

  int a, b;
  for (int i = 0; i < M; ++i) {
    std::cin >> a >> b;
    adj_list[a].emplace_back(b);
    adj_list[b].emplace_back(a);
  }

  int min_bacon = 0x7fffffff;
  int min_entry = 0;
  for (int i = 1; i <= N; ++i) {
    BFS(i);
    if (bacon[i] < min_bacon) {
      min_bacon = bacon[i];
      min_entry = i;
    }
  }

  std::cout << min_entry << "\n";

  return 0;
}