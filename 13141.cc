#include <iostream>
#include <vector>

#define INF 2147000000

using dist_t = int;
using pii = std::pair<int, int>;
using piid = std::pair<pii, dist_t>;

template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}

template <typename T>
inline T max(T a, T b) {
  return a < b ? b : a;
}

int N, M;
int dist[201][201];
piid edges[20001]; 

int main() {
  std::cin >> N >> M;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      dist[i][j] = INF;
    }
    dist[i][i] = 0;
  }

  int S, E, L;
  for (int i = 0; i < M; ++i) {
    std::cin >> S >> E >> L;
    dist[S][E] = dist[E][S] = min(dist[S][E], L);
    edges[i] = piid(pii(S, E), L);
  }

  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (dist[i][k] != INF && dist[k][j] != INF) {
          dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  double min_time = 2147000000.0;

  for (int i = 1; i <= N; ++i) {
    double local_max = 0;
    for (int j = 0; j < M; ++j) {
      piid e = edges[j];
      int S = e.first.first;
      int E = e.first.second;
      dist_t L = e.second;
      local_max = max<double>(local_max, (dist[i][S] + dist[i][E] + L) / 2.0);
    }
    min_time = min<double>(min_time, local_max);
  }

  std::cout.precision(1);
  std::cout << std::fixed << min_time << std::endl;

  return 0;
}