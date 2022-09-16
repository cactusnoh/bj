#include <iostream>
#include <vector>
#include <queue>

#define INF 0x7fffffff
#define min(a, b) (a < b ? a : b)

struct Edge {
  Edge(int _dst = 0, int _cost = 0, int _time = 0) : dst(_dst), cost(_cost), time(_time) {}
  int dst;
  int cost;
  int time;
};

struct Entry {
  Entry(int _dst = 0, int _cost = 0, int _time = 0) : dst(_dst), cost(_cost), time(_time) {}
  int dst;
  int cost;
  int time;
};

bool operator>(const Entry &lhs, const Entry &rhs) {
  return lhs.time > rhs.time;
}

int TC;
int N, M, K;
std::vector<Edge> adj_list[10'001];

int dijkstra() {
  // using priority queue was slower; used queue instead
  // std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> PQ;
  std::queue<Entry> Q;

  // initialize all elements of min_time to INF
  int min_time[101][10'001];
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      min_time[i][j] = INF;
    }
  }

  // PQ.emplace(1, 0, 0); 
  Q.emplace(1, 0, 0);
  min_time[1][0] = 0;
  while (!Q.empty() /*!PQ.empty()*/) {
    // auto curr = PQ.top();
    // PQ.pop();
    auto curr = Q.front();
    Q.pop();

    if (min_time[curr.dst][curr.cost] < curr.time) {
      continue;
    }

    for (const auto next : adj_list[curr.dst]) {
      int ndst = next.dst;
      int ncost = next.cost + curr.cost;
      int ntime = next.time + curr.time;
      if (ncost <= M && ntime < min_time[ndst][ncost]) {
        for (int c = ncost; c <= M; ++c) {
          if (ntime < min_time[ndst][c]) {
            min_time[ndst][c] = ntime;
          } else {
            break;  // this contributes very much to the execution time
          }
          // min_time[ndst][c] = min(min_time[ndst][c], ntime);
        }
        // PQ.emplace(ndst, ncost, ntime);
        Q.emplace(ndst, ncost, ntime);
      }
    }
  }

  int ret = 0x7fffffff;
  for (int i = 0; i <= M; ++i) {
    ret = min(ret, min_time[N][i]);
  }
  return ret;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> TC;
  for (int t = 1; t <= TC; ++t) {
    // Get input
    std::cin >> N >> M >> K;

    // Clear adjacency list
    for (int i = 1; i <= N; ++i) {
      adj_list[i].clear();
    }
    
    // Get input
    for (int i = 0; i < K; ++i) {
      int u, v, c, d;
      std::cin >> u >> v >> c >> d;
      adj_list[u].emplace_back(v, c, d);
    }

    // Do dijkstra
    int min_cost = dijkstra();
    if (min_cost == INF) {
      std::cout << "Poor KCM" << "\n";
    } else {
      std::cout << min_cost << "\n";
    }
  }

  return 0;
}