#include <iostream>

int N, M;
int parent[1001], rank[1001];

int find_set(int n)
{
  if(parent[n] == n)
    return n;
  return (parent[n] = find_set(parent[n]));
}

void union_sets(int a, int b)
{
  a = find_set(a);
  b = find_set(b);
  if(a != b) {
    if(rank[a] < rank[b]) {
      int temp = a;
      a = b;
      b = temp;
    }
    parent[b] = a;
    if(rank[a] == rank[b])
      rank[a]++;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> N >> M;

  for(int i = 1; i <= N; ++i) {
    rank[i] = 0;
    parent[i] = i;
  }
  
  for(int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v; 
    union_sets(u, v);
  }

  return 0;
}