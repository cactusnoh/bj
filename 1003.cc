#include <cstdio>
#include <utility>

int T, zero[41], one[41];

std::pair<int, int> fibonacci(int n) {
  if (n == 0) {
    return {1, 0};
  } else if (n == 1) {
    return {0, 1};
  } else {
    if(zero[n] != -1 && one[n] != -1)
      return {zero[n], one[n]};
    std::pair<int, int> ret = {fibonacci(n - 1).first + fibonacci(n - 2).first, 
                               fibonacci(n - 1).second + fibonacci(n - 2).second};
    zero[n] = ret.first; one[n] = ret.second;
    return ret;
  }
}

int main()
{
  for(int i = 0; i < 41; ++i) {
    zero[i] = -1; one[i] = -1;
  }

  scanf("%d", &T);
  for(int t = 0; t < T; ++t) {
    int n;
    scanf("%d", &n);
    auto p = fibonacci(n);
    printf("%d %d\n", p.first, p.second);
  }

  return 0;
}