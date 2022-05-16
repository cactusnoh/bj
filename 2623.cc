#include <iostream>
#include <vector>

int N, M;
bool start_time[10001], finish_time[10001], fail;
std::vector<int> adj_list[10001], finished;

void DFS(int n)
{
  start_time[n] = true;
  for(int next : adj_list[n]) {
    if(start_time[next] == false)
      DFS(next);
    else if(start_time[next] == true && finish_time[next] == false) {
      fail = true;
      return;
    }
    if(fail)
      return;
  }
  finished.push_back(n);
  finish_time[n] = true;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    int no_singer, prev, curr;
    std::cin >> no_singer >> prev;
    for(int i = 1; i < no_singer; ++i) {
      std::cin >> curr;
      adj_list[prev].push_back(curr);
      prev = curr;
    }
  }

  for(int i = 1; i <= N; ++i)
    if(start_time[i] == 0)
      DFS(i);
  
  if(fail) {
    std::cout << 0 << "\n";
    return 0;
  }

  for(int i = finished.size() - 1; i >= 0; --i)
    std::cout << finished[i] << "\n";

  return 0;
}