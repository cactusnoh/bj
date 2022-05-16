#include <iostream>

#define INF 987654321

int min(int a, int b)
{
  return a < b ? a : b;
}

int n, m;
int dist[101][101];

int main()
{
  std::cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      dist[i][j] = (i == j ? 0 : INF);

  for(int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    dist[a][b] = min(c, dist[a][b]);
  }

  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        if(dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j)
      std::cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
    std::cout << "\n";
  }

  return 0;
}