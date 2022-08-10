#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  bool ascending = true;
  bool descending = true;
  
  int curr, prev;
  std::cin >> prev;
  for (int i = 0; i < 7; ++i) {
    std::cin >> curr;
    if (curr > prev) {
      descending = false;
    } else if (curr < prev) {
      ascending = false;
    } else {
      descending = ascending = false;
      break;
    }
    prev = curr;
  }

  if (ascending) {
    std::cout << "ascending" << std::endl;
  } else if (descending) {
    std::cout << "descending" << std::endl;
  } else {
    std::cout << "mixed" << std::endl;
  }

  return 0;
}