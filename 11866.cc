#include <iostream>

#define SIZE 1001

int N, K;
int queue[SIZE], front, rear, size;
bool visited[SIZE];

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> N >> K;
  for(int i = 0; i < N; ++i)
    queue[i] = i + 1;
  rear = size = N;

  int next = -1;
  std::cout << "<";
  for(int i = 0; i < N; ++i) {
    int cnt = 0;
    while(cnt < K) {
      next = (next + 1) % N;
      if(visited[next]) continue;
      ++cnt;
    }
    visited[next] = true;
    std::cout << queue[next] << (i != N - 1 ? ", " : "");
  }
  std::cout << ">";

  return 0;
}