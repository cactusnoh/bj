#include <iostream>
#include <unordered_map>
#include <string>

int T, n;
std::unordered_map<std::string, int> kinds;

int main()
{
  std::cin >> T;
  
  for(int t = 0; t < T; ++t) {
    kinds.clear();
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
      std::string kind;
      std::cin >> kind >> kind;
      ++kinds[kind];
    }
    int ans = 1;
    for(const auto &p : kinds)
      ans *= (p.second + 1);
    std::cout << ans - 1 << std::endl;
  }

  return 0;
}