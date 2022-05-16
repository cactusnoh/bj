#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, std::pair<int, int>> pipii;
typedef std::pair<int, int> pii;

int V, E;
std::vector<pipii> adj_list;
int parent[10001], rank[10001];

int getParent(int a)
{
  if(parent[a] == a)
    return a;
  return parent[a] = getParent(parent[a]);
}

void unionize(int a, int b)
{
  a = getParent(a); 
  b = getParent(b);

  if(a == b)  
    return;

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

  std::cin >> V >> E;

  for(int i = 1; i <= V; ++i)
    parent[i] = i;

  for(int i = 0; i < E; ++i) {
    int src, dst, w;
    std::cin >> src >> dst >> w;
    adj_list.push_back(pipii(w, pii(src, dst)));
  }

  std::sort(adj_list.begin(), adj_list.end());

  int ans = 0;
  for(int i = 0; i < adj_list.size(); ++i) {
    auto curr = adj_list[i];
    int w = curr.first, src = curr.second.first, dst = curr.second.second;
    if(getParent(src) == getParent(dst))
      continue;
    unionize(src, dst);
    ans += w;
  }

  std::cout << ans << std::endl;
  
  return 0;
}