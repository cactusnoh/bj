#include <iostream>
#include <vector>
#include <queue>

int N, e;
bool visited[101];
std::vector<int> adj[101];

void BFS(int start)
{
  visited[start] = true;
  std::queue<int> frontier;
  frontier.push(start);

  while(!frontier.empty()) {
    int x = frontier.front();
    frontier.pop();
    for(int i : adj[x]) {
      if(!visited[i]) {
        visited[i] = true;
        frontier.push(i);
      }
    }
  }
}

int main()
{
  std::cin >> N >> e;

  for(int i = 0; i < e; ++i) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  BFS(1);

  int cnt = 0;
  for(int i = 1; i <= N; ++i)
    if(visited[i] == true)
      ++cnt;
  std::cout << cnt - 1 << std::endl;

  return 0;
}