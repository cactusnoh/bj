#include <iostream>

int N, cnt[10];

void count_numbers(int n, int m)
{
  while(n != 0) {
    cnt[n % 10] += m;
    n /= 10;
  }
}

int main()
{
  std::cin >> N;

  int start = 1, end = N, multiplier = 1;

  while(true) {
    while(start <= end && start % 10 != 0) {
      count_numbers(start++, multiplier);
    }

    if(start > end) {
      break;
    }

    while(start <= end && end % 10 != 9) {
      count_numbers(end--, multiplier);
    }

    if(start > end) {
      break;
    }

    for(int i = 0; i <= 9; ++i) {
      cnt[i] += (end / 10 - start / 10 + 1) * multiplier;
    }

    end /= 10;
    start /= 10;
    multiplier *= 10;
  }

  for(int i = 0; i <= 9; ++i) {
    std::cout << cnt[i] << " ";
  }

  return 0;
}