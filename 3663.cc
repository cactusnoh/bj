#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline int min(int a, int b) {
    return a < b ? a : b;
}
inline int max(int a, int b) {
    return a < b ? b : a;
}

int T;
std::string name;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> T;

  for (int i = 0; i < T; ++i) {
    std::cin >> name;

    int lr_cnt = name.size() - 1;
    int ud_cnt = 0;

    for (size_t i = 0; i < name.size(); ++i) {
      ud_cnt += min(name[i] - 'A', 1 + 'Z' - name[i]);
      if (i > 0 && name[i] == 'A') {
        size_t beg = i - 1, end = i + 1;
        while (end < name.size() && name[end] == 'A') {
          ++end;
        }
        lr_cnt = min(lr_cnt, 2 * beg + name.size() - end);
        lr_cnt = min(lr_cnt, (name.size() - end) * 2 + beg);
      }
    }

    std::cout << lr_cnt + ud_cnt << "\n";
  }

  return 0;
}