#include <iostream>
#include <queue>

#define MAX 100000

typedef std::pair<int, int> pii;

int N, K;
std::queue<pii> Q;
bool visited[MAX + 1];
int cnt;

int main()
{
  std::cin >> N >> K;

  Q.push(pii(N, 0));

  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    int u = curr.first, t = curr.second;

    visited[u] = true;

    if(u == K) {
      ++cnt;
      while(!Q.empty() && Q.front().second == t) {
        if(Q.front().first == K)
          ++cnt;
        Q.pop();
      }
      std::cout << t << "\n" << cnt << std::endl;
      return 0;
    }

    if(u + 1 <= MAX && !visited[u + 1]) {
      Q.push(pii(u + 1, t + 1));
    }
    if(u - 1 >= 0 && !visited[u - 1]) {
      Q.push(pii(u - 1, t + 1));
    }
    if(u * 2 <= MAX && !visited[u * 2]) {
      Q.push(pii(u * 2, t + 1));
    }
  }

  return 0;
}