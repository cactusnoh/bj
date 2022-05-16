#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> pii;

int N, M;
std::vector<pii> adj_list[100001];

bool inSet[100001];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int src, dst, cost;
    std::cin >> src >> dst >> cost;
    adj_list[src].push_back(pii(dst, cost));
    adj_list[dst].push_back(pii(src, cost));
  }

  Q.push(pii(0, 1));
  
  int sum = 0, max_path = 0;

  while(!Q.empty()) {
    int u = Q.top().second, d_u = Q.top().first;
    Q.pop();

    if(inSet[u]) continue;
    
    sum += d_u;
    if(d_u > max_path)
      max_path = d_u;
    inSet[u] = true;

    for(auto next : adj_list[u])
      if(!inSet[next.first])
        Q.push(pii(next.second, next.first));
  }

  std::cout << sum - max_path << std::endl;

  return 0;
}