#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2147000000
#define S_SELECTOR 0
#define G_SELECTOR 1
#define H_SELECTOR 2

typedef std::pair<int, int> pii;

int T, n, m, t, S, g, h;
std::vector<pii> adj_list[2001];
int dist[3][2001];
std::vector<int> answers;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

void dijkstra(int s)
{
  int selector;
  if(s == S) selector = S_SELECTOR;
  else if(s == g) selector = G_SELECTOR;
  else if(s == h) selector = H_SELECTOR;

  Q.push(pii(0, s));
  dist[selector][s] = 0;

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int u = curr.second, d_u = curr.first;

    if(dist[selector][u] < d_u) continue;

    for(auto next : adj_list[u]) {
      int v = next.first, w_uv = next.second;
      if(dist[selector][v] > d_u + w_uv) {
        dist[selector][v] = d_u + w_uv;
        Q.push(pii(d_u + w_uv, v));
      }
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> T;
  for(int test_case = 0; test_case < T; ++test_case) {
    for(int i = 1; i <= 2000; ++i) {
      adj_list[i].clear();
      for(int j = 0; j < 3; ++j)
        dist[j][i] = INF;
    }
    answers.clear();

    std::cin >> n >> m >> t >> S >> g >> h;

    for(int i = 0; i < m; ++i) {
      int a, b, d;
      std::cin >> a >> b >> d;
      adj_list[a].push_back(pii(b, d));
      adj_list[b].push_back(pii(a, d));
    }

    dijkstra(S); 
    int second = (dist[S_SELECTOR][g] < dist[S_SELECTOR][h] ? h : g);
    dijkstra(g); dijkstra(second);

    for(int i = 0; i < t; ++i) {
      int candidate;
      std::cin >> candidate;
      if(second == h &&
         dist[S_SEL][g] + dist[H_SEL][g] + dist[H_SEL][candidate] == dist[S_SEL][candidate])
         answers.push_back(candidate);
      else if(second == g &&
         dist[S_SEL][h] + dist[G_SEL][h] + dist[G_SEL][candidate] == dist[S_SEL][candidate])
         answers.push_back(candidate);
    }

    std::sort(answers.begin(), answers.end());
    for(auto i : answers)
      std::cout << i << " ";
    std::cout << "\n";
  }

  return 0;
}