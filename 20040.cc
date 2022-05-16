#include <iostream>

int N, M;

int parent[500001], rank[500001];

int getParent(int a)
{
  if(parent[a] == a)
    return a;
  return (parent[a] = getParent(parent[a]));
}

bool unionize(int a, int b)
{
  a = getParent(a);
  b = getParent(b);

  if(a == b) return false;

  if(rank[a] < rank[b]) {
    int temp = a;
    a = b;
    b = temp;
  }

  if(rank[a] == rank[b])
    ++rank[a];

  parent[b] = a;
  return true;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;

  for(int i = 0; i < N; ++i)
    parent[i] = i;

  for(int i = 1; i <= M; ++i) {
    int src, dst;
    std::cin >> src >> dst;
    if(unionize(src, dst)) continue;
    std::cout << i << std::endl;
    return 0;
  }
  std::cout << 0 << std::endl;

  return 0;
}