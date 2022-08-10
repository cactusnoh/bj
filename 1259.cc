#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::string in;
  while (true) {
    std::cin >> in;
    
    if (in[0] == '0') {
      break;
    }

    bool fail = false;
    int n = in.size();
    for (int i = 0; i < n / 2; ++i) {
      if (in[i] != in[n - 1 - i]) {
        fail = true;
        break;
      }
    }
    if (fail) {
      std::cout << "no" << "\n";
    } else {
      std::cout << "yes" << "\n";
    }
  }

  return 0;
}