#include <iostream>

#define INF 1000000001

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int n, m;
int d[101][101];
int next[101][101];

int main()
{
  std::cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(i == j) {
        d[i][j] = 0;
        next[i][j] = i;
      } else
        d[i][j] = INF;
    }
  }

  for(int i = 0; i < m; ++i) {
    int source, dest, dist;
    std::cin >> source >> dest >> dist;
    if(d[source][dest] > dist) {
      d[source][dest] = dist;
      next[source][dest] = dest;
    }
  }

  for(int k = 1; k <= n; ++k) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        if(d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      std::cout << (d[i][j] == INF ? 0 : d[i][j]) << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

  /*
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      std::cout << next[i][j] << " ";
    }
    std::cout << "\n";
  }
  */

  return 0;
}