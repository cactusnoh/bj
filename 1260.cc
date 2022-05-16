#include <iostream>
#include <vector>

int N, M, V;
int adj[1001][1001];
bool visited[1001];

void DFS(int v)
{
  visited[v] = true;
  std::cout << v << " ";
  for(int j = 1; j <= N; ++j)
    if(adj[v][j] == 1 && visited[j] == false)
      DFS(j);
}

void BFS(int v) 
{
  std::cout << v << " ";
  visited[v] = true;
  std::vector<int> frontier = {v};
  while(!frontier.empty()) {
    std::vector<int> next;
    for(int i : frontier) {
      for(int j = 1; j <= N; ++j)
        if(adj[i][j] == 1 && visited[j] == false) {
          std::cout << j << " ";
          visited[j] = true;
          next.push_back(j);
        }
    }
    frontier = next;
  }
}

int main()
{
  std::cin >> N >> M >> V;
  for(int i = 0; i < M; ++i) {
    int temp1, temp2;
    std::cin >> temp1 >> temp2;
    adj[temp1][temp2] = 1;
    adj[temp2][temp1] = 1;
  }

  DFS(V);
  std::cout << "\n";
  for(int i = 0; i < 1001; ++i)
    visited[i] = false;
  BFS(V);
  std::cout << std::endl;
  // for(int i = 0; i < N + 1; ++i) {
  //   for(int j = 0; j < N + 1; ++j)
  //     std::cout << adj[i][j] << " ";
  //   std::cout << "\n";
  // }
  
  return 0;
}