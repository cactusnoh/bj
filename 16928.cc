#include <iostream>
#include <queue>

typedef std::pair<int, int> pii;

int N, M;
int teleport[101];
bool visited[101];
std::queue<pii> Q;

void BFS()
{
  visited[1] = true;
  Q.push(pii(1, 0));
  
  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    int u = curr.first, level = curr.second;
    for(int i = 1; i <= 6; ++i) {
      if(u + i > 100) continue;
      if(u + i == 100) {
        std::cout << level + 1 << std::endl;
        return;
      }
      if(visited[teleport[u + i]]) continue;
      Q.push(pii(teleport[u + i], level + 1));
      visited[teleport[u + i]] = true;
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;

  for(int i = 1; i < 101; ++i)
    teleport[i] = i;

  for(int i = 0; i < N + M; ++i) {
    int src, dst;
    std::cin >> src >> dst;
    teleport[src] = dst;
  }

  BFS();

  return 0;
}