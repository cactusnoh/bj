#include <iostream>
#include <deque>

int N, K;
int level[200001];

void BFS(int s)
{
  std::deque<int> frontier = {s};
  level[s] = 0;

  while(!frontier.empty()) {
    int v = frontier.front();
    if(v == K) {
      std::cout << level[v] << std::endl;
      return;
    } 
    frontier.pop_front();
    if(v - 1 >= 0 && level[v - 1] == -1) {
      level[v - 1] = level[v] + 1;
      frontier.push_back(v - 1);
    }
    if(v + 1 <= 200000 && level[v + 1] == -1) {
      level[v + 1] = level[v] + 1;
      frontier.push_back(v + 1);
    }
    if(2 * v <= 200000 && level[2 * v] == -1) {
      level[2 * v] = level[v] + 1;
      frontier.push_back(2 * v);
    }
  }

}

int main()
{
  for(int i = 0; i < 200001; ++i)
    level[i] = -1;
  
  std::cin >> N >> K;

  BFS(N);

}