#include <iostream>

int first, second;

int main()
{
  std::cin >> first >> second;

  while(first != 0 && second != 0) {
    if(second % first == 0)
      std::cout << "factor" << std::endl;
    else if(first % second == 0)
      std::cout << "multiple" << std::endl;
    else
      std::cout << "neither" << std::endl;

    std::cin >> first >> second;
  }

  return 0;
}