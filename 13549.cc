#include <iostream>
#include <queue>

#define MAX 100000

typedef std::pair<int, int> pii;

int N, K;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
bool visited[MAX + 1];

int main()
{
  std::cin >> N >> K;

  Q.push(pii(0, N));
  while(1) {
    auto curr = Q.top(); Q.pop();

    if(curr.second == K) {
      std::cout << curr.first << std::endl;
      return 0;
    }

    if(curr.second * 2 <= MAX && !visited[curr.second * 2]) {
      Q.push(pii(curr.first, curr.second * 2));
      visited[curr.second * 2] = true;
    }

    if(curr.second + 1 <= MAX && !visited[curr.second + 1]) {
      Q.push(pii(curr.first + 1, curr.second + 1));
      visited[curr.second + 1] = true;
    }

    if(curr.second - 1 >= 0 && !visited[curr.second - 1]) {
      Q.push(pii(curr.first + 1, curr.second - 1));
      visited[curr.second - 1] = true;
    }

  }

  return 0;
}