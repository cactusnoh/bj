#include <iostream>

inline int abs(int a)
{
  return a < 0 ? -a : a;
}

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int N, M;
int min_click;
bool invalid_btn[10];

bool possible_no(int number)
{
  if(number == 0)
    return !invalid_btn[0];

  while(number) {
    if(invalid_btn[number % 10])
      return false;
    number /= 10;
  }
  return true;
}

int main()
{
  std::cin >> N >> M;

  for(int i = 0; i < M; ++i) {
    int btn;
    std::cin >> btn;
    invalid_btn[btn] = true;
  }

  min_click = abs(100 - N);

  for(int i = 0; i <= 1000000; ++i) {
    int btn_click = 0, temp = i;
    if(i == 0) btn_click = 1;
    while(temp) {
      btn_click++;
      temp /= 10;
    }

    if(possible_no(i))
      min_click = min(min_click, abs(i - N) + btn_click);
  }

  std::cout << min_click << std::endl;

  return 0;
}