#include <iostream>
#include <vector>
#include <algorithm>

using Node = int;

inline int min(int a, int b) {
  return a < b ? a : b;
}

int V, E;

int timer;

int low[10'001];
int t_in[10'001];
bool visited[10'001];

std::vector<Node> adj_list[10'001];

int articulation_cnt;
bool articulation_point[10'001];

void DFS(Node n, Node prev = -1) {
  int children = 0;
  visited[n] = true;
  t_in[n] = low[n] = ++timer;

  for (Node next : adj_list[n]) {
    if (next == prev) {
      continue;
    }
    if (visited[next]) {
      low[n] = min(low[n], t_in[next]);
    } else {
      DFS(next, n);
      ++children;
      low[n] = min(low[n], low[next]);
      if (!articulation_point[n] && low[next] >= t_in[n] && prev != -1) {
        ++articulation_cnt;
        articulation_point[n] = true;
      }
    }
  }

  if (prev == -1 && children > 1) {
    ++articulation_cnt;
    articulation_point[n] = true;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> V >> E;

  for (int i = 0; i < E; ++i) {
    Node A, B;
    std::cin >> A >> B;
    adj_list[A].push_back(B);
    adj_list[B].push_back(A);
  }

  for (Node i = 1; i <= V; ++i) {
    if (!visited[i]) {
      DFS(i);
    }
  }

  std::cout << articulation_cnt << "\n";
  for (Node i = 1; i <= V; ++i) {
    if (articulation_point[i]) {
      std::cout << i << " "; 
    }
  }
  std::cout << std::endl;

  return 0;
}