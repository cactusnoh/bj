#include <iostream>
#include <algorithm>
#include <queue>

#define INF 2147000000

typedef std::pair<int, int> pii;

struct myCompare {
  bool operator()(const pii &lhs, const pii &rhs)
  {
    return lhs.second < rhs.second;
  }
};

int N, D;
pii people[100'000];

std::priority_queue<int, std::vector<int>, std::greater<int>> SQ;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> N;

  int a, b;
  for(int i = 0; i < N; ++i) {
    std::cin >> a >> b;
    if(a > b) {
      int temp = a;
      a = b;
      b = temp;
    } 
    people[i] = pii(a, b);
  }
  std::sort(people, people + N, myCompare());

  std::cin >> D;

  int ans = 0;
  for(int i = 0; i < N; ++i) {
    auto curr = people[i];

    if(curr.second - curr.first > D)
      continue;
    
    SQ.push(curr.first);

    while(!SQ.empty()) {
      if(curr.second - SQ.top() > D)
        SQ.pop();
      else
        break;
    }

    ans = ans < SQ.size() ? SQ.size() : ans;
  }

  std::cout << ans << std::endl;

  return 0;
}