#include <iostream>
#include <queue>
#include <cmath>

typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;
typedef std::pair<double, int> pdi;

inline double dist(const pdd &lhs, const pdd &rhs)
{
  return sqrt((lhs.first - rhs.first) * (lhs.first - rhs.first) +
         (lhs.second - rhs.second) * (lhs.second - rhs.second));
}

int N;
pdd stars[100];
bool inSet[100];

std::priority_queue<pdi, std::vector<pdi>, std::greater<pdi>> Q;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> N;
  for(int i = 0; i < N; ++i) 
    std::cin >> stars[i].first >> stars[i].second;

  double ans = 0;
  Q.push(pdi(0.0, 0));

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second;
    double d_u = curr.first;
    
    if(inSet[u]) continue;

    ans += d_u;
    inSet[u] = true;

    for(int v = 0; v < N; ++v) {
      if(inSet[v]) continue;
      Q.push(pdi(dist(stars[v], stars[u]), v));
    }
  }

  std::cout << ans << std::endl;

  return 0;
}