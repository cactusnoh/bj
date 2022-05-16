#include <iostream>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> pii;
typedef std::pair<int, std::pair<int,int>> pipii;

int N, parent[100001], rank[100001];
pii x[100001], y[100001], z[100001];
std::vector<pipii> edges;
long long ans;

int getParent(int x)
{
  if(parent[x] == x)
    return x;
  return (parent[x] = getParent(parent[x]));
}

void unionize(int a, int b)
{
  a = getParent(a);
  b = getParent(b);

  if(rank[a] < rank[b]) {
    int temp = a;
    a = b;
    b = temp;
  }

  if(rank[a] == rank[b])
    ++rank[a];
  parent[b] = a;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> x[i].first >> y[i].first >> z[i].first;
    x[i].second = y[i].second = z[i].second = i;
    parent[i] = i;
  }

  std::sort(x, x + N);
  std::sort(y, y + N);
  std::sort(z, z + N);

  for(int i = 0; i < N - 1; ++i) {
    edges.push_back(pipii(x[i + 1].first - x[i].first, pii(x[i].second, x[i + 1].second)));
    edges.push_back(pipii(y[i + 1].first - y[i].first, pii(y[i].second, y[i + 1].second)));
    edges.push_back(pipii(z[i + 1].first - z[i].first, pii(z[i].second, z[i + 1].second)));
  }
  std::sort(edges.begin(), edges.end());

  long long ans = 0;
  for(int i = 0; i < edges.size(); ++i) {
    auto edge = edges[i];
    int edge_len = edge.first, u = edge.second.first, v = edge.second.second;

    if(getParent(u) == getParent(v))
      continue;
    unionize(u, v);
    ans += edge_len;
  }

  std::cout << ans << std::endl;

  return 0;
}