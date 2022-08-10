#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int sum = 0;
  int i = 0;
  while (std::cin >> i) {
    sum = (sum + i * i) % 10;
  }

  std::cout << sum << std::endl;

  return 0;
}