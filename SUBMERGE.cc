#include <iostream>
#include <vector>

inline int min(int a, int b) {
  return a < b ? a : b;
}

int N, M;
std::vector<int> adj_list[10'001];

int timer;
int t_in[10'001];
int low[10'001];
bool visited[10'001];

bool is_arti[10'001];

void DFS(int curr, int prev = -1) {
  int child_cnt = 0;
  visited[curr] = true;
  t_in[curr] = low[curr] = ++timer;

  for (int next : adj_list[curr]) {
    if (next == prev) {
      continue;
    }
    if (visited[next]) {
      low[curr] = min(low[curr], t_in[next]);
    } else {
      ++child_cnt;
      DFS(next, curr);
      low[curr] = min(low[curr], low[next]);
      if (prev != -1 && low[next] >= t_in[curr]) {
        is_arti[curr] = true;
      }
    }
  }
  if (prev == -1 && child_cnt > 1) {
    is_arti[curr] = true;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  while (1) {
    std::cin >> N >> M;

    if (N == 0 && M == 0) {
      break;
    }

    timer = 0;
    for (int i = 1; i <= N; ++i) {
      adj_list[i].clear();
      visited[i] = false;
      is_arti[i] = false;
      t_in[i] = 0;
      low[i] = 0;
    }

    for (int i = 0; i < M; ++i) {
      int u, v;
      std::cin >> u >> v;
      adj_list[u].push_back(v);
      adj_list[v].push_back(u); 
    }

    for (int i = 1; i <= N; ++i) {
      if (!visited[i]) {
        DFS(i);
      }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (is_arti[i]) {
        ++ans;
      }
    }
    std::cout << ans << "\n";
  }

  return 0;
}