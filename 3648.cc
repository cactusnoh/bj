#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

int N, M;
std::vector<int> adj[2001];   // adjacency list
std::vector<int> adjT[2001];  // adjacency list transposed

inline int abs(int a) {
  return a < 0 ? -a : a;
}
inline int get_node(int n) {
  return n > 0 ? n : -n + N;
}
inline int get_negation(int n) {
  return n > 0 ? n + N : -n;
}

// korsaju SCC
bool visited[2001];
std::vector<int> order;
int comp[2001];
void DFS_1(int curr) {
  visited[curr] = true;
  for (auto next : adj[curr]) {
    if (!visited[next]) {
      DFS_1(next);
    }
  }
  order.push_back(curr);
}
void DFS_2(int curr, int comp_num) {
  visited[curr] = true;
  comp[curr] = comp_num;
  for (auto next : adjT[curr]) {
    if (!visited[next]) {
      DFS_2(next, comp_num);
    }
  }
}

// BFS to find out path exists
bool path_exists(int s, int e) {
  bool visited[2001] = {false};
  std::queue<int> Q;

  Q.push(s);
  visited[s] = true;

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    if (curr == e) {
      return true;
    }

    for (int next : adj[curr]) {
      if (!visited[next]) {
        Q.push(next);
        visited[next] = true;
      }
    }
  }

  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  while (std::cin >> N >> M) {
    // reset stuff
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= 2000; ++i) {
      adj[i].clear();
      adjT[i].clear();
    }

    // map building
    for (int i = 0; i < M; ++i) {
      int a, b;
      std::cin >> a >> b;
      // add to adjacency list
      adj[get_negation(a)].emplace_back(get_node(b));
      adj[get_negation(b)].emplace_back(get_node(a));
      // add to transposed adjacency list
      adjT[get_node(b)].emplace_back(get_negation(a));
      adjT[get_node(a)].emplace_back(get_negation(b));
    }

    // korsaju SCC
    for (int i = 2 * N; i >= 1; --i) {
      if (!visited[i]) {
        DFS_1(i);
      }
    }
    memset(visited, false, sizeof(visited));
    int comp_cnt = 0;
    for (auto it = order.rbegin(); it != order.rend(); ++it) {
      if (!visited[*it]) {
        DFS_2(*it, comp_cnt++);
      }
    }

    // check 2-SAT
    bool fail = false;
    for (int i = 1; i <= N; ++i) {
      if (comp[i] == comp[get_negation(i)]) {
        fail = true;
        break;
      }
    }

    if (path_exists(1, get_negation(1)) && comp[1] < comp[get_negation(1)]) {
      fail = true;
    }

    std::cout << (fail ? "no" : "yes") << "\n";
  }

  return 0;
}