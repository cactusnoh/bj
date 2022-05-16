#include <iostream>

#define INF 2147000000

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int N, M, R;
int items[101];
int dist[101][101];

int main()
{
  std::cin >> N >> M >> R;

  for(int i = 1; i <= N; ++i) {
    std::cin >> items[i];
    for(int j = 1; j <= N; ++j)
      dist[i][j] = INF;
    dist[i][i] = 0;
  }
  
  for(int i = 0; i < R; ++i) {
    int src, dst, w;
    std::cin >> src >> dst >> w;
    dist[src][dst] = w;
    dist[dst][src] = w;
  }

  for(int k = 1; k <= N; ++k) {
    for(int i = 1; i <= N; ++i) {
      for(int j = 1; j <= N; ++j) {
        if(dist[i][k] == INF || dist[k][j] == INF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int max_item = 0;

  for(int i = 1; i <= N; ++i) {
    int item_cnt = 0;
    for(int j = 1; j <= N; ++j) {
      if(dist[i][j] > M) continue;
      item_cnt += items[j];
    }
    if(item_cnt > max_item)
      max_item = item_cnt;
  }

  std::cout << max_item << std::endl;

  return 0;
}