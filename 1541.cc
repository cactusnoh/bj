#include <iostream>

int main()
{
  int ans = 0, temp;
  char operand;
  bool subtract = false;
  while(std::cin >> temp) {
    if(subtract)
      ans -= temp;
    else
      ans += temp;
    std::cin >> operand;
    if(operand == '-')
      subtract = true;
  }

  std::cout << ans << std::endl;

  return 0;
}