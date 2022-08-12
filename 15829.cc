#include <iostream>

#define M 1234567891

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int L;
  std::cin >> L;
  
  char c;
  long long multiplier = 1;
  long long hash_val = 0;

  for (int i = 0; i < L; ++i) {
    std::cin >> c;
    hash_val = (hash_val + (c - 'a' + 1) * multiplier) % M;
    multiplier = ((multiplier << 5) - multiplier) % M;
  }

  std::cout << hash_val << std::endl;

  return 0;
}