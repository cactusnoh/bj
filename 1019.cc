#include <iostream>

int N, cnt[10];

void count_numbers(int n)
{
  while(n != 0) {
    cnt[n % 10]++;
    n /= 10;
  }
}

int main()
{
  std::cin >> N;

  int start = 1, end = N;

  while(true) {
    while(start <= end && start % 10 != 0) {
      count_numbers(start++);
    }

    if(start > end) {
      break;
    }

    
  }

  return 0;
}