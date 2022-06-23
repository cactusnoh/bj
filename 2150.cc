#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

int V, E;

std::vector<int> adj_list[10'001];
std::vector<int> rev_adj_list[10'001];

std::vector<int> order;
bool visited[10'001];

std::vector<int> component;
std::vector<std::vector<int>> SCCs;

void DFS1(int n) {
  visited[n] = true;

  for (auto i : adj_list[n]) {
    if (!visited[i]) {
      DFS1(i);
    }
  }

  order.push_back(n);
}

void DFS2(int n) {
  visited[n] = true;
  component.push_back(n);

  for (auto i : rev_adj_list[n]) {
    if (!visited[i]) {
      DFS2(i);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> V >> E;

  int A, B;
  for (int i = 0; i < E; ++i) {
    std::cin >> A >> B;
    adj_list[A].push_back(B);
    rev_adj_list[B].push_back(A);
  }

  for (int i = 1; i <= V; ++i) {
    if (!visited[i]) {
      DFS1(i);
    }
  }
  memset(visited, 0, sizeof(visited));

  for (int i = order.size() - 1; i >= 0; --i) {
    if (!visited[order[i]]) {
      DFS2(order[i]);

      std::sort(component.begin(), component.end());
      SCCs.push_back(component);
      component.clear();
    }
  }

  std::sort(SCCs.begin(), SCCs.end());

  std::cout << SCCs.size() << "\n";
  for (const auto &c : SCCs) {
    for (auto i : c) {
      std::cout << i << " ";
    }
    std::cout << -1 << "\n";
  }

  return 0;
}