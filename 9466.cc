#include <iostream>
#include <cstring>

int T, N;
int next[100001];
bool visited[100001], done[100001];
int cnt;

void DFS(int n)
{
  visited[n] = true;
  if(!visited[next[n]])
    DFS(next[n]);
  else if(!done[next[n]]) {
    for(int i = next[n]; i != n; i = next[i])
      ++cnt;
    ++cnt;
  }
  done[n] = true;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> T;

  for(int tc = 0; tc < T; ++tc) {
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    memset(done, 0, sizeof(done));

    std::cin >> N;
    for(int i = 1; i <= N; ++i)
      std::cin >> next[i]; 

    for(int i = 1; i <= N; ++i)
      if(!visited[i])
        DFS(i);

    std::cout << N - cnt << "\n";
  }

  return 0;
}