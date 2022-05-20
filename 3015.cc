#include <iostream>
#include <stack>

typedef std::pair<int, int> pii;

int N;
int height[500'001];
std::stack<pii> s;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  for(int i = 0; i < N; ++i) {
    std::cin >> height[i];
  }

  long long cnt = 0;

  for(int i = 0; i < N; ++i) {
    int same_cnt = 1;
    while(!s.empty() && s.top().first <= height[i]) {
      cnt += s.top().second;
      if(s.top().first == height[i]) {
        same_cnt += s.top().second;
      }
      s.pop();
    }

    if(!s.empty()) {
      cnt++;
    }

    s.push(pii(height[i], same_cnt));
  }

  std::cout << cnt << std::endl;

  return 0;
}