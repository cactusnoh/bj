#include <iostream>

int N;
int memo2[501], memo5[501];

int main()
{
  std::cin >> N;

  for(int i = 1; i <= N; ++i) {
    int two = 0, five = 0, temp = i;
    while(temp % 2 == 0) {
      temp /= 2;
      ++two;
    }
    temp = i;
    while(temp % 5 == 0) {
      temp /= 5;
      ++five;
    }
    memo2[i] = memo2[i - 1] + two;
    memo5[i] = memo5[i - 1] + five;
  }

  std::cout << (memo2[N] > memo5[N] ? memo5[N] : memo2[N]) << std::endl;

  return 0;
}